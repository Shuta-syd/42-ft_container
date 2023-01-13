#include "test.hpp"
#include <vector.hpp>
#include <type_traits>
void test_enable_if();

void test_type_traits() {
	test_enable_if();
}


template <typename T>
typename std::enable_if<std::is_integral<T>::value, T>::type
std_add(T a, T b) {
	return a + b;
}

template <typename T>
typename ft::enable_if<ft::is_integral<T>::value, T>::type
ft_add(T a, T b) {
	return a + b;
}

void test_enable_if()
{
	std::cout << "std: ";
	std::cout << std_add(1, 2) << " ";
	std::cout << std_add(22, 20) << std::endl;
	// std::cout << std_add(1.0, 2.0) << std::endl; //error
	std::cout << "ft: ";
	std::cout << ft_add(1, 2) << " ";
	std::cout << ft_add(22, 20) << std::endl;
	// std::cout << ft_add(1.0, 2.0) << std::endl; //error
}
