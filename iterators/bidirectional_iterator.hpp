#ifndef BIDIRECTIONAL_ITERATOR_HPP_
#define BIDIRECTIONAL_ITERATOR_HPP_

#include <node.hpp>
#include <iterator.hpp>

namespace ft {
	template <class T, class Comp>
	class bidirectional_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T> {
		public:
			typedef T iterator_type;
			typedef node<T> node_type;
			typedef typename iterator_traits<T>::iterator_category iterator_category;
			typedef typename iterator_traits<T>::value_type value_type;
			typedef typename iterator_traits<T>::difference_type difference_type;
			typedef typename iterator_traits<T>::pointer pointer;
			typedef typename iterator_traits<T>::reference reference;

			bidirectional_iterator(): current_(), key_compare(Comp()) {}
			explicit bidirectional_iterator(node_type *ptr): current_(ptr), key_compare(Comp()) {}
			bidirectional_iterator(const bidirectional_iterator &rhs) {
				*this = rhs;
			}

			~bidirectional_iterator() {}

			bidirectional_iterator &operator=(const bidirectional_iterator &rhs) {
				if (*this == rhs)
					return *this;
				current_ = rhs.current_;
				key_compare = rhs.key_compare;
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
				if (current_->rhs_ != nullNode_) {
					current_ = current_->lhs_;
					while (current_->lhs_ != nullNode_)
						current_ = current_->lhs_;
					return current_;
				}
				while (current_->pta_->lhs_ != current_)
					current_ = current_->pta_;
				current_ = current_->pta_;
				return *this;
		}

		bidirectional_iterator operator++(int) { // postfix increment
			bidirectional_iterator tmp(*this);
			++(*this);
			return tmp;
		}

		bidirectional_iterator &operator--() {
			if (current_->lhs_ != nullNode_) {
				current_ = current_->rhs_;
				while (current_->rhs_ != nullNode_)
					current_ = current_->rhs_;
				return current_;
			}
			while (current_->pta_->rhs_ != current_)
				current_ = current_->pta_;
			current_ = current_->pta_;
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
			Comp key_compare;
	};
};

#endif
