#ifndef REVERSE_ITERATOR_HPP_
#define REVERSE_ITERATOR_HPP_

#include <iterator_trait.hpp>

namespace ft {
	template <class Iterator>
	class reverse_iterator {
		public:
			typedef Iterator iterator_type;
			typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
			typedef typename iterator_traits<Iterator>::value_type value_type;
			typedef typename iterator_traits<Iterator>::difference_type difference_type;
			typedef typename iterator_traits<Iterator>::pointer pointer;
			typedef typename iterator_traits<Iterator>::reference reference;

					/* Constructor & Destructor */
			reverse_iterator() : current_pos_(NULL){};
			explicit reverse_iterator(iterator_type pos) : current_pos_(pos) {};
			~reverse_iterator(){};

			template <class Iter>
			reverse_iterator(const reverse_iterator<Iter> &rhs) {
				*this = rhs;
			};

			iterator_type base() const { return current_pos_; };

			/* operators */
			template <class Iter>
			reverse_iterator &operator=(const reverse_iterator<Iter> &rhs) {
				if (*this == rhs)
					return *this;
				this->current_pos_ = rhs.base();
				return *this;
			}

			reference operator*() const {
				iterator_type tmp(current_pos_);
				return *(--tmp);
			}

			pointer operator->() const { return &(*current_pos_); }
			reference operator[](difference_type n) { return current_pos_ + n; }

			reverse_iterator &operator++() { // prefix increment
				--current_pos_;
				return *this;
			}
			reverse_iterator operator++(int) { // postfix increment
				reverse_iterator tmp(*this);
				++(*this);
				return *tmp;
			}
			reverse_iterator &operator--() {
				++current_pos_;
				return *this;
			}

			reverse_iterator operator--(int) {
				reverse_iterator tmp(*this);
				--(*this);
				return tmp;
			}

			reverse_iterator &operator+=(difference_type n) {
				current_pos_ -= n;
				return *this;
			}
			reverse_iterator operator+(difference_type n) {
				reverse_iterator tmp(*this);
				tmp.current_pos_ -= n;
				return tmp;
			}
			reverse_iterator &operator-=(difference_type n) {
				current_pos_ += n;
				return *this;
			}
			reverse_iterator operator-(difference_type n) {
				reverse_iterator tmp(*this);
				tmp.current_pos_ += n;
				return tmp;
			}

		private:
			iterator_type current_pos_;
	};

	template <class Iterator>
	bool operator== (const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs) { return lhs.base() == rhs.base(); }

	template <class Iterator>
	bool operator!= (const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs) { return !(lhs.base() == rhs.base()); }

	template <class Iterator>
	bool operator< (const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs) { return lhs.base() < rhs.base(); }

	template <class Iterator>
	bool operator> (const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs) { return !(lhs.base() < rhs.base()); }

	template <class Iterator>
	bool operator<= (const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs) { return lhs.base() <= rhs.base(); }

	template <class Iterator>
	bool operator>= (const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs) { return !(lhs.base() <= rhs.base()); }

	template <class Iterator>
	ft::reverse_iterator<Iterator> operator+ (typename ft::reverse_iterator<Iterator>::difference_type n, const ft::reverse_iterator<Iterator>& rev_it) {
		ft::reverse_iterator<Iterator> tmp(rev_it);
			tmp.current_pos_ -= n;
			return tmp;
	}

	template <class Iterator>
	typename ft::reverse_iterator<Iterator>::difference_type operator- (const ft::reverse_iterator<Iterator>& lhs,    const ft::reverse_iterator<Iterator>& rhs) {
		if (lhs.base() > rhs.base())
			return lhs.base() - rhs.base();
		else
			return rhs.base() - lhs.base();
	}
};

#endif
