#ifndef AVLTREE_HPP_
#define AVLTREE_HPP_

#include <memory>
#include <iomanip>
#include <node.hpp>
#include <pair.hpp>
#include <bidirectional_iterator.hpp>

namespace ft {
	template <class T, class Comp, class Allocator = std::allocator<T> >
	class AVLtree {
	public:
		typedef T value_type;
		typedef typename value_type::first_type key_type;
		typedef Allocator allocator_type;
		typedef node<T> node_type;
		typedef typename std::equal_to<key_type> equal_to;
		typedef bidirectional_iterator<T, node_type> iterator;
		typedef bidirectional_iterator<const T, node_type> const_iterator;
		typedef std::size_t size_type;

		AVLtree() : size_(0) ,root_(), begin_(), end_(), nullNode_(new node_type()), key_compare(Comp()) {
			root_ = nullNode_;
		}

		AVLtree(const AVLtree &rhs) { *this = rhs; }

		AVLtree &operator=(const AVLtree &rhs) {
			size_ = rhs.size_;
			root_ = rhs.root_;
			nullNode_ = rhs.nullNode_;
			begin_ = rhs.begin_;
			end_ = rhs.end_;
			key_compare = rhs.key_compare;
			return *this;
		}

		~AVLtree() {
			this->destroyTree(root_);
			this->destroyNode(nullNode_);
		}

		/**
		 * @brief Insert at the appropriate position in the AVLtree
		 * Duplicate: https://cplusplus.com/reference/map/map/insert/
		 */
		pair<iterator, bool> insert(const value_type &val) {
			if (root_ == nullNode_) {
				root_ = new node_type(val, nullNode_, nullNode_);
				begin_ = root_;
				end_ = begin_;
				size_ += 1;
				return ft::make_pair(iterator(root_, nullNode_, end_, begin_), true);
			}

			node_type *pta = this->searchParent(val.first);
			if (equal_to()(pta->key_, val.first))
				return ft::make_pair(iterator(pta, nullNode_, end_, begin_), false);

			node_type *node = new node_type(val, pta, nullNode_);
			if (key_compare(pta->key_, val.first)) {
				pta->rhs_ = node;
				end_ = pta->rhs_;
				balanceInsert(pta->rhs_);
			}
			else {
				pta->lhs_ = node;
				begin_ = pta->lhs_;
				balanceInsert(pta->lhs_);
			}
			size_ += 1;
			return ft::make_pair(iterator(node, nullNode_, end_, begin_), true);
		}

		/** @brief Locate a specific key from a specific tree */
		node_type *search(const key_type &key) const {
			node_type *node = root_;
			while (node != nullNode_ && node->key_ != key) {
				node = key_compare(node->key_, key) ? node->rhs_ : node->lhs_;
			}
			return node;
		}

		/** @brief Delete a specific node */
		size_type erase(const key_type &key) {
			node_type *target = this->search(key);
			if (target == nullNode_)
				return 0;
			size_ -= 1;
			/**
			 * 1. If the node you want to delete is the leftmost node, simply delete that node
			 * 2. If the node you want to delete has a right subtree, promote it
			 * 3. The node to be deleted is replaced by the node with the largest value in the left subtree, and the node with the largest value is deleted.
			 */
			if (target->lhs_ == nullNode_) {
				// All patterns of equilibrium binary tree collapse are on this side.
				node_type *pta = target->pta_;
				if (root_ == target)
					root_ = target->rhs_;
				else if (pta->lhs_ == target)
					pta->lhs_ = target->rhs_;
				else
					pta->rhs_ = target->rhs_;
				target->rhs_->pta_ = pta;
				balanceErase(target->rhs_);
				delete target;
			}
			else {
				node_type *maxNode = this->searchMaxNode(target->lhs_);
				node_type *pta = maxNode->pta_;
				target->key_ = maxNode->key_;
				target->val_ = maxNode->val_;
				if (pta->lhs_ == maxNode)
					pta->lhs_ = maxNode->lhs_;
				else
					pta->rhs_ = maxNode->lhs_;
				maxNode->lhs_->pta_ = pta;
				balanceErase(target->lhs_);
				if (maxNode->lhs_ == nullNode_)
					maxNode->lhs_->pta_ = nullNode_;
				delete maxNode;
			}
			return 1;
		}

