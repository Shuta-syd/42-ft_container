#include "test.hpp"
#include <vector.hpp>
#include <iostream>
#include <string>

void iterators_test();
void constructor_test();

void vector_test() {
	std::cout << YEL << "-------------ft::vector test start-------------" << RES << std::endl;
	// constructor_test();
	iterators_test();
}

void constructor_test() {
	//test1 (empty constructor)
	ft::vector<int> empty_var_int;
	ft::vector<int *> empty_var_int_p;
	ft::vector<std::string> empty_var_string;

	//test2 (fill constructor)
	ft::vector<int> var_int(5, 42); // KO
	ft::vector<std::string> var_string(5, "TEST");
	ft::vector<char> var_char(5, 'x');

	//test3 (range constructor)

}

void iterators_test() {
	ft::vector<int> ft_int(5, 42);
	std::vector<int> std_int(5, 42);

	ft::vector<int>::iterator it = ft_int.begin();
	std::vector<int>::iterator sit = std_int.begin();
	std::cout << "- iterator.base()" << std::endl;
	std::cout << "ft: [" << it.base() << "] std: [" << sit.base() << "]" << std::endl;
	std::cout << "ft: ["<< *it << "] std: [" << *sit << "]" << std::endl;
}
