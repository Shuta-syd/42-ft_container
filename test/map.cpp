#include "test.hpp"
#include <map>
#include <map.hpp>
void test();
void test_iterator();
template <class T1, class T2>
void print_std_map(std::map<T1, T2> test);
template <class T1, class T2>
void print_ft_map(ft::map<T1, T2> test);
template <class T1, class T2>
void print_std_map_reverse(std::map<T1, T2> test);
template <class T1, class T2>
void print_ft_map_reverse(ft::map<T1, T2> test);

#define FT_PAIR(a, b) ft::pair<int, std::string>(a, b)
#define STD_PAIR(a, b) std::pair<int, std::string>(a, b)

void test_map() {
	print_white("--------------------------------------------------");
	print_white("|                      map                       |");
	print_white("--------------------------------------------------");

	test_iterator();
	// test();
}

void test() {
	std::map<int, std::string> root;
	root[2] = "Hello";
	root[1] = "World";
	root[3] = "42";

	for (std::map<int, std::string>::iterator it = root.begin(); it != root.end(); it++) {
		std::cout << (*it).first << std::endl;
	}
}

void test_iterator() {
	print_white("--------------------------------------------------");
	print_white("|                  TEST Iterator                 |");
	print_white("--------------------------------------------------");

	print_mgn("bidirectional operator++");
	std::map<int, std::string> std_test1;
	std_test1.insert(STD_PAIR(42, "Hello"));
	std_test1.insert(STD_PAIR(10, "World"));
	std_test1.insert(STD_PAIR(50, "42Tokyo"));
	std::cout << "std: ";
	print_std_map<int, std::string>(std_test1);

	ft::map<int, std::string> ft_test1;
	ft_test1.insert(FT_PAIR(42, "Hello"));
	ft_test1.insert(FT_PAIR(10, "World"));
	ft_test1.insert(FT_PAIR(50, "42Tokyo"));
	std::cout << "ft : ";
	print_ft_map(ft_test1);

	// print_mgn("bidirectional  operator--");
	// std::map<int, std::string> std_test2;
	// std_test2.insert(STD_PAIR(42, "Hello"));
	// std_test2.insert(STD_PAIR(10, "World"));
	// std_test2.insert(STD_PAIR(50, "42Tokyo"));
	// std::cout << "std: ";
	// print_std_map_reverse<int, std::string>(std_test2);

	// ft::map<int, std::string> ft_test2;
	// ft_test2.insert(FT_PAIR(42, "Hello"));
	// ft_test2.insert(FT_PAIR(10, "World"));
	// ft_test2.insert(FT_PAIR(50, "42Tokyo"));
	// std::cout << "ft : ";
	// print_ft_map_reverse(ft_test2);
}

template <class T1, class T2>
void print_std_map(std::map<T1, T2> test) {

		typename std::map<T1, T2>::iterator it = test.begin();
		for (; it != test.end(); it++) {
			std::cout << "[" << std::setw(2) << std::right << std::setfill(' ') << it->first << "]";
	}
	std::cout << std::endl;
}

template <class T1, class T2>
void print_ft_map(ft::map<T1, T2> test) {

		typename ft::map<T1, T2>::iterator it = test.begin();
		for (; it != test.end(); it++) {
			std::cout << "[" << std::setw(2) << std::right << std::setfill(' ') << it->first << "]";
	}
	std::cout << std::endl;
}


template <class T1, class T2>
void print_std_map_reverse(std::map<T1, T2> test) {

		typename std::map<T1, T2>::iterator it = --(test.end());
		for (; it != test.begin(); it--) {
			std::cout << "[" << std::setw(2) << std::right << std::setfill(' ') << it->first << "]";
	}
	std::cout << std::endl;
}

template <class T1, class T2>
void print_ft_map_reverse(ft::map<T1, T2> test) {

		typename ft::map<T1, T2>::iterator it = --(test.end());
		for (; it != test.begin(); it--) {
			std::cout << "[" << std::setw(2) << std::right << std::setfill(' ') << it->first << "]";
	}
	std::cout << std::endl;
}
