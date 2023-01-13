#include "test.hpp"
#include <vector.hpp>
#include <iostream>
#include <string>

template <typename T>
void print_std_vector(std::vector<T> vec);
template <typename T>
void print_ft_vector(ft::vector<T> vec);
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
	// test();
}

void test() {
	std::vector<int> var1 (6, 42);
	// std::vector<int> var2(15, 10);

	// var1.resize(2, 10);
	print_std_vector(var1);
	std::vector<int>::iterator it = var1.erase(var1.begin() + 1, var1.end());
	std::cout << *it << std::endl;
	// print_std_vector(var1);
	// print_std_vector(var2);
	// var1.swap(var2);
	print_std_vector(var1);
	// print_std_vector(var2);
	std::cout << var1.size() << " " << var1.capacity() << std::endl;
	// std::cout << var2.size() << " " << var2.capacity() << std::endl;
}

void constructor_test() {
	std::cout << YEL << "-------------constructor test-------------" << RES << std::endl;
	//test1 (empty constructor)
	print_mgn("empty constructor");
	ft::vector<int> empty_var_int;
	ft::vector<int *> empty_var_int_p;
	ft::vector<std::string> empty_var_string;
	std::cout << "ok" << std::endl;

	//test2 (fill constructor)
	print_mgn("fill constructor");
	ft::vector<int> var_int(5, 42); // KO
	ft::vector<std::string> var_string(5, "TEST");
	ft::vector<char> var_char(5, 'x');
	print_ft_vector(var_char);
	print_ft_vector(var_string);
	print_ft_vector(var_int);

	//test3 (range constructor)
	print_mgn("range constructor");

	//test4 (copy constructor)
	print_mgn("copy constructor");
	ft::vector<int> ft_4(5, 42);
	ft::vector<int> ft_cp_4 = ft_4;

	print_ft_vector(ft_4);
	print_ft_vector(ft_cp_4);

	//test5 operator=
	ft::vector<std::string> ft_5(5, "42");
	ft::vector<std::string> ft_cp_5;
	ft_cp_5 = ft_5;
	print_mgn("operator=");
	print_ft_vector(ft_5);
	print_ft_vector(ft_cp_5);
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
	std::vector<int> std_1(5, 42);
	ft::vector<int> ft_1(5, 42);

	print_mgn("size() capacity()");
	print_cmp("- size()", ft_1.size(), std_1.size());
	print_cmp("- capacity()", ft_1.capacity(), std_1.capacity());


	print_mgn("resize(n, val)");
	std::vector<std::string> std_2(5, "42");
	ft::vector<std::string> ft_2(5, "42");
	std_2.resize(2, "10");
	ft_2.resize(2, "10");

	print_std_vector(std_2);
	print_ft_vector(ft_2);
	print_cmp("- size()", ft_2.size(), std_2.size());
	print_cmp("- capacity()", ft_2.capacity(), std_2.capacity());
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
	print_mgn("insert(pos, n, val)");

	std::vector<std::string> std_3(5, "42");
	ft::vector<std::string> ft_3(5, "42");
	std::vector <std::string> ::iterator sit_3 = std_3.end();
	ft::vector<std::string>::iterator it_3 = ft_3.end();
	std_3.insert(sit_3, 7, "42");
	ft_3.insert(it_3, 7, "42");
	print_cmp("3. size()", ft_3.size(), std_3.size());
	print_cmp("3. capacity()", ft_3.capacity(), std_3.capacity());

	print_mgn("insert(pos, first, last)");
	std::vector<std::string> std_4(5, "42");
	std::vector<std::string> std_item_4(10, "10");
	ft::vector<std::string> ft_4(5, "42");
	ft::vector<std::string> ft_item_4(10, "10");
	std::vector <std::string> ::iterator sit_4 = std_4.end();
	ft::vector<std::string>::iterator it_4 = ft_4.end();
	std_4.insert(std_4.begin() + 1, std_item_4.begin(), std_item_4.end());
	ft_4.insert(ft_4.begin() + 1, ft_item_4.begin(), ft_item_4.end());

	print_std_vector(std_4);
	print_ft_vector(ft_4);

	print_cmp("4. size()", ft_4.size(), std_4.size());
	print_cmp("4. capacity()", ft_4.capacity(), std_4.capacity());

	//pop_back()
	print_mgn("pop_back()");
	std::vector<int> std_5(5, 42);
	ft::vector<int> ft_5(5, 42);

	std_5.pop_back();
	ft_5.pop_back();
	print_cmp("5. size()", ft_5.size(), std_5.size());
	print_cmp("5. capacity()", ft_5.capacity(), std_5.capacity());

	std::vector<int> std_6;
	ft::vector<int> ft_6;

	std_6.pop_back();
	ft_6.pop_back();
	print_cmp("6. size()", ft_6.size(), std_6.size()); // stdは境界値対策してない
	print_cmp("6. capacity()", ft_6.capacity(), std_6.capacity());

	//push_back()
	print_mgn("push_back()");
	std::vector<int> std_7(5, 42);
	ft::vector<int> ft_7(5, 42);

	std_7.push_back(10);
	ft_7.push_back(10);

	print_std_vector(std_7);
	print_ft_vector(ft_7);

	print_cmp("7. size()", ft_7.size(), std_7.size());
	print_cmp("7. capacity()", ft_7.capacity(), std_7.capacity());

	//assign(n, val)
		print_mgn("assign(n, val)");
	std::vector<std::string> std_8(10, "42");
	ft::vector<std::string> ft_8(10, "42");
	std_8.assign(5, "10");
	ft_8.assign(5, "10");

	print_std_vector(std_8);
	print_ft_vector(ft_8);

	print_cmp("8. size()", ft_8.size(), std_8.size());
	print_cmp("8. capacity()", ft_8.capacity(), std_8.capacity());

	// assign (first, last)
	print_mgn("assign(first, last)");
	std::vector<std::string> std_9(5, "42");
	std::vector<std::string> std_item_9(2, "10");
	ft::vector<std::string> ft_9(5, "42");
	ft::vector<std::string> ft_item_9(2, "10");
	std::vector <std::string> ::iterator sit_9 = std_9.end();
	ft::vector<std::string>::iterator it_9 = ft_9.end();
	std_9.assign(std_item_9.begin(), std_item_9.end());
	ft_9.assign(ft_item_9.begin(), ft_item_9.end());

	print_std_vector(std_9);
	print_ft_vector(ft_9);

	print_cmp("9. size()", ft_9.size(), std_9.size());
	print_cmp("9. capacity()", ft_9.capacity(), std_9.capacity());

	// swap (other)
	print_mgn("swap(other)");
	std::vector<std::string> std_10(5, "42");
	std::vector<std::string> std_item_10(10, "10");
	ft::vector<std::string> ft_10(5, "42");
	ft::vector<std::string> ft_item_10(10, "10");
	std_10.swap(std_item_10);
	ft_10.swap(ft_item_10);

	print_std_vector(std_10);
	print_std_vector(std_item_10);
	print_ft_vector(ft_10);
	print_ft_vector(ft_item_10);

	print_cmp("10. size()", ft_10.size(), std_10.size());
	print_cmp("10. capacity()", ft_10.capacity(), std_10.capacity());

	//erase(pos)
	print_mgn("erase(pos)");
	std::vector<std::string> std_11(5, "42");
	ft::vector<std::string> ft_11(5, "42");

	std::vector<std::string>::iterator sit_11 = std_11.begin() + 3;
	ft::vector<std::string>::iterator it_11 = ft_11.begin() + 3;

	ft_11.erase(it_11);
	std_11.erase(sit_11);

	print_std_vector(std_11);
	print_ft_vector(ft_11);

	print_cmp("11. size()", ft_11.size(), std_11.size());
	print_cmp("11. capacity()", ft_11.capacity(), std_11.capacity());

	//erase(first, end)
	print_mgn("erase(first, end)");
	std::vector<std::string> std_12(5, "42");
	ft::vector<std::string> ft_12(5, "42");

	std::vector<std::string>::iterator sit_12 = std_12.begin() + 1;
	ft::vector<std::string>::iterator it_12 = ft_12.begin() + 1;

	ft_12.erase(it_12, it_12 + 3);
	std_12.erase(sit_12, sit_12 + 3);

	print_std_vector(std_12);
	print_ft_vector(ft_12);

	print_cmp("12. size()", ft_12.size(), std_12.size());
	print_cmp("12. capacity()", ft_12.capacity(), std_12.capacity());
}

template <typename T>
void print_cmp(std::string test_name, T ft_var, T std_var) {
	std::cout << YEL << test_name << RES << std::endl;
	std::cout << "ft: ["<< ft_var << "] std: [" << std_var << "]" << std::endl;
}

void print_mgn(std::string str) {
	std::cout << MGN << str << RES << std::endl;
}

template <typename T>
void print_std_vector(std::vector<T> vec) {
	typename std::vector<T>::iterator begin = vec.begin();
	typename std::vector<T>::iterator end = vec.end();
	std::cout << "std: ";
	for (; begin != end; begin++)
		std::cout << "[" << *begin << "]";
	std::cout << std::endl;
}

template <typename T>
void print_ft_vector(ft::vector<T> vec) {
	typename ft::vector<T>::iterator begin = vec.begin();
	typename ft::vector<T>::iterator end = vec.end();
	std::cout << "ft : ";
	for (; begin != end; begin++)
		std::cout << "[" << *begin << "]";
	std::cout << std::endl;
}
