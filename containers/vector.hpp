#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <memory>
#include <type_traits.hpp>
#include <random_access_iterator.hpp>
#include <reverse_iterator.hpp>
#include <algorithm.hpp>

namespace ft
{
	template <typename T, typename Allocator = std::allocator<T> >
	class vector
	{
	public:
		typedef T value_type;																							// The first template parameter (T)
		typedef Allocator allocator_type;																	// The second template parameter (Alloc)
		typedef typename allocator_type::reference reference;							// for the default allocator: value_type&
		typedef typename allocator_type::const_reference const_reference; // for the default allocator: const value_type&
		typedef typename allocator_type::pointer pointer;									// for the default allocator: value_type*
		typedef typename allocator_type::const_pointer const_pointer;			// for the default allocator: const value_type*
		typedef ft::random_access_iterator<value_type> iterator;
		typedef ft::random_access_iterator<const value_type> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef std::ptrdiff_t difference_type;
		typedef std::size_t size_type;

		/*----------------------------------------
		[Constructors & Destructor]
		----------------------------------------*/
		/**
		 * @brief empty container constructor (default constructor)
		 * Constructs an empty container, with no elements.
		 */
		explicit vector(const allocator_type &alloc = allocator_type()) : alloc_(alloc), begin_(NULL), end_(NULL), reserved_end_(NULL) {}

		/**
		 * @brief fill constructor
		 * Constructs a container with n elements. Each element is a copy of val.
		 */
		explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
				: alloc_(alloc), begin_(NULL), end_(NULL), reserved_end_(NULL) {
			begin_ = alloc_.allocate(n);
			end_ = begin_;
			reserved_end_ = begin_ + n;
			for (size_t i = 0; i < n; i++) {
				alloc_.construct(end_, val);
				end_++;
			}
		}

		/**
		 * @brief range constructor
		 * Constructs a container with as many elements as the range [first,last],
		 * with each element constructed from its corresponding element in that range, in the same  order.
		 */
		template <class InputIterator>
		vector(
				InputIterator begin,
				typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type end,
				const allocator_type &alloc = allocator_type())
				: alloc_(alloc), begin_(NULL), end_(NULL), reserved_end_(NULL)
		{
			insert(this->begin(), begin, end);
		}

		/** @brief copy constructor */
		vector(const vector &x) : alloc_(x.alloc_), begin_(NULL), end_(NULL), reserved_end_(NULL) { *this = x; }

		/** @brief Destroy the vector object */
		~vector()
		{
			this->clear();
			alloc_.deallocate(begin_, this->capacity());
		}

		/** @brief Copies all the elements from x into the container */
		vector &operator=(const vector &rhs) {
			if (rhs == *this)
					return (*this);
			this->clear();
			this->insert(this->begin(), rhs.begin(), rhs.end());
			return *this;
		}

		/*----------------------------------------
		[Iterators]
		----------------------------------------*/
		iterator begin() { return iterator(begin_); }
		const_iterator begin() const { return const_iterator(begin_); }
		iterator end() { return iterator(end_); }
		const_iterator end() const { return const_iterator(end_); }
		reverse_iterator rbegin() { return reverse_iterator(this->end()); }
		const_reverse_iterator rbegin() const { return const_reverse_iterator(this->end()); }
		reverse_iterator rend() { return reverse_iterator(this->begin()); }
		const_reverse_iterator rend() const { return const_reverse_iterator(this->begin()); }

		/*----------------------------------------
		[Element access]
		----------------------------------------*/
		/** @brief Returns a reference to the element at position n in the vector container. */
		reference operator[](size_type n) { return *(begin_ + n); }
		const_reference operator[](size_type n) const { return *(begin_ + n); }

		/** @brief Returns a reference to the element at position n in the vector.
		 * The function automatically checks whether n is within the bounds of valid elements in the vector, throwing an out_of_range exception
		 */
		reference at(size_type n)
		{
			if (n >= this->size())
				throw std::out_of_range("Error: Bad access");
			return begin_[n];
		}

		const_reference at(size_type n) const
		{
			if (n >= this->size())
				throw std::out_of_range("Error: Bad access");
			return begin_[n];
		}

		/** @brief Returns a reference to the first element in the container */
		reference front() { return this->at(0); }
		const_reference front() const { return this->at(0); }

		/** @brief Returns a reference to the last element in the vector */
		reference back() { return this->at(this->size() - 1); }
		const_reference back() const { return this->at(this->size() - 1); }

		/** @brief Returns a direct pointer to the memory array used internally by the vector to store its owned elements */
		T *data() {
			if (this->size() == 0)
				return NULL;
			return begin_;
		}

		const T *data() const {
			if (this->size() == 0)
				return NULL;
			return begin_;
		}

		/*----------------------------------------
		[Capacity]
		----------------------------------------*/
		/** @brief Returns the number of elements in the vector */
		size_type size() const { return (end_ - begin_); }

