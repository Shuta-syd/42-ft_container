#include "test.hpp"
#include <vector.hpp>
#include <iostream>
#include <string>


void constructor_test();

void vector_test() {
	std::cout << YEL << "-------------ft::vector test start-------------" << RES << std::endl;
	constructor_test();
}

void constructor_test() {
	//test1
	ft::vector<int> empty_var_int;
	ft::vector<int *> empty_var_int_p;
	ft::vector<std::string> empty_var_string;

	//test2
	ft::vector<int> var_int(5, 2);
	ft::vector<std::string> var_string(5, "TEST");
	ft::vector<char> var_char(5, 'x');
}
