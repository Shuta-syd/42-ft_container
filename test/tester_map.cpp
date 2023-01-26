#include "test.hpp"
void tester_constructor_map();
void tester_modifiers_map();
void test_map();

#define FT_PAIR(a, b) ft::pair<int, std::string>(a, b)
#define STD_PAIR(a, b) std::pair<int, std::string>(a, b)

void tester_map()
{
	print_white("--------------------------------------------------");
	print_white("|                     Map Test                   |");
	print_white("--------------------------------------------------");

	tester_constructor_map();
	tester_modifiers_map();
	// test_map();
}

void test_map() {
	ft::map<int, std::string> ft_map;

	ft_map.insert(FT_PAIR(1, "42"));
	ft_map.insert(FT_PAIR(2, "42"));
	ft_map.insert(FT_PAIR(3, "42"));
	ft_map.insert(FT_PAIR(4, "42"));
	ft_map.insert(FT_PAIR(5, "42"));
	ft_map.insert(FT_PAIR(6, "42"));
	ft_map.insert(FT_PAIR(7, "42"));

	// ft_map.erase(1);
	ft_map.erase(4);
}

void tester_modifiers_map()
{
	print_white("--------------------------------------------------");
	print_white("|                 Modifiers Test                 |");
	print_white("--------------------------------------------------");
	print_white("========================== insert test ==========================");
	clock_t ft_start = clock();
	for (size_t i = 0; i < 100; i++) {
		ft::map<int, std::string> ft_map;
		for (size_t i = 0; i < 1000; i++)
			ft_map.insert(FT_PAIR(i, "42Tokyo"));
	}
	clock_t ft_end = clock();
	double ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	clock_t std_start = clock();
	for (size_t i = 0; i < 100; i++){
		std::map<int, std::string> std_map;
		for (size_t i = 0; i < 1000; i++)
			std_map.insert(STD_PAIR(i, "42Tokyo"));
	}
	clock_t std_end = clock();
	double std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::map<int, std::string> ft_map;
	for (size_t i = 0; i < 100; i++)
			ft_map.insert(FT_PAIR(i, "42Tokyo"));
	std::map<int, std::string> std_map;
	for (size_t i = 0; i < 100; i++)
			std_map.insert(STD_PAIR(i, "42Tokyo"));
	bool equal = ft::equal_map(ft_map.begin(), ft_map.end(), std_map.begin());
	if (ft_map.size() != std_map.size())
		equal = false;

	print_time_cmp(ft_time, std_time, equal);

	print_white("========================= insert2 test =========================");

	ft_start = clock();
	for (size_t i = 0; i < 100; i++) {
		ft::map<int, std::string> ft_map;
		for (size_t i = 0; i < 1000; i++) {
			ft_map.insert(ft_map.begin(), FT_PAIR(i, "42Tokyo"));
		}
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 100; i++){
		std::map<int, std::string> std_map;
			for (size_t i = 0; i < 1000; i++) {
				std_map.insert(std_map.begin(), STD_PAIR(i, "42Tokyo"));
		}
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::map<int, std::string> ft_map2;
	for (size_t i = 0; i < 100; i++)
		ft_map2.insert(ft_map2.begin(), FT_PAIR(i, "42Tokyo"));
	std::map<int, std::string> std_map2;
	for (size_t i = 0; i < 100; i++)
		std_map2.insert(std_map2.begin(), STD_PAIR(i, "42Tokyo"));
	equal = ft::equal_map(ft_map2.begin(), ft_map2.end(), std_map2.begin());
	if (ft_map2.size() != std_map2.size())
		equal = false;

	print_time_cmp(ft_time, std_time, equal);


	print_white("========================= insert3 test =========================");
	ft::map<int, std::string> ft_map3;
	std::map<int, std::string> std_map3;
	for (size_t i = 0; i < 1000; i++) {
		ft_map3.insert(FT_PAIR(i, "42tokyo"));
		std_map3.insert(STD_PAIR(i, "42tokyo"));
	}

	ft_start = clock();
	for (size_t i = 0; i < 100; i++) {
		ft::map<int, std::string> ft_map;
		ft_map.insert(ft_map3.begin(), ft_map3.end());
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 100; i++){
		std::map<int, std::string> std_map;
		std_map.insert(std_map3.begin(), std_map3.end());
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::map<int, std::string> ft_map4;
	ft_map4.insert(ft_map3.begin(), ft_map3.end());
	std::map<int, std::string> std_map4;
	std_map4.insert(std_map3.begin(), std_map3.end());
	equal = ft::equal_map(ft_map4.begin(), ft_map4.end(), std_map4.begin());
	if (ft_map4.size() != std_map4.size())
		equal = false;

	print_time_cmp(ft_time, std_time, equal);


	print_white("========================= erase test =========================");
	ft::map<int, std::string> ft_map5;
	std::map<int, std::string> std_map5;
	for (size_t i = 0; i < 500; i++) {
		ft_map5.insert(FT_PAIR(i, "42tokyo"));
		std_map5.insert(STD_PAIR(i, "42tokyo"));
	}

	ft_start = clock();
	for (size_t i = 0; i < 100; i++) {
	ft::map<int, std::string> ft_map(ft_map5.begin(), ft_map5.end());
		for (size_t i = 0; i < 500; i++)
			ft_map.erase(i);
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 100; i++){
		std::map<int, std::string> std_map(std_map5.begin(), std_map5.end());
		for (size_t i = 0; i < 500; i++)
			std_map.erase(i);
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::map<int, std::string> ft_map6(ft_map5.begin(), ft_map5.end());
	for (size_t i = 0; i < 100; i++)
		ft_map6.erase(i);
	std::map<int, std::string> std_map6(std_map5.begin(), std_map5.end());
	for (size_t i = 0; i < 100; i++)
		std_map6.erase(i);
	equal = ft::equal_map(ft_map6.begin(), ft_map6.end(), std_map6.begin());
	if (ft_map6.size() != std_map6.size())
		equal = false;

	print_time_cmp(ft_time, std_time, equal);
}


void tester_constructor_map()
{
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
	for (size_t i = 0; i < 50; i++)
	{
		ft_map2.insert(FT_PAIR(i, "42tokyo"));
		std_map2.insert(STD_PAIR(i, "42tokyo"));
	}

	ft_start = clock();
	for (size_t i = 0; i < 100; i++)
		ft::map<int, std::string> ft_map(ft_map2.begin(), ft_map2.end());
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 100; i++)
		std::map<int, std::string> std_map(std_map2.begin(), std_map2.end());
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::map<int, std::string> ft_map3(ft_map2.begin(), ft_map2.end());
	std::map<int, std::string> std_map3(std_map2.begin(), std_map2.end());
	bool equal = ft::equal_map(ft_map3.begin(), ft_map3.end(), std_map3.begin());
	if (ft_map3.size() != std_map3.size())
		equal = false;

	print_time_cmp(ft_time, std_time, equal);

	print_white("==================== copy constructor test ====================");
	ft::map<int, std::string> ft_map4;
	std::map<int, std::string> std_map4;
	for (size_t i = 0; i < 50; i++) {
		ft_map4.insert(FT_PAIR(i, "42tokyo"));
		std_map4.insert(STD_PAIR(i, "42tokyo"));
	}

	ft_start = clock();
	for (size_t i = 0; i < 100; i++)
		ft::map<int, std::string> ft_map(ft_map4);
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 100; i++)
		std::map<int, std::string> std_map(std_map4);
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::map<int, std::string> ft_map5(ft_map4);
	std::map<int, std::string> std_map5(std_map4);
	equal = ft::equal_map(ft_map5.begin(), ft_map5.end(), std_map5.begin());
	if (ft_map5.size() != std_map5.size())
		equal = false;

	print_time_cmp(ft_time, std_time, equal);
}

template <class T1, class T2>
void print_std_map(std::map<T1, T2> test) {
	std::cout << "ft :";
	typename std::map<T1, T2>::iterator it = test.begin();
	for (; it != test.end(); it++) {
		std::cout << "[" << std::setw(1) << std::right << std::setfill(' ') << it->first << "]";
	}
	std::cout << std::endl;
}

template <class T1, class T2>
void print_ft_map(ft::map<T1, T2> test) {
	std::cout << "std:";
	typename ft::map<T1, T2>::iterator it = test.begin();
	for (; it != test.end(); it++) {
		std::cout << "[" << std::setw(1) << std::right << std::setfill(' ') << it->first << "]";
	}
	std::cout << std::endl;
}