		/** @brief Returns the maximum number of elements that the vector can hold */
		size_type max_size() const { return this->alloc_.max_size(); }

		/**
		 * @brief Resizes the container so that it contains n elements.
		 *
		 * @param n New container size, expressed in number of elements
		 * @param val Object whose content is copied to the added elements in case that n is greater than the current container size
		 */
		void resize(size_type n, value_type val = value_type()) {
			if (this->max_size() < n)
				throw std::length_error("Size required is too long\n");

			size_type size = this->size();
			if (size > n) {
				for (size_type i = n; i < size; i++){
					--end_;
					alloc_.destroy(end_);
				}
			}
			else
				this->insert(iterator(end_), n - size, val);
		}

		/** @brief Returns the size of the storage space currently allocated for the vector, expressed in terms of elements */
		size_type capacity() const { return (reserved_end_ - begin_); }
		/** @brief Returns whether the vector is empty (i.e. whether its size is 0) */
		bool empty() const {
			if (this->size() == 0)
				return true;
			return false;
		}

		/** @brief Requests that the vector capacity be at least enough to contain n elements */
		void reserve(size_type n) {
			if (this->max_size() < n)
				throw std::length_error("Size required is too long\n");
			size_type old_capacity = this->capacity();
			if (old_capacity >= n)
				return;

			pointer old_begin = begin_;
			pointer old_end = end_;
			size_type old_size = this->size();

			begin_ = alloc_.allocate(n);
			end_ = begin_;
			reserved_end_ = begin_ + n;
			for (; old_begin != old_end; old_begin++) {
				alloc_.construct(end_, *old_begin);
				end_++;
			}
			alloc_.deallocate(old_begin - old_size, old_capacity);
		}

		/*----------------------------------------
		[Modifiers]
		----------------------------------------*/
		/** @brief Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly */
		template <class InputIterator>
		void assign(
				InputIterator first,
				typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type last) {
			this->clear();
			size_type length = last - first;
			size_type capacity = this->capacity();
			if (capacity < length) {
				alloc_.deallocate(begin_, capacity);
				begin_ = alloc_.allocate(length);
				end_ = begin_;
				reserved_end_ = begin_ + length;
			}
			for (; first != last; first++){
				alloc_.construct(end_, *first);
				end_++;
			}
		}

		void assign(size_type n, const value_type &val) {
			this->clear();
			size_type capacity = this->capacity();
			if (capacity < n) {
				alloc_.deallocate(begin_, capacity);
				begin_ = alloc_.allocate(n);
				end_ = begin_;
				reserved_end_ = begin_ + n;
			}
			for (size_t i = 0; i < n; i++) {
				alloc_.construct(end_, val);
				end_++;
			}
		}

		/** @brief Appends the given element value to the end of the container */
		void push_back(const value_type &val) {
			size_type size = this->size();
			size_type capacity = this->capacity();
			if (capacity - size < 1) {
				size_type new_capacity = size > 0 ? size * 2 : 1;
				this->reserve(new_capacity);
			}
			alloc_.construct(end_, val);
			end_++;
		}

		/** @brief Removes the last element in the vector */
		void pop_back() {
			if (this->size() == 0)
				return;
			alloc_.destroy(end_ - 1);
			end_ -= 1;
		}

		/** @brief inserts value before pos */
		iterator insert(iterator pos, const value_type &val) {
			size_type size = this->size();
			size_type capacity = this->capacity();
			size_type pos_len = &(*pos) - begin_;
			if (capacity - size >= size + 1) {//!!!!!!!!!!!!!!!!
				iterator it = this->end();
				iterator new_it = pos - 1;
				for (; it != new_it; it--)
					alloc_.construct(&(*it), *it);
				end_ += 1;
				alloc_.construct(&(*new_it), val);
			}
			else {
				size_type new_capacity = size > 0 ? size * 2 : 1;
				iterator old_begin = this->begin();
				iterator old_end = this->end();
				begin_ = alloc_.allocate(new_capacity);
				end_ = begin_;
				reserved_end_ = begin_ + new_capacity;
				for (; old_begin != pos; old_begin++) {
					alloc_.construct(end_, *(old_begin));
					alloc_.destroy(&(*old_begin));
					end_++;
				}
				alloc_.construct(end_, val);
				end_ += 1;
				for (; old_begin != old_end; old_begin++) {
					alloc_.construct(end_, *(old_begin));
					alloc_.destroy(&(*old_begin));
					end_++;
				}
				alloc_.deallocate(&(*(old_begin - size)), capacity);
			}
			return (iterator(begin_ + pos_len));
		}

