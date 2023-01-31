#ifndef RANDOM_ACCESS_ITERATOR_HPP_
#define RANDOM_ACCESS_ITERATOR_HPP_

#include <iterator.hpp>

namespace ft {
	template <class T>
	class random_access_iterator : public ft::iterator<ft::random_access_iterator_tag, T> {
	public:
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type value_type;								// not pointer or reference
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type difference_type;			// Signed integer type for the difference of iterators
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer pointer;											// pointer type
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference reference;									// reference type
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category iterator_category; // iterator category (random, forward ...etc)

		/* Constructor & Destructor */
		random_access_iterator() : current_pos_(NULL){}
		random_access_iterator(pointer pos) : current_pos_(pos) {}
		~random_access_iterator(){};
		random_access_iterator(const random_access_iterator &rhs) {
			*this = rhs;
		};

		operator random_access_iterator<const value_type>() const {
			return random_access_iterator<const value_type>(current_pos_);
		}

		/* operators */
		random_access_iterator &operator=(const random_access_iterator &rhs) {
			if (*this == rhs)
				return *this;
			this->current_pos_ = rhs.current_pos_;
			return *this;
		}

	pointer base() const { return current_pos_; };

		reference operator*() const { return *current_pos_; }
		pointer operator->() const { return &(*current_pos_); }
		reference operator[](difference_type n) const { return *(current_pos_ + n); }
		random_access_iterator &operator++() { // prefix increment
			current_pos_++;
			return *this;
		}
		random_access_iterator operator++(int) { // postfix increment
			random_access_iterator tmp(*this);
			++(*this);
			return tmp;
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
		bool operator!=(const random_access_iterator &rhs) const { return !(*this == rhs); }
		bool operator>(const random_access_iterator &rhs) const { return this->current_pos_ > rhs.current_pos_; }
		bool operator<(const random_access_iterator &rhs) const { return this->current_pos_ < rhs.current_pos_; }
		bool operator>=(const random_access_iterator &rhs) const { return this->current_pos_ >= rhs.current_pos_; }
		bool operator<=(const random_access_iterator &rhs) const { return this->current_pos_ <= rhs.current_pos_; }

	private:
		pointer current_pos_;
	};

	template <class T>
	typename ft::random_access_iterator<T>::difference_type operator+ (typename ft::random_access_iterator<T>::difference_type n, const ft::random_access_iterator<T>& rev_it) {
		ft::random_access_iterator<T> tmp(rev_it);
			tmp.current_pos_ += n;
			return tmp;
	}

	template <class T>
	typename ft::random_access_iterator<T>::difference_type operator- (const ft::random_access_iterator<T>& lhs,    const ft::random_access_iterator<T>& rhs) {
		if (lhs.base() > rhs.base())
			return lhs.base() - rhs.base();
		else
			return rhs.base() - lhs.base();
	}
}

#endif
