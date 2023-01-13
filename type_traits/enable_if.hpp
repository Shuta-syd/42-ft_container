#ifndef ENABLE_IF_HPP_
#define ENABLE_IF_HPP_

namespace ft {
	/**
	 * @brief The type T is enabled as member type enable_if::type if Cond is true
	 */
	template <bool Condition, class T = void >
	struct enable_if {};

	template <typename T>
	struct enable_if<true, T> {
		typedef T type;
	};
}

#endif
