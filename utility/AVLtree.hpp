#ifndef AVLTREE_HPP_
#define AVLTREE_HPP_


/* color code */
#define YEL "\033[33m"
#define RES "\033[m"
#include <memory>
#include <iomanip>
#include <node.hpp>
#include <pair.hpp>
#include <bidirectional_iterator.hpp>
#include <reverse_iterator.hpp>

namespace ft {
	template <class T, class Comp, class N = node<T>, class Allocator = std::allocator<T> >
	class AVLtree {
	public:
		typedef T value_type;
		typedef typename value_type::first_type key_type;
		typedef N node_type;
		typedef typename Allocator::template rebind<N>::other  allocator_type;
		typedef typename std::equal_to<key_type> equal_to;
		typedef bidirectional_iterator<T, node_type> iterator;
		typedef bidirectional_iterator<const T, node_type> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef std::size_t size_type;

		AVLtree() :  root_(), size_(0), begin_(), end_(), nullNode_(), key_compare(Comp()), alloc_(allocator_type()) {
			nullNode_ = alloc_.allocate(1);
			alloc_.construct(nullNode_, node_type());
			begin_ = nullNode_;
			end_ = nullNode_;
			root_ = nullNode_;
		}

		AVLtree(const AVLtree &rhs) { *this = rhs; }


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
				root_ = this->createNode(val, nullNode_, nullNode_);
				begin_ = root_;
				end_ = begin_;
				size_ += 1;
				return ft::make_pair(iterator(root_, nullNode_, end_, begin_), true);
			}

			node_type *pta = this->searchParent(val.first);
			if (equal_to()(pta->key_, val.first))
				return ft::make_pair(iterator(pta, nullNode_, end_, begin_), false);

