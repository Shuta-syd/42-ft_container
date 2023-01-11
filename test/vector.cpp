#include "test.hpp"
#include <vector.hpp>
#include <iostream>
#include <string>

template <typename T>
void print_cmp(std::string test_name, T std_var, T ft_var);
void print_mgn(std::string str);
void capacity_test();
void iterators_test();
void constructor_test();
void modifier_test();
void test();

void vector_test() {
	std::cout << GRN << "-------------ft::vector test start-------------" << RES << std::endl;
	// constructor_test();
	// iterators_test();
	// capacity_test();
	modifier_test();
	test();
}

void test() {

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
	ft::vector<int> ft_int(5, 42);

	print_cmp("- size()", ft_int.size(), std_int.size());
	print_cmp("- capacity()", ft_int.capacity(), std_int.capacity());
}

void modifier_test() {
	//insert(pos, val)
	print_mgn("insert(pos, val)");
	std::vector<int> std_1;
	ft::vector<int> ft_1;

	std::vector<int>::iterator sit_1 = std_1.begin();
	ft::vector<int>::iterator it_1 = ft_1.begin();
	std_1.insert(sit_1, 42);
	ft_1.insert(it_1, 42);
	print_cmp("1. size()", ft_1.size(), std_1.size());
	print_cmp("1. capacity()", ft_1.capacity(), std_1.capacity());

	std::vector<int> std_2(5, 42);
	ft::vector<int> ft_2(5, 42);

	std::vector<int>::iterator sit_2 = std_2.end();
	ft::vector<int>::iterator it_2 = ft_2.end();
	std_2.insert(sit_2, 42);
	ft_2.insert(it_2, 42);
	print_cmp("2. size()", ft_2.size(), std_2.size());
	print_cmp("2. capacity()", ft_2.capacity(), std_2.capacity());

	//insert(pos, n, val)
		std::vector<int> std_3(5, 42);
	ft::vector<int> ft_3(5, 42);

	print_mgn("insert(pos, n, val)");
	std::vector<int>::iterator sit_3 = std_3.end();
	ft::vector<int>::iterator it_3 = ft_3.end();
	std_3.insert(sit_3, 7, 42);
	ft_3.insert(it_3, 7, 42);
	print_cmp("3. size()", ft_3.size(), std_3.size());
	print_cmp("3. capacity()", ft_3.capacity(), std_3.capacity());

	//pop_back()
	print_mgn("pop_back()");
	std::vector<int> std_4(5, 42);
	ft::vector<int> ft_4(5, 42);

	std_4.pop_back();
	ft_4.pop_back();
	print_cmp("4. size()", ft_4.size(), std_4.size());
	print_cmp("4. capacity()", ft_4.capacity(), std_4.capacity());

	std::vector<int> std_5;
	ft::vector<int> ft_5;

	std_5.pop_back();
	ft_5.pop_back();
	print_cmp("5. size()", ft_5.size(), std_5.size()); // stdは境界値対策してない
	print_cmp("5. capacity()", ft_5.capacity(), std_5.capacity());
}

template <typename T>
void print_cmp(std::string test_name, T ft_var, T std_var) {
	std::cout << YEL << test_name << RES << std::endl;
	std::cout << "ft: ["<< ft_var << "] std: [" << std_var << "]" << std::endl;
}

void print_mgn(std::string str) {
	std::cout << MGN << str << RES << std::endl;
}
