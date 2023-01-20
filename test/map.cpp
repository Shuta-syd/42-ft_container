#include "test.hpp"
#include <map>
#include <map.hpp>
void test();

void test_map() {
	print_white("--------------------------------------------------");
	print_white("|                      map                       |");
	print_white("--------------------------------------------------");
	test();
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
