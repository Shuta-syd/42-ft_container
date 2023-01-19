#ifndef AVLTREE_HPP_
#define AVLTREE_HPP_

#include <memory>
#include <node.hpp>
// #include <pair.hpp>

namespace ft
{
	template <class T, class Comp, class Allocator = std::allocator<T> >
	class AVLtree
	{
	public:
		typedef T value_type;
		typedef typename value_type::first_type key_type;
		typedef Allocator allocator_type;
		typedef node<T> node_type;

		AVLtree() : root_(), nullNode_(new node_type()), key_compare(Comp()) { root_ = nullNode_; }
		~AVLtree() {}

		void insert(value_type &val) {
			if (root_ == nullNode_) {
				root_ = new node_type(val, nullNode_, nullNode_);
				return;
			}

			node_type *pta = this->searchParent(val.first);
			if (key_compare(pta->key_, val.first)) {
				pta->rhs_ = new node_type(val, pta, nullNode_);
				balanceInsert(pta->rhs_);
			}
			else {
				pta->lhs_ = new node_type(val, pta, nullNode_);
				balanceInsert(pta->lhs_);
			}
		}

		void printAVL(node_type *node, int i) {
			if (node == NULL) {
				node = root_;
				std::cout << "null:[" << nullNode_ << "]" << std::endl;
			}
			std::cout << MGN << i << ":" << "[" << node->key_ << "]" << RES << std::endl;
			std::cout << "node:[" << node << "]" << std::endl;
			std::cout << "lhs :[" << node->lhs_ << "]" << std::endl;
			std::cout << "rhs :[" << node->rhs_ << "]" << std::endl;
			if (node->lhs_ != nullNode_)
				printAVL(node->lhs_, i + 1);
			if (node->rhs_ != nullNode_)
				printAVL(node->rhs_, i + 1);
		}

	private:
		node_type *root_;
		node_type *nullNode_;
		Comp key_compare;

		/** @brief Search for appropriate parent node of val to insert by traversing from root */
		node_type *searchParent(const key_type &key) {
			node_type *pta = root_;
			node_type *candidate = root_;
			bool high_or_low;

			while (candidate) {
				pta = candidate;
				high_or_low = key_compare(pta->key_, key);
				if ((high_or_low && pta->rhs_ == nullNode_) && (!high_or_low && pta->lhs_ == nullNode_))
					return pta;
				candidate = high_or_low ? pta->rhs_ : pta->lhs_;
				if (candidate == nullNode_)
					return pta;
			}
			return pta;
		}

		/** @brief Check if it is established as an equilibrium binary tree and rotate if it is not balanced */
		void balanceInsert(node_type *targetNode) {
			while (targetNode->pta_ != nullNode_) {
				node_type *pta = targetNode->pta_;
				int height = pta->height_;

				// targetNode inserted to left side
				if (pta->lhs_ == targetNode) {
					if (this->bias(pta) == 2) // need to rotate
						pta = this->bias(pta->lhs_) == 1 ? this->rotateR(pta) : this->rotateLR(pta);
					else // -1 <= bias <= 1, no problem, update parent height
						this->updateHeight(pta);
				}
				else { // targetNode inserted to right side
					if (this->bias(pta) == -2) // need to rotate
						pta = this->bias(pta->lhs_) == -1 ? this->rotateL(pta) : this->rotateRL(pta);
					else // -1 <= bias <= 1, no problem, update parent height
						this->updateHeight(pta);
				}
				if (height == pta->height_) // nothing update == end point
					break;
				targetNode = pta;
			}
		}

		/** @brief single left rotate */
		node_type *rotateL(node_type *beforeRoot) {
			node_type *rhs = beforeRoot->rhs_;
			node_type *afterRoot = rhs;
			node_type *pivot = rhs->lhs_;

			beforeRoot->rhs_ = pivot;
			if (pivot != nullNode_)
				pivot->pta_ = afterRoot;
			afterRoot->lhs_ = beforeRoot;
			beforeRoot->pta_ = afterRoot;

			if (beforeRoot == root_)
				root_ = afterRoot;

			updateHeight(beforeRoot);
			updateHeight(afterRoot);

			return afterRoot;
		}

		/** @brief single right rotate */
		node_type *rotateR(node_type *beforeRoot) {
			node_type *lhs = beforeRoot->lhs_;
			node_type *afterRoot = lhs;
			node_type *pivot = lhs->rhs_;

			beforeRoot->lhs_ = pivot;
			if (pivot != nullNode_)
				pivot->pta_ = afterRoot;
			afterRoot->rhs_ = beforeRoot;
			beforeRoot->pta_ = afterRoot;

			if (beforeRoot == root_)
				root_ = afterRoot;

			updateHeight(beforeRoot);
			updateHeight(afterRoot);

			return afterRoot;
		}

		/** @brief single RR rotate + LL rotate */
		node_type *rotateRL(node_type *beforeRoot) {
			rotateR(beforeRoot->rhs_);
			return rotateL(beforeRoot);
		}

		/** @brief single LL rotate + RR rotate rotate */
		node_type *rotateLR(node_type *beforeRoot) {
			rotateL(beforeRoot->lhs_);
			return rotateR(beforeRoot);
		}

		/**
		 * @brief Calculate the difference (bias) between left and right nodes
		 * 				Formula is: left partial tree - right partial tree
		 */
		int bias(node_type *node) { return (node->lhs_->height_ - node->rhs_->height_); }

		/** @brief Update node height and bias by insertion or deletion */
		void updateHeight(node_type *node)
		{
			int left_height = node->lhs_->height_;
			int right_height = node->rhs_->height_;

			node->height_ = 1 + (left_height > right_height ? left_height : right_height);
			node->bias_ = left_height - right_height;
		}

	};
}

#endif
