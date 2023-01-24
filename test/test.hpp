#ifndef TEST_HPP_
#define TEST_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <algorithm.hpp>

/* test funcs */
void vector_test();
void stack_test();
void test_type_traits();
void test_node();
void test_avl_tree();
void test_map();

void tester_vector();

void print_time_cmp(double ft, double std, bool ok);
void print_mgn(std::string str);
void print_white(std::string str);
/* color code */
#define RED "\e[31m"
#define GRN "\e[32m"
#define YEL "\e[33m"
#define BLU "\e[34m"
#define MGN "\e[35m"
#define CYN "\e[36m"
#define RES "\e[m"

#endif
