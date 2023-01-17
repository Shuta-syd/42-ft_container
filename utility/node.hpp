#ifndef NODE_HPP_
#define NODE_HPP_

#include <memory>

namespace ft {
	template <class T>
	class node {
		public:
			typedef T value_type

		private:
			value_type val_;
			node* pta_;
			node* lhs_;
			node* rhs_;
	};
}

#endif