		node_type *getNullNode() const { return nullNode_; }
		iterator begin() { return iterator(begin_, nullNode_, end_, begin_); }
		const_iterator begin() const { return const_iterator(begin_, nullNode_, end_, begin_); }
		iterator end() { return iterator(nullNode_, nullNode_, end_, begin_); }
		const_iterator end() const { return const_iterator(nullNode_, nullNode_, end_, begin_); }
		size_type size() const { return size_; }

		void printAVL(node_type *node, int i) {
			if (node == NULL)
				node = root_;
			std::cout << YEL << "[ " << i << " ]" << RES << ": ";
			std::cout << " [ " << std::setw(3) << std::right << std::setfill(' ') << node->key_ << " ] ";
			std::cout << " | lhs :[ " << std::setw(3) << std::right << std::setfill(' ') << node->lhs_->key_ << " ] ";
			std::cout << " | rhs :[ " << std::setw(3) << std::right << std::setfill(' ') << node->rhs_->key_ << " ] " << std::endl;
			if (node->lhs_ != nullNode_)
				printAVL(node->lhs_, i + 1);
			if (node->rhs_ != nullNode_)
				printAVL(node->rhs_, i + 1);
		}

		node_type *root_;
		size_type size_;
		node_type *begin_;
		node_type *end_;
	private:
		node_type *nullNode_;
		Comp key_compare;

		/** @brief Search for appropriate parent node of val to insert by traversing from root */
		node_type *searchParent(const key_type &key) {
			node_type *pta = root_;
			node_type *candidate = root_;
			bool high_or_low;

			while (candidate) {
				pta = candidate;
				if (equal_to()(pta->key_, key))
					return pta;
				high_or_low = key_compare(pta->key_, key);
				if ((high_or_low && pta->rhs_ == nullNode_) && (!high_or_low && pta->lhs_ == nullNode_))
					return pta;
				candidate = high_or_low ? pta->rhs_ : pta->lhs_;
				if (candidate == nullNode_)
					return pta;
			}
			return pta;
		}

		/** @brief Check equilibrium binary tree and rotate if it is not balanced (insert) */
		void balanceInsert(node_type *target) {
			while (target->pta_ != nullNode_) {
				node_type *pta = target->pta_;
				int height = pta->height_;

				if (this->bias(pta) == 2) // need to rotate
					pta = this->bias(pta->lhs_) == 1 ? this->rotateR(pta) : this->rotateLR(pta);
				if (this->bias(pta) == -2) // need to rotate
					pta = this->bias(pta->rhs_) == -1 ? this->rotateL(pta) : this->rotateRL(pta);
				else // -1 <= bias <= 1, no problem, update parent height
					this->updateHeight(pta);
				if (height == pta->height_) // nothing update == end point
					break;
				target = pta;
			}
		}

	/** @brief Check equilibrium binary tree and rotate if it is not balanced (erase) */
	void balanceErase(node_type *target) {
		while (target->pta_ != nullNode_) {
			node_type *pta = target->pta_;
			int height = pta->height_;

			if (this->bias(pta) == 2)
				pta = this->bias(pta->lhs_) >= 0 ? rotateR(pta) : rotateLR(pta);
			if (this->bias(pta) == -2)
				pta = this->bias(pta->rhs_) <= 0 ? rotateL(pta) : rotateRL(pta); //segv
			else
				this->updateHeight(pta);
			if (height == pta->height_)
				break;
			target = pta;
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
			beforeRoot->rhs_ = beforeRoot->rhs_->pta_;
			return rotateL(beforeRoot);
		}

		/** @brief single LL rotate + RR rotate rotate */
		node_type *rotateLR(node_type *beforeRoot) {
			rotateL(beforeRoot->lhs_);
			beforeRoot->lhs_ = beforeRoot->lhs_->pta_;
			return rotateR(beforeRoot);
		}

		/**
		 * @brief Calculate the difference (bias) between left and right nodes
		 * 				Formula is: left partial tree - right partial tree
		 */
		int bias(node_type *node) { return (node->lhs_->height_ - node->rhs_->height_); }

		/** @brief Update node height and bias by insertion or deletion */
		void updateHeight(node_type *node) {
			int left_height = node->lhs_->height_;
			int right_height = node->rhs_->height_;

			node->height_ = 1 + (left_height > right_height ? left_height : right_height);
		}

		/** @brief Search for the maximum value from the left-branch tree of a specific node */
		node_type *searchMaxNode(node_type *node) {
			while (node->rhs_ != nullNode_) {
				node = node->rhs_;
			}
			return node;
		}

		/** @brief  */
		void destroyTree(node_type *root) {

		}

		/**  @brief  */
		void destroyNode(node_type *node) {

		}
	};
}

#endif
