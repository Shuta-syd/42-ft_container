#ifndef STACK_HPP_
#define STACK_HPP_

#include <vector.hpp>

namespace ft {
	template<class T, class Container = ft::vector<T>>
	class stack {
		public:
			typedef Container container_type;
			typedef Container::value_type value_type;
			typedef Container::size_type size_type;
			typedef Container::reference reference;
			typedef Container::const_reference const_reference;

		/**
		 * @brief Default Constructor
		 * @param ctnr Container object, if any, otherwise it is an empty container
		 */
		explicit stack (const container_type& ctnr = container_type()): ctnr_(ctnr) {}

		/** @brief Returns whether the stack is empty: i.e. whether its size is zero */
		bool empty() const { return ctnr_.empty(); }

		/** @brief Returns the number of elements in the stack */
		size_type size() const {return ctnr_.size(); }

		/** @brief Returns a reference to the top element in the stack */
		value_type &top() { return ctnr_.back(); }
		const value_type &top() const { return ctnr_.back(); }

		/** @brief Inserts a new element at the top of the stack, above its current top element */
		void push(const value_type &val) { ctnr_.push_back(val); }

		/** @brief Removes the element on top of the stack, effectively reducing its size by one */
		void pop() { return ctnr_.pop_back(); }

	private:
		container_type ctnr_;
	};
}

#endif