		/** @brief inserts n copies of the value before pos */
		void insert(iterator pos, size_type n, const value_type &val) {
			if (n == 0)
				return;
			else if (n > this->max_size())
				throw std::length_error("Size required is too long\n");

			size_type size = this->size();
			size_type capacity = this->capacity();
			if (capacity - size >= n) {
				for (size_type i = 0; i < n; i++)
					insert(pos - i, val);
			}
			else {
				size_type new_capacity = capacity > 0 ? size * 2 : n;
				new_capacity = capacity >= n ? size * 2 : size + n;
				iterator old_begin = this->begin();
				iterator old_end = this->end();
				begin_ = alloc_.allocate(new_capacity);
				end_ = begin_;
				reserved_end_ = begin_ + new_capacity;
				for (; old_begin != pos; old_begin++) {
					alloc_.construct(end_, *(old_begin));
					alloc_.destroy(&(*old_begin));
					end_++;
				}
				for (size_t i = 0; i < n; i++) {
					alloc_.construct(end_, val);
					end_++;
				}
				for (; old_begin != old_end; old_begin++) {
					alloc_.construct(end_, *(old_begin));
					alloc_.destroy(&(*old_begin));
					end_++;
				}
				alloc_.deallocate(&(*(old_begin - size)), capacity);
			}
		}

		/** @brief inserts elements from range [first, last) before pos */
		template <class InputIterator>
		void insert(
				iterator pos,
				InputIterator first,
				typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type last)
		{
			size_type length = last - first;
			size_type size = this->size();
			size_type capacity = this->capacity();
			if (capacity - size >= length) {
				for (size_type i = 0; i < length; i++)
					insert(pos - i, *(first + i));
			}
			else {
				size_type new_capacity = capacity > 0 ? size * 2 : length;
				new_capacity = capacity >= length ? size * 2 : size + length;
				iterator old_begin = this->begin();
				iterator old_end = this->end();
				begin_ = alloc_.allocate(new_capacity);
				end_ = begin_;
				reserved_end_ = begin_ + new_capacity;
				for (; old_begin != pos; old_begin++) {
					alloc_.construct(end_, *(old_begin));
					alloc_.destroy(&(*old_begin));
					end_++;
				}
				for (size_t i = 0; i < length; i++) {
					alloc_.construct(end_, *(first + i));
					end_++;
				}
				for (; old_begin != old_end; old_begin++) {
					alloc_.construct(end_, *(old_begin));
					alloc_.destroy(&(*old_begin));
					end_++;
				}
				alloc_.deallocate(&(*(old_begin - size)), capacity);
			}
		}

		/** @brief Erases the specified elements from the container */
		iterator erase(iterator pos) {
			size_type pos_len = end_ - &(*pos) - 1;
			if (pos_len == 0) {
				pop_back();
				return pos;
			}
			iterator pos_next = pos + 1;
			for (size_type i = 0; i < pos_len; i++) {
				alloc_.destroy(&(*(pos + i)));
				alloc_.construct(&(*pos), *pos_next);
				pos_next++;
			}
			end_ -= 1;
			return pos;
		}

		iterator erase(iterator first, iterator last) {
			difference_type len = last - first;
			for (; first != last; first++) {
				alloc_.destroy(&(*(first)));
				if (&(*last) != end_) {
					alloc_.construct(&(*first), *last);
					alloc_.destroy(&(*last));
					last++;
				}
			}
			end_ -= len;
			return first;
		}

		/** @brief Removes all elements from the vector (which are destroyed), leaving the container with a size of 0 */
		void clear() {
			size_type size = this->size();
			for (size_t i = 0; i < size; i++) {
				end_--;
				alloc_.destroy(end_ - i);
			}
		}

		/** @brief Exchanges the content of the container by the content of x, which is another vector
		 * object of the same type. Sizes may differ
		 * */
		void swap(vector &other) {
			pointer tmp_begin = begin_;
			pointer tmp_end = end_;
			pointer tmp_reserved_end = reserved_end_;

			this->begin_ = other.begin_;
			this->end_ = other.end_;
			this->reserved_end_ = other.reserved_end_;

			other.begin_ = tmp_begin;
			other.end_ = tmp_end;
			other.reserved_end_ = tmp_reserved_end;
		}

		/*---------------------------------------
		[Allocator]
		----------------------------------------*/
		allocator_type get_allocator() const { return alloc_; }

	private:
		allocator_type alloc_; // Allocator value
		pointer begin_;				 // Pointer to the first element
		pointer end_;					 // Pointer next to the last element
		pointer reserved_end_; // Next pointer to allocated memory
	};

	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		if (lhs.size() != rhs.size())
			return false;
		typename vector<T>::const_iterator it_lhs = lhs.begin();
		typename vector<T>::const_iterator end_lhs = lhs.end();
		typename vector<T>::const_iterator it_rhs = rhs.begin();

		for (; it_lhs != end_lhs; it_lhs++) {
			if (*it_lhs != *it_rhs)
				return false;
			it_rhs++;
		}
		return true;
	}

	template <class T, class Alloc>
	bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) { return !(lhs == rhs); }

	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) { return !(lhs > rhs); }

	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) { return ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()); }

	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) { return !(lhs < rhs); }

	template <class T, class Alloc>
	void swap(vector<T, Alloc> &lhs, vector<T, Alloc> &rhs) { lhs.swap(rhs); }
}

#endif
