#ifndef NODE_HPP_
#define NODE_HPP_

namespace ft {
	template <class T, class Allocator = std::allocator<T> >
	class node {
		public:
			typedef T value_type;
			typedef typename value_type::first_type key_type;
			typedef node<T> node_type;

			node(): pta_(NULL), lhs_(NULL), rhs_(NULL), val_(), key_(), height_(0) {}
			node(const value_type &val, node* pta, node *null): pta_(pta), lhs_(null), rhs_(null), val_(val), key_(val.first), height_(1) {}
			~node() {}

			node_type *pta_;
			node_type *lhs_;
			node_type *rhs_;
			value_type val_;
			key_type key_;
			int height_;

	};
}

#endif
