#ifndef BIDIRECTIONAL_ITERATOR_HPP_
#define BIDIRECTIONAL_ITERATOR_HPP_

#include <node.hpp>
#include <iterator.hpp>
#include <iterator_traits.hpp>

namespace ft {
	template <class T, class N>
	class bidirectional_iterator : public iterator<bidirectional_iterator_tag, T> {
		public:
			typedef N node_type;
			typedef typename iterator<bidirectional_iterator_tag, T>::iterator_category iterator_category;
			typedef typename iterator<bidirectional_iterator_tag, T>::value_type value_type;
			typedef typename iterator<bidirectional_iterator_tag, T>::difference_type difference_type;
			typedef typename iterator<bidirectional_iterator_tag, T>::pointer pointer;
			typedef typename iterator<bidirectional_iterator_tag, T>::reference reference;

			bidirectional_iterator(): current_() {}
			explicit bidirectional_iterator(node_type *ptr, node_type *null, node_type *end, node_type *begin): current_(ptr), nullNode_(null), end_(end), begin_(begin) {}
			bidirectional_iterator(const bidirectional_iterator &rhs) {
				*this = rhs;
			}

			operator bidirectional_iterator<const value_type, node_type>() const {
				return bidirectional_iterator<const value_type, node_type>(current_, nullNode_, end_, begin_);
			}

			~bidirectional_iterator() {}

			bidirectional_iterator &operator=(const bidirectional_iterator &rhs) {
				if (*this == rhs)
					return *this;
				current_ = rhs.current_;
				nullNode_ = rhs.nullNode_;
				end_ = rhs.end_;
				begin_ = rhs.begin_;
				return *this;
			}

			node_type *base() const { return current_; };

			reference operator*() const { return current_->val_; }
			pointer operator->() const { return &current_->val_; }
			bool operator==(const bidirectional_iterator &rhs) const { return current_ == rhs.current_; }
			bool operator!=(const bidirectional_iterator &rhs) const { return current_ != rhs.current_; }
			bool operator>(const bidirectional_iterator &rhs) const { return current_ > rhs.current_; }
			bool operator<=(const bidirectional_iterator &rhs) const { return current_ <= rhs.current_; }
			bool operator<(const bidirectional_iterator &rhs) const { return current_ < rhs.current_; }
			bool operator>=(const bidirectional_iterator &rhs) const { return current_ >= rhs.current_; }

			bidirectional_iterator &operator++() { // prefix increment
				if (current_ == end_)
					current_ = nullNode_;
				else if (current_ == nullNode_)
					current_ = begin_;
				else
					current_ = this->get_next_node(current_);
				return *this;
		}

		bidirectional_iterator operator++(int) { // postfix increment
				bidirectional_iterator tmp(*this);
				++(*this);
				return tmp;
		}

		bidirectional_iterator &operator--() {
			if (current_ == begin_)
				current_ = nullNode_;
			else if (current_ == nullNode_)
				current_ = end_;
			else
				current_ = this->get_prev_node(current_);
			return *this;
		}

		bidirectional_iterator operator--(int) {
			bidirectional_iterator tmp(*this);
			--(*this);
			return tmp;
		}

		private:
			node_type *current_;
			node_type *nullNode_;
			node_type *end_;
			node_type *begin_;

			bool is_right(node_type *node) {
			return node->pta_ && node->pta_ != nullNode_ && node == node->pta_->rhs_;
			}

			bool is_left(node_type *node) {
			return node->pta_ && node->pta_ != nullNode_ && node == node->pta_->lhs_;
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
	};
}

#endif
