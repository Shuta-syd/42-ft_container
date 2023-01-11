#include "test.hpp"
#include <vector.hpp>
#include <iostream>
#include <string>

template <typename T>
void print_cmp(std::string test_name, T std_var, T ft_var);
void capacity_test();
void iterators_test();
void constructor_test();
void modifier_test();

void vector_test() {
	std::cout << GRN << "-------------ft::vector test start-------------" << RES << std::endl;
	// constructor_test();
	// iterators_test();
	capacity_test();
	// modifier_test();
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
	print_cmp("- iterator base()", random_it.base(), random_sit.base());
	print_cmp("- iterator operator*", *random_it, *random_sit);

	//reverse_iterator
	ft::vector<int>::reverse_iterator reverse_it = ft_int.rbegin();
	std::vector<int>::reverse_iterator reverse_sit = std_int.rbegin();
	print_cmp("- reverse_iterator operator*", *reverse_it, *reverse_sit);

	/**
	 * @brief https://qiita.com/HO-RI9191/items/6f761af23cf5d288cb9e (Linuxだとエラー)
	 */
	ft::vector<const int> ft_const_int(5, 42);
	std::vector<const int> std_const_int(5, 42);

	//const random_iterator
	ft::vector<int>::const_iterator const_random_it = ft_const_int.begin();
	std::vector<int>::const_iterator const_random_sit = std_const_int.begin();
	print_cmp("- const_iterator base()", const_random_it.base(), const_random_sit.base());
	print_cmp("- const_iterator operator*", *const_random_it, *const_random_sit);

	//const reverse_iterator
	ft::vector<int>::const_reverse_iterator const_reverse_it = ft_const_int.rbegin();
	std::vector<int>::const_reverse_iterator const_reverse_sit = std_const_int.rbegin();
	print_cmp("- const_reverse_iterator operator*", *const_reverse_it, *const_reverse_sit);
}


void capacity_test() {
	std::cout << GRN << "-----------------capacity test----------------" << RES << std::endl;
	std::vector<int> std_int(5, 42);
	std::vector<int> ft_int(5, 42);

	print_cmp("- size()", ft_int.size(), std_int.size());
	print_cmp("- capacity()", ft_int.capacity(), std_int.capacity());
}

void modifier_test() {
	std::vector<int> std_int;

	for (size_t i = 0; i < 10; i++)
		std_int.push_back(i);
	std_int.assign(5, 100);
	for (size_t i = 0; i < 10; i++)
		std::cout << std_int[i] << " ";
	std::cout << std::endl;
}

template <typename T>
void print_cmp(std::string test_name, T ft_var, T std_var) {
	std::cout << YEL << test_name << RES << std::endl;
	std::cout << "ft: ["<< ft_var << "] std: [" << std_var << "]" << std::endl;
}
