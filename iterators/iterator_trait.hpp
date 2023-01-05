#ifndef ITERATOR_TRAIT_HPP_
#define ITERATOR_TRAIT_HPP_

#include <iterator.hpp>

namespace ft {
		/**
	 * @brief Traits class defining properties of iterators.
	 */
	template <class Iterator>
	class iterator_traits {
		typedef typename ft::iterator<ft::random_access_iterator_tag, Iterator>::value_type value_type;								// not pointer or reference
		typedef typename ft::iterator<ft::random_access_iterator_tag, Iterator>::difference_type difference_type;			// Signed integer type for the difference of iterators
		typedef typename ft::iterator<ft::random_access_iterator_tag, Iterator>::pointer pointer;											// pointer type
		typedef typename ft::iterator<ft::random_access_iterator_tag, Iterator>::reference reference;									// reference type
		typedef typename ft::iterator<ft::random_access_iterator_tag, Iterator>::iterator_category iterator_category; // iterator category (random, forward ...etc)
	};

	template <class T>
	class iterator_traits<T*> {
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type value_type;								// not pointer or reference
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type difference_type;			// Signed integer type for the difference of iterators
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer pointer;											// pointer type
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference reference;									// reference type
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category iterator_category; // iterator category (random, forward ...etc)
	};

	template <class T>
	class iterator_traits<const T*> {
		typedef typename ft::iterator<ft::random_access_iterator_tag, const T>::value_type value_type;								// not pointer or reference
		typedef typename ft::iterator<ft::random_access_iterator_tag, const T>::difference_type difference_type;			// Signed integer type for the difference of iterators
		typedef typename ft::iterator<ft::random_access_iterator_tag, const T>::pointer pointer;											// pointer type
		typedef typename ft::iterator<ft::random_access_iterator_tag, const T>::reference reference;									// reference type
		typedef typename ft::iterator<ft::random_access_iterator_tag, const T>::iterator_category iterator_category; // iterator category (random, forward ...etc)
	};
};

#endif
