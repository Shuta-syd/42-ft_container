#ifndef IS_INTEGRAL_HPP_
#define IS_INTEGRAL_HPP_


/** @brief Trait class that identifies whether T is an integral type. */
namespace ft {
	template <class T, T v>
	struct integral_constant {
	static const T value = v;
	typedef T value_type;
	typedef integral_constant<T,v> type;
	operator T() { return v; }
};

	typedef integral_constant<bool, false> false_type;
	typedef integral_constant<bool, true> true_type;

	template <typename T>
	struct is_integral_helper : public false_type {};
	template <>
	struct is_integral_helper<char> : public true_type {};
	template <>
	struct is_integral_helper<char16_t> : public true_type {};
	template <>
	struct is_integral_helper<char32_t> : public true_type {};
	template <>
	struct is_integral_helper<wchar_t> : public true_type {};
	template <>
	struct is_integral_helper<signed char> : public true_type {};
	template <>
	struct is_integral_helper<short int> : public true_type {};
	template <>
	struct is_integral_helper<int> : public true_type {};
	template <>
	struct is_integral_helper<long int> : public true_type {};
	template <>
	struct is_integral_helper<long long int> : public true_type {};
	template <>
	struct is_integral_helper<unsigned int> : public true_type {};
	template <>
	struct is_integral_helper<unsigned char> : public true_type {};
	template <>
	struct is_integral_helper<unsigned short int> : public true_type {};
	template <>
	struct is_integral_helper<unsigned long int> : public true_type {};
	template <>
	struct is_integral_helper<unsigned long long int> : public true_type {};

	template <>
	struct is_integral_helper<const char> : public true_type {};
	template <>
	struct is_integral_helper<const char16_t> : public true_type {};
	template <>
	struct is_integral_helper<const char32_t> : public true_type {};
	template <>
	struct is_integral_helper<const wchar_t> : public true_type {};
	template <>
	struct is_integral_helper<const signed char> : public true_type {};
	template <>
	struct is_integral_helper<const short int> : public true_type {};
	template <>
	struct is_integral_helper<const int> : public true_type {};
	template <>
	struct is_integral_helper<const long int> : public true_type {};
	template <>
	struct is_integral_helper<const long long int> : public true_type {};
	template <>
	struct is_integral_helper<const unsigned int> : public true_type {};
	template <>
	struct is_integral_helper<const unsigned char> : public true_type {};
	template <>
	struct is_integral_helper<const unsigned short int> : public true_type {};
	template <>
	struct is_integral_helper<const unsigned long int> : public true_type {};
	template <>
	struct is_integral_helper<const unsigned long long int> : public true_type {};

	template <class T>
	struct is_integral: public is_integral_helper<T> {};
}

#endif
