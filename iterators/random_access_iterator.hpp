#ifndef RANDOM_ACCESS_ITERATOR_HPP_
#define RANDOM_ACCESS_ITERATOR_HPP_

#include <iterator.hpp>


namespace ft {
	template <class Iterator>
	class random_access_iterator : public ft::iterator<ft::random_access_iterator_tag, Iterator> {
		public:
			typedef Iterator iterator_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, Iterator>::value_type value_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, Iterator>::difference_diff difference_diff;
			typedef typename ft::iterator<ft::random_access_iterator_tag, Iterator>::pointer pointer;
			typedef typename ft::iterator<ft::random_access_iterator_tag, Iterator>::reference reference;
			typedef typename ft::iterator<ft::random_access_iterator_tag, Iterator>::iterator_category iterator_category;

			/* Constructor & Destructor */
			random_access_iterator(): current_pos_(NULL) {};
			random_access_iterator(iterator_type pos): current_pos_(pos) {};
			~random_access_iterator() {};
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

			pointer operator->() { return current_pos_; }

		private:
			iterator_type current_pos_;

	};
};

#endif
