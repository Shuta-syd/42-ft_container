#ifndef EQUAL_HPP_
#define EQUAL_HPP_

namespace ft {
	template <class InputIterator1, class InputIterator2>
		bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
	{
		while (first1 != last1) {
			if (!(*first1 == *first2))
				return false;
			++first1; ++first2;
		}
		return true;
	}

	template <class InputIterator1, class InputIterator2>
		bool equal_map ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
	{
		while (first1 != last1) {
			if (!(first1->first == first2->first)) {
				return false;
			}
			++first1; ++first2;
		}
		return true;
	}
}


#endif
