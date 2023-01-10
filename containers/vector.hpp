#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <memory>
#include <random_access_iterator.hpp>
#include <reverse_iterator.hpp>

namespace ft {
	template <typename T, typename Allocator = std::allocator<T> >
	class vector {
	public:
		typedef T value_type;							// The first template parameter (T)
		typedef Allocator allocator_type; // The second template parameter (Alloc)
		typedef typename allocator_type::reference reference; // for the default allocator: value_type&
		typedef typename allocator_type::const_reference const_reference; // for the default allocator: const value_type&
		typedef typename allocator_type::pointer pointer;		 // for the default allocator: value_type*
		typedef typename allocator_type::const_pointer const_pointer; // for the default allocator: const value_type*
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
		explicit vector(const allocator_type &alloc = allocator_type()): alloc_(alloc), begin_(NULL), end_(NULL), reserved_end_(NULL) {}

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
		 * with each element constructed from its corresponding element in that range, in the same order.
		 *
		 * vector(2, 10);
		 */

		// template <class InputIterator>
		// vector(InputIterator begin, InputIterator end, const allocator_type &alloc = allocator_type())
		//  : alloc_(alloc), begin_(NULL), end_(NULL), reserved_end_(NULL) {
		// 	std::cout << "Range" << std::endl;
		// }

		/** @brief copy constructor */
		vector(const vector &x){
			*this = x;
		}

		/** @brief Destroy the vector object */
		~vector() {}

		/** @brief Copies all the elements from x into the container */
		vector &operator=(const vector &x) {
			if (x == *this)
				return *this;
			// this->clear();
			// this->insert();
			return *this;
		}
		/*----------------------------------------*/


		/*----------------------------------------
		[Iterators]
		----------------------------------------*/
		iterator begin() { return iterator(begin_); }
		const_iterator begin() const  { return const_iterator(begin_); }
		iterator end() { return iterator(end_);  }
		const_iterator end() const  { return const_iterator(end_); }
		reverse_iterator rbegin() { return reverse_iterator(this->end()); }
		const_reverse_iterator rbegin() const { return const_reverse_iterator(this->end());}
		reverse_iterator rend() { return reverse_iterator(this->begin()); }
		const_reverse_iterator rend() const { return const_reverse_iterator(this->begin());}
		/*--------------------------------------*/


		/*----------------------------------------
		[Element access]
		----------------------------------------*/
		/** @brief Returns a reference to the element at position n in the vector container. */
		reference operator[] (size_type n) { return *(begin_ + n);}
		const_reference operator[] (size_type n) const { return *(begin_ + n); }

		/** @brief Returns a reference to the element at position n in the vector.
		 * The function automatically checks whether n is within the bounds of valid elements in the vector, throwing an out_of_range exception
		 */
		reference at(size_type n) {
			if (n >= this->size())
				throw std::out_of_range("Error: Bad access");
			return begin_[n];
		}

		const_reference at(size_type n) const {
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
	T* data() {
		if (this->size() == 0)
			return NULL;
		return begin_;
	}

	const T* data() const {
		if (this->size() == 0)
			return NULL;
		return begin_;
	}
	/*--------------------------------------*/


		/*----------------------------------------
		[Capacity]
		----------------------------------------*/
		/** @brief Returns the number of elements in the vector */
		size_type size() const { return (end_ - begin_); }
		/*--------------------------------------*/


		/*----------------------------------------
		[Modifiers]
		----------------------------------------*/
		/**
		 * @brief
		 *
		 * @param position
		 * @param val
		 * @return iterator
		 */
		iterator insert(iterator position, const value_type &val) {

		}

		/**
		 * @brief The vector is extended by inserting new elements before the element at the specified position,
		 * 				effectively increasing the container size by the number of elements inserted.
		 *
		 * @param position Position in the vector where the new elements are inserted.
		 * @param n Number of elements to insert. Each element is initialized to a copy of val.
		 * @param val Value to be copied (or moved) to the inserted elements.
		 */
		void insert(iterator position, size_type n, const value_type &val) {

		}

		/**
		 * @brief Insert elements from first to last at "position" into this container
		 *
		 * @param position Position in the vector where the new elements are inserted.
		 * @param first,last Iterators specifying a range of elements. Copies of the elements in the range [first,last) are inserted at position
		 */
		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last) {

		}

		/**
		 * @brief Removes all elements from the vector (which are destroyed), leaving the container with a size of 0.
		 */
		void clear() {

		}

		/*--------------------------------------*/

		/*---------------------------------------
		[Allocator]
		----------------------------------------*/

		/*--------------------------------------*/
	private:
		allocator_type alloc_;	// Allocator value
		pointer begin_;					// Pointer to the first element
		pointer end_;					// Pointer to the last element
		pointer reserved_end_; // End of allocated storage
	};
}

#endif
