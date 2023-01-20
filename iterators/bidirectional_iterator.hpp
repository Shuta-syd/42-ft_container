#ifndef BIDIRECTIONAL_ITERATOR_HPP_
#define BIDIRECTIONAL_ITERATOR_HPP_

#include <iterator.hpp>

namespace ft {
	template <class Iterator>
	class bidirectional_iterator : public ft::iterator<ft::bidirectional_iterator_tag, Iterator> {
		public:
			typedef Iterator iterator_type;
			typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
			typedef typename iterator_traits<Iterator>::value_type value_type;
			typedef typename iterator_traits<Iterator>::difference_type difference_type;
			typedef typename iterator_traits<Iterator>::pointer pointer;
			typedef typename iterator_traits<Iterator>::reference reference;
	}
};

#endif
