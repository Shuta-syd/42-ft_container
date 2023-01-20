#ifndef PAIR_HPP_
#define PAIR_HPP_

#include <algorithm.hpp>

/**
 * @brief This class couples together a pair of values, which may be of different types (T1 and
 *      T2). The individual values can be accessed through its public members first and second.
 */
namespace ft {
	template <class T1, class T2>
	struct pair {
		public:
			typedef T1 first_type;
			typedef T2 second_type;
			first_type first;
			second_type second_;

			pair(): first(), second_() {}

			template <class U, class V>
			pair(const pair<U, V> &pr): first(pr.first), second_(pr.second_) {}

			pair (const first_type& a, const second_type& b): first(a), second_(b) {}

		pair& operator= (const pair& pr) {
			first = pr.first;
			second_ = pr.second_;
			return *this;
		}
	};

		/** @brief Creates a std::pair object, deducing the target type from the types of arguments */
		template< class T1, class T2 >
		ft::pair<T1, T2> make_pair( T1 t, T2 u ) { return ft::pair<T1, T2>(t, u); }

		template< class T1, class T2 >
		bool operator==( const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs ) {
			return (lhs.first_ == rhs.first_ && lhs.second_ == rhs.second_) ;
		}

		template <class T1, class T2>
		bool operator!=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs) { return !(lhs == rhs); }

		template <class T1, class T2>
		bool operator<(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs) {
			return (lhs.first_ < rhs.first_ && lhs.second_ < rhs.second_);
		}

		template <class T1, class T2>
		bool operator<=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs) { return !(rhs < lhs); }

		template <class T1, class T2>
		bool operator>(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs) { return rhs < lhs; }

		template <class T1, class T2>
		bool operator>=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs) { return !(lhs < rhs); }
}

#endif
