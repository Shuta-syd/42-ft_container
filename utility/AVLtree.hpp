#ifndef AVLTREE_HPP_
#define AVLTREE_HPP_

#include <memory>
#include <node.hpp>
// #include <pair.hpp>

namespace ft {
	template <class T, class Comp, class Allocator= std::allocator<T> >
	class AVLtree {
		public:
			typedef T value_type;
			typedef typename value_type::first_type key_type;
			typedef Allocator allocator_type;
			typedef node<T> node_type;

			AVLtree(): root_(NULL), key_compare(Comp()) {}
			~AVLtree() {}

			void insert(value_type &val) {
				if (root_ == NULL) {
					root_ = new node_type(val, NULL);
					return;
				}

				node_type *pta = this->searchParent(val.first);
				if (key_compare(pta->key_, val.first)) {
					pta->rhs_ = new node_type(val, pta);
					// balance_insert(pta->rhs_)
				}
				else {
					pta->lhs_ = new node_type(val, pta);
					//balance_insert(pta->lhs_)
				}
			}

		private:
			node_type *root_;
			Comp key_compare;

			/** @brief Search for appropriate parent node of val to insert by traversing from root */
			node_type *searchParent(const key_type &key) {
				node_type *pta = root_;
				node_type *candidate = root_;
				bool high_or_low;

				while (candidate) {
					pta = candidate;
					high_or_low = key_compare(pta->key_, key);
					if ((high_or_low && pta->rhs_ == NULL) && (!high_or_low && pta->lhs_ == NULL))
						return pta;
					candidate = high_or_low ? pta->rhs_ : pta->lhs_;
					if (candidate == NULL)
						return pta;
				}
				return pta;
			}

			/** @brief single left rotate */
			void rotateL() {}
			/** @brief single right rotate */
			void rotateR() {}
			/** @brief single RR rotate + LL rotate */
			void rotateRL() {}
			/** @brief single LL rotate + RR rotate rotate */
			void rotateLR() {}
	};
}

#endif
