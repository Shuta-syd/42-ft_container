#include "test.hpp"
#include <map>
#include <map.hpp>
void test();
void test_iterator();

#define FT_PAIR(a, b) ft::pair<int, std::string>(a, b)
#define STD_PAIR(a, b) std:pair<int, std::string>(a, b)

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

	ft::map<int, std::string> ft_test1;
	ft_test1.insert(FT_PAIR(42, "Hello"));
	ft_test1.insert(FT_PAIR(10, "World"));
	ft_test1.insert(FT_PAIR(50, "42Tokyo"));
}
