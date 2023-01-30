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
				else if (current_->rhs_ != nullNode_) {
					current_ = current_->rhs_;
					while (current_->lhs_ != nullNode_)
						current_ = current_->lhs_;
				} else {
					while (current_->pta_->lhs_ != current_)
						current_ = current_->pta_;
					current_ = current_->pta_;
				}
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
			else if (current_->lhs_ != nullNode_) {
				current_ = current_->lhs_;
				while (current_->rhs_ != nullNode_ )
					current_ = current_->rhs_;
			}
			else {
				while (current_->pta_->rhs_ != current_)
					current_ = current_->pta_;
				current_ = current_->pta_;
			}
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
	};
}

#endif