			node_type *node = this->createNode(val, pta, nullNode_);
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
			size_ += 1;;
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
			if (target == begin_)
				begin_ = this->get_next_node(begin_);
			else if (target == end_)
				end_ = this->get_prev_node(end_);
			else if (target == nullNode_)
				return 0;
			size_ -= 1;
			/**
			 * 1. If the node you want to delete is the leftmost node, simply delete that node
			 * 2. If the node you want to delete has a right subtree, promote it
			 * 3. The node to be deleted is replaced by the node with the largest value in the left subtree, and the node with the largest value is deleted.
			 */
			if (target->lhs_ == nullNode_) {
				this->Replace(target, target->rhs_);
				balanceErase(target->rhs_);
				this->destroyNode(target);
			}
			else {
				node_type *maxNode = this->get_max_node(target->lhs_);
				if (maxNode == begin_)
					begin_ = target;
				else if (target == end_)
					end_ = target;

				target->key_ = maxNode->key_;
				target->val_ = maxNode->val_;
				this->Replace(maxNode, maxNode->lhs_);
				this->balanceErase(maxNode->lhs_);
				this->destroyNode(maxNode);
			}
			return 1;
		}

		/** @brief Delete a specific node */
		void erase(iterator first, iterator last) {
			while (first != last) {
				const key_type &key = first->first;
				first++;

				node_type *target = this->search(key);
				if (target == begin_)
					begin_ = this->get_next_node(begin_);
				else if (target == end_)
					end_ = this->get_prev_node(end_);
				else if (target == nullNode_)
					return;
				size_ -= 1;

				if (target->lhs_ == nullNode_) {
					this->Replace(target, target->rhs_);
					balanceErase(target->rhs_);
					this->destroyNode(target);
				}
				else {
					node_type *maxNode = this->get_max_node(target->lhs_);
					if (maxNode == begin_)
						begin_ = target;
					else if (target == end_)
						end_ = target;

					target->key_ = maxNode->key_;
					target->val_ = maxNode->val_;
					this->Replace(maxNode, maxNode->lhs_);
					this->balanceErase(maxNode->lhs_);
					this->destroyNode(maxNode);
				}
			}
		}


		void swap(AVLtree &other) {
			std::swap(root_, other.root_);
			std::swap(nullNode_, other.nullNode_);
			std::swap(begin_, other.begin_);
			std::swap(end_, other.end_);
			std::swap(size_, other.size_);
			std::swap(key_compare, other.key_compare);
			std::swap(alloc_, other.alloc_);
		}

	iterator upper_bound(const key_type &key) {
		node_type *node = root_;
		node_type *ret = nullNode_;

		while (node != nullNode_) {
			if (key_compare(key, node->key_)) {
				ret = node;
				node = node->lhs_;
			}
			else
				node = node->rhs_;
		}
		return iterator(ret, nullNode_, begin_, end_) ;
	}

	iterator lower_bound(const key_type &key) {
		node_type *node = root_;
		node_type *ret = nullNode_;

		while (node != nullNode_) {
			if (key_compare(node->key_, key) == false) {
				ret = node;
				node = node->lhs_;
			}
			else
				node = node->rhs_;
		}
		return iterator(ret, nullNode_, begin_, end_) ;
	}


		node_type *getRoot() const { return root_; }
		node_type *getNullNode() const { return nullNode_; }
		iterator begin() { return iterator(begin_, nullNode_, end_, begin_); }
		const_iterator begin() const { return const_iterator(begin_, nullNode_, end_, begin_); }
		iterator end() { return iterator(nullNode_, nullNode_, end_, begin_); }
		const_iterator end() const { return const_iterator(nullNode_, nullNode_, end_, begin_); }
		reverse_iterator rbegin() { return reverse_iterator(iterator(end_, nullNode_, end_, begin_)); }
		const_reverse_iterator rbegin() const { return const_reverse_iterator(const_iterator(end_, nullNode_, end_, begin_)); }
		reverse_iterator rend() { return reverse_iterator(iterator(nullNode_, nullNode_, end_, begin_)); }
		const_reverse_iterator rend() const { return const_reverse_iterator(const_iterator(nullNode_, nullNode_, end_, begin_)); }
		size_type size() const { return size_; }
		size_type max_size() const { return alloc_.max_size(); }

		iterator find(const key_type &key) { return iterator(this->search(key), nullNode_, end_, begin_);}
		const_iterator const_find(const key_type &key) {return const_iterator(this->search(key), nullNode_, end_, begin_);}

		void printAVL(node_type *node, int i) {
			if (node == NULL)
				node = root_;
			else if (node == nullNode_)
				return;
			std::cout << YEL << "[ " << i << " ]" << RES << ": ";
			std::cout << " [ " << std::setw(3) << std::right << std::setfill(' ') << node->key_ << " ] ";
			std::cout << " | lhs :[ " << std::setw(3) << std::right << std::setfill(' ') << node->lhs_->key_ << " ] ";
			std::cout << " | rhs :[ " << std::setw(3) << std::right << std::setfill(' ') << node->rhs_->key_ << " ] " << std::endl;
			if (node->lhs_ != nullNode_)
				printAVL(node->lhs_, i + 1);
			if (node->rhs_ != nullNode_)
				printAVL(node->rhs_, i + 1);
		}

	private:
		node_type *root_;
		size_type size_;
		node_type *begin_; // smallest key
		node_type *end_; // largest key
		node_type *nullNode_;
		Comp key_compare;
		allocator_type alloc_;

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
				pivot->pta_ = beforeRoot;

			afterRoot->lhs_ = beforeRoot;
			this->Replace(beforeRoot, afterRoot);
			beforeRoot->pta_ = afterRoot;

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
				pivot->pta_ = beforeRoot;

			afterRoot->rhs_ = beforeRoot;
			this->Replace(beforeRoot, afterRoot);
			beforeRoot->pta_ = afterRoot;

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
		void updateHeight(node_type *node) {
			int left_height = node->lhs_->height_;
			int right_height = node->rhs_->height_;

			node->height_ = 1 + (left_height > right_height ? left_height : right_height);
		}

		void Replace(node_type *before, node_type *after) {
			node_type *pta = before->pta_;

			if (before == root_)
				root_ = after;
			else if (pta->lhs_ == before)
				pta->lhs_ = after;
			else
				pta->rhs_ = after;

			after->pta_ = pta;
		}


	node_type *get_min_node(node_type *node) {
			while (node->lhs_ != nullNode_ && node->lhs_) {
				node = node->lhs_;
			}
			return node;
	}

	node_type *get_max_node(node_type *node) {
			while (node->rhs_ != nullNode_ && node->rhs_) {
				node = node->rhs_;
			}
			return node;
	}

	bool is_right(node_type *node) {
			return node->pta_ && node->pta_ != nullNode_ && node == node->pta_->rhs_;
	}

	bool is_left(node_type *node) {
			return node->pta_ && node->pta_ != nullNode_ && node == node->pta_->lhs_;
	}

		node_type *get_next_node(node_type *node) {
			if (node->rhs_ != nullNode_)
					return this->get_min_node(node->rhs_);
			else {
				while (this->is_right(node)) {
					node = node->pta_;
				}
			}
			return node->pta_;
		}

		node_type *get_prev_node(node_type *node) {
			if (node->lhs_ != nullNode_)
					return this->get_max_node(node->lhs_);
			else {
				while (this->is_left(node)) {
					node = node->pta_;
				}
			}
			return node->pta_;
		}

		/** @brief  Create node and allocate memory*/
		node_type *createNode(const value_type &val, node_type *pta, node_type *null) {
			node_type *node;
			node = alloc_.allocate(1);
			alloc_.construct(node, node_type(val, pta, null));
			return node;
		}

		void destroyTree(node_type *node) {
			if (node == nullNode_)
				return;
			if (node->lhs_ != nullNode_)
				destroyTree(node->lhs_);
			if (node->rhs_ != nullNode_)
				destroyTree(node->rhs_);
			destroyNode(node);
		}

		void destroyNode(node_type *node) {
			alloc_.destroy(node);
			alloc_.deallocate(node, 1);
		}
	};
}

#endif
