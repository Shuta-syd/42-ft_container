#ifndef NODE_HPP_
#define NODE_HPP_

namespace ft {
	template <class T>
	class node {
		public:
			typedef T value_type;
			typedef typename value_type::first_type key_type;
			typedef node<T> node_type;

			node(): pta_(NULL), lhs_(NULL), rhs_(NULL), val_(), key_(), bias_(0), height_(0) {}
			node(value_type &val, node* pta, node *null): pta_(pta), lhs_(null), rhs_(null), val_(val), key_(val.first), bias_(0), height_(1) {}
			~node() {}

			node_type *pta_;
			node_type *lhs_;
			node_type *rhs_;
			value_type val_;
			key_type key_;
			int bias_;
			int height_;
	};
}

#endif
