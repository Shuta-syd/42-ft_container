#include "test.hpp"
#include <vector.hpp>
#include <iostream>
#include <string>

void iterators_test();
void constructor_test();

void vector_test() {
	std::cout << GRN << "-------------ft::vector test start-------------" << RES << std::endl;
	// constructor_test();
	iterators_test();
}

void constructor_test() {
	std::cout << YEL << "-------------constructor test-------------" << RES << std::endl;
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
	std::cout << GRN << "-----------------iterator test----------------" << RES << std::endl;
	ft::vector<int> ft_int(5, 42);
	std::vector<int> std_int(5, 42);

	//random_iterator
	ft::vector<int>::iterator random_it = ft_int.begin();
	std::vector<int>::iterator random_sit = std_int.begin();
	std::cout << YEL << "- _iterator base()" << RES << std::endl;
	std::cout << "ft: ["<< random_it.base() << "] std: [" << random_sit.base() << "]" << std::endl;
	std::cout << YEL << "- _iterator operator*" << RES << std::endl;
	std::cout << "ft: ["<< *random_it << "] std: [" << *random_sit << "]" << std::endl;

	//reverse_iterator
	ft::vector<int>::reverse_iterator reverse_it = ft_int.rbegin();
	std::vector<int>::reverse_iterator reverse_sit = std_int.rbegin();
	std::cout << YEL << "- reverse_iterator operator*" << RES << std::endl;
	std::cout << "ft: ["<< *reverse_it << "] std: [" << *reverse_sit << "]" << std::endl;
}
