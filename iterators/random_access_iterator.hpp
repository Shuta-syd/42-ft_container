#ifndef RANDOM_ACCESS_ITERATOR_HPP_
#define RANDOM_ACCESS_ITERATOR_HPP_

#include <iterator.hpp>

namespace ft {
	template <class Iterator>
	class random_access_iterator : public ft::iterator<ft::random_access_iterator_tag, Iterator> {
	public:
		typedef Iterator iterator_type;																																								// What type of information this iterator has
		typedef typename ft::iterator<ft::random_access_iterator_tag, Iterator>::value_type value_type;								// not pointer or reference
		typedef typename ft::iterator<ft::random_access_iterator_tag, Iterator>::difference_type difference_type;			// Signed integer type for the difference of iterators
		typedef typename ft::iterator<ft::random_access_iterator_tag, Iterator>::pointer pointer;											// pointer type
		typedef typename ft::iterator<ft::random_access_iterator_tag, Iterator>::reference reference;									// reference type
		typedef typename ft::iterator<ft::random_access_iterator_tag, Iterator>::iterator_category iterator_category; // iterator category (random, forward ...etc)

		/* Constructor & Destructor */
		random_access_iterator() : current_pos_(NULL){};
		explict random_access_iterator(iterator_type pos) : current_pos_(pos){};
		~random_access_iterator(){};
		random_access_iterator(const random_access_iterator &rhs) {
			*this = rhs;
		};

		/* operators */
		random_access_iterator &operator=(const random_access_iterator &rhs) {
			if (*this == rhs)
				return *this;
			this->current_pos_ = rhs.current_pos_;
			return *this;
		}

		reference operator*() const { return *current_pos_; }
		pointer operator->() const { return &(*current_pos_); }
		reference operator[](difference_type n) { return current_pos_ + n; }
		random_access_iterator &operator++() { // prefix increment
			current_pos_++;
			return *this;
		}
		random_access_iterator operator++(int) { // postfix increment
			random_access_iterator tmp(*this);
			++(*this);
			return *tmp;
		}
		random_access_iterator &operator--() {
			current_pos_--;
			return *this;
		}
		random_access_iterator operator--(int) {
			random_access_iterator tmp(*this);
			--(*this);
			return tmp;
		}
		random_access_iterator &operator+=(difference_type n) {
			current_pos_ += n;
			return *this;
		}
		random_access_iterator operator+(difference_type n) {
			random_access_iterator tmp(*this);
			tmp.current_pos_ += n;
			return tmp;
		}
		random_access_iterator &operator-=(difference_type n) {
			current_pos_ -= n;
			return *this;
		}
		random_access_iterator operator-(difference_type n) {
			random_access_iterator tmp(*this);
			tmp.current_pos_ -= n;
			return tmp;
		}
		difference_type operator-(const random_access_iterator &rhs) {
			random_access_iterator tmp(*this);
			difference_type diff = 0;
			if (tmp > rhs) {
				while (rhs != tmp) {
					tmp--;
					diff++;
				}
			}
			else {
				while (rhs != tmp) {
					tmp++;
					diff++;
				}
			}
			return diff;
		}

		bool operator==(const random_access_iterator &rhs) const { return this->current_pos_ == rhs.current_pos_; }
		bool operator!=(const random_access_iterator &rhs) const { return !(this == rhs); }
		bool operator>(const random_access_iterator &rhs) const {return this->current_pos_ > rhs.current_pos_};
		bool operator<(const random_access_iterator &rhs) const {return !(this > rhs)};
		bool operator>=(const random_access_iterator &rhs) const {return this->current_pos_ >= rhs.current_pos_};
		bool operator<=(const random_access_iterator &rhs) const {return !(this >= rhs)};

	private:
		iterator_type current_pos_;
	};

	template <class Iterator>
	random_access_iterator<Iterator> operator+ (typename random_access_iterator<Iterator>::difference_type n, const random_access_iterator<Iterator>& rev_it) {
		random_access_iterator tmp(rev_it);
			tmp.current_pos_ += n;
			return tmp;
	};

	template <class Iterator>
	random_access_iterator<Iterator> operator- (typename random_access_iterator<Iterator>::difference_type n, const random_access_iterator<Iterator>& rev_it) {
		random_access_iterator tmp(rev_it);
			tmp.current_pos_ -= n;
			return tmp;
	};
};

#endif
