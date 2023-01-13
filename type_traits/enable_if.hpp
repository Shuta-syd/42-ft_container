#ifndef ENABLE_IF_HPP_
#define ENABLE_IF_HPP_

namespace ft {
	/**
	 * @brief The type T is enabled as member type enable_if::type if Cond is true
	 */
	template <bool Condition, class T = void >
	struct enable_if {
		typedef T type;
	};

	template <typename T>
	struct ft::enable_if<false, T> {};
}

#endif
