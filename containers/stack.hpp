#ifndef STACK_HPP_
#define STACK_HPP_

#include <vector.hpp>

namespace ft {
	template<class T, class Container = ft::vector<T> >
	class stack {
		public:
			typedef Container container_type;
			typedef typename Container::value_type value_type;
			typedef typename Container::size_type size_type;
			typedef typename Container::reference reference;
			typedef typename Container::const_reference const_reference;

		/**
		 * @brief Default Constructor
		 * @param ctnr Container object, if any, otherwise it is an empty container
		 */
		explicit stack (const container_type& ctnr = container_type()): c(ctnr) {}

		/** @brief copy constructor */
		stack( const stack& other ) { *this = other; }

		stack& operator=( const stack& other ) {
			this->c = other.c;
			return *this;
		}

		/** @brief Returns whether the stack is empty: i.e. whether its size is zero */
		bool empty() const { return c.empty(); }

		/** @brief Returns the number of elements in the stack */
		size_type size() const {return c.size(); }

		/** @brief Returns a reference to the top element in the stack */
		value_type &top() { return c.back(); }
		const value_type &top() const { return c.back(); }

		/** @brief Inserts a new element at the top of the stack, above its current top element */
		void push(const value_type &val) { c.push_back(val); }

		/** @brief Removes the element on top of the stack, effectively reducing its size by one */
		void pop() { return c.pop_back(); }

	protected:
		container_type c;
	};

	template <class T, class Container>
	bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { lhs.c == rhs.c; }

	template <class T, class Container>
	bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { !(lhs.c == rhs.c); }

	template <class T, class Container>
	bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { lhs.c < rhs.c; }

	template <class T, class Container>
	bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { lhs.c <= rhs.c; }

	template <class T, class Container>
	bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { lhs.c > rhs.c; }

	template <class T, class Container>
	bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { lhs.c >= rhs.c; }
}

#endif
