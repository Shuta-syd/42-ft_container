#ifndef TEST_HPP_
#define TEST_HPP_

#include <iostream>
#include <string>
#include <time.h>
#include <algorithm.hpp>
#include <map>
#include <vector>
#include <map.hpp>
#include <vector.hpp>

/* test funcs */
void tester_map();
void tester_vector();
void test_avl_tree();

void print_time_cmp(double ft, double std, bool ok);
void print_mgn(std::string str);
void print_yel(std::string str);
void print_white(std::string str);
template <typename T>
void print_std_vector(std::vector<T> vec);
template <typename T>
void print_ft_vector(ft::vector<T> vec);
template <class T1, class T2>
void print_std_map(std::map<T1, T2> test);
template <class T1, class T2>
void print_ft_map(ft::map<T1, T2> test) ;

/* color code */
#define RED "\033[31m"
#define GRN "\033[32m"
#define YEL "\033[33m"
#define BLU "\033[34m"
#define MGN "\033[35m"
#define CYN "\033[36m"
#define RES "\033[m"

#endif
