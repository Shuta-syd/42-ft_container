#include "test.hpp"
void tester_constructor_map();
void tester_capacity_map();
void tester_modifiers_map();

#define FT_PAIR(a, b) ft::pair<int, std::string>(a, b)
#define STD_PAIR(a, b) std::pair<int, std::string>(a, b)

void tester_map() {
	print_white("--------------------------------------------------");
	print_white("|                     Map Test                   |");
	print_white("--------------------------------------------------");

	tester_constructor_map();
	tester_capacity_map();
	tester_modifiers_map();
}

void tester_modifiers_map() {
	print_white("--------------------------------------------------");
	print_white("|                 Modifiers Test                 |");
	print_white("--------------------------------------------------");

}

void tester_capacity_map() {
	print_white("--------------------------------------------------");
	print_white("|                  Capacity Test                 |");
	print_white("--------------------------------------------------");
}

void tester_constructor_map() {
	print_white("--------------------------------------------------");
	print_white("|                Constructor Test                |");
	print_white("--------------------------------------------------");
	print_white("==================== empty constructor test ====================");
	clock_t ft_start = clock();
	for (size_t i = 0; i < 100; i++)
		ft::map<int, std::string> ft_map;
	clock_t ft_end = clock();
	double ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	clock_t std_start = clock();
	for (size_t i = 0; i < 100; i++)
		std::map<int, std::string> std_map;
	clock_t std_end = clock();
	double std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	print_time_cmp(ft_time, std_time, true);


	print_white("==================== range constructor test ====================");
	ft::map<int, std::string> ft_map2;
	std::map<int, std::string> std_map2;
	for (size_t i = 0; i < 50; i++) {
		ft_map2.insert(FT_PAIR(i, "42tokyo"));
		std_map2.insert(STD_PAIR(i, "42tokyo"));
	}

	ft_start = clock();
	for (size_t i = 0; i < 100; i++)
		ft::map<int, std::string> ft_vec(ft_map2.begin(), ft_map2.end());
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 100; i++)
		std::map<int, std::string> std_vec(std_map2.begin(), std_map2.end());
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::map<int, std::string> ft_map3(ft_map2.begin(), ft_map2.end());
	std::map<int, std::string> std_map3(std_map2.begin(), std_map2.end());
	print_ft_map(ft_map3);
	print_std_map(std_map3);
	bool equal = ft::equal_map(ft_map3.begin(), ft_map3.end(), std_map3.begin());

	print_time_cmp(ft_time, std_time, equal);
}

template <class T1, class T2>
void print_std_map(std::map<T1, T2> test) {

		std::cout << "ft :";
		typename std::map<T1, T2>::iterator it = test.begin();
		for (; it != test.end(); it++) {
			std::cout << "[" << std::setw(2) << std::right << std::setfill(' ') << it->first << "]";
	}
	std::cout << std::endl;
}

template <class T1, class T2>
void print_ft_map(ft::map<T1, T2> test) {

		std::cout << "std:";
		typename ft::map<T1, T2>::iterator it = test.begin();
		for (; it != test.end(); it++) {
			std::cout << "[" << std::setw(2) << std::right << std::setfill(' ') << it->first << "]";
	}
	std::cout << std::endl;
}
