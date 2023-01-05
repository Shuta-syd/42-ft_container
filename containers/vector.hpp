#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <memory>
#include <random_access_iterator.hpp>

namespace ft {
	template <typename T, typename Allocator = std::allocator<T>>
	class vector {
	public:
		typedef T value_type;							// The first template parameter (T)
		typedef Allocator allocator_type; // The second template parameter (Alloc)
		typedef allocator_type::reference reference; // for the default allocator: value_type&
		typedef allocator_type::const_reference const_reference; // for the default allocator: const value_type&
		typedef allocator_type::pointer pointer;		 // for the default allocator: value_type*
		typedef allocator_type::const_pointer const_pointer; // for the default allocator: const value_type*
		typedef ft::random_access_iterator<pointer> iterator;
		typedef ft::random_access_iterator<const_pointer> const_iterator;
		typedef ft::random_access_iterator<iterator> reverse_iterator;
		typedef ft::random_access_iterator<const_iterator> const_reverse_iterator;
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;

		/*----------------------------------------[Constructors & Destructor]----------------------------------------*/
		/**
		 * @brief empty container constructor (default constructor)
		 * Constructs an empty container, with no elements.
		 */
		explicit vector(const allocator_type &alloc = allocator_type()): alloc_(alloc), first_(NULL), last_(NULL), reserved_last_(NULL) {}

		/**
		 * @brief fill constructor
		 * Constructs a container with n elements. Each element is a copy of val.
		 */
		explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
		: alloc_(alloc), first_(NULL), last_(NULL), reserved_last_(NULL) {
			first_ = alloc_.allocate(n);
			end_ = first_;
			reserved_last_ = first_ + n;
			for (size_t i = 0; i < n; i++) {
				alloc_.construct(end_, val);
				end_++;
			}
		}

		/**
		 * @brief range constructor
		 * Constructs a container with as many elements as the range [first,last),
		 * with each element constructed from its corresponding element in that range, in the same order.
		 */
		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type()) : alloc_(alloc), first_(NULL), last_(NULL), reserved_last_(NULL) {

		}

		/**
		 * @brief copy constructor
		 * Constructs a container with a copy of each of the elements in x, in the same order.
		 */
		vector(const vector &x){

		}

		/**
		 * @brief Destroy the vector object
		 */
		~vector() {}

		/**
		 * @brief Copies all the elements from x into the container.
		 */
		vector &operator=(const vector &x) {
			if (x == *this)
				return *this;
			// this->clear();
			// this->insert();
			return *this;
		}
		/*-----------------------------------------------------------------------------------------------------------*/


		/*-------------------------------------------------[Iterators]-----------------------------------------------*/


		/*-----------------------------------------------------------------------------------------------------------*/


		/*----------------------------------------------[Element access]---------------------------------------------*/

		/*-----------------------------------------------------------------------------------------------------------*/


		/*-------------------------------------------------[Capacity]------------------------------------------------*/

		/*-----------------------------------------------------------------------------------------------------------*/


		/*------------------------------------------------[Modifiers]------------------------------------------------*/
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

		/*-----------------------------------------------------------------------------------------------------------*/

		/*------------------------------------------------[Allocator]------------------------------------------------*/

		/*-----------------------------------------------------------------------------------------------------------*/
	private:
		allocator_type alloc_;	// Allocator value
		pointer first_;					// Pointer to the first element
		pointer last_;					// Pointer to the last element
		pointer reserved_last_; // End of allocated storage
	};
}

#endif
