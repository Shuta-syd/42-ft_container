#include "test.hpp"
#include <vector.hpp>
void tester_constructor();
void tester_capacity();

void tester_vector() {
	print_white("--------------------------------------------------");
	print_white("|                   Vector Test                  |");
	print_white("--------------------------------------------------");

	tester_constructor();
	tester_capacity();
}

void tester_capacity() {
	print_white("--------------------------------------------------");
	print_white("|                  Capacity Test                 |");
	print_white("--------------------------------------------------");
	print_white("========================== resize test =========================");
	clock_t ft_start = clock();
	for (size_t i = 0; i < 100; i++) {
		ft::vector<int> ft_vec;
		ft_vec.resize(100, 42);
	}
	clock_t ft_end = clock();
	double ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	clock_t std_start = clock();
	for (size_t i = 0; i < 100; i++){
		std::vector<int> std_vec;
		std_vec.resize(100, 42);
	}
	clock_t std_end = clock();
	double std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::vector<int> ft_vec1;
	std::vector<int> std_vec1;
	ft_vec1.resize(100, 42);
	std_vec1.resize(100, 42);
	bool equal = ft::equal(ft_vec1.begin(), ft_vec1.end(), std_vec1.begin());

	print_time_cmp(ft_time, std_time, equal);


	print_white("========================= resize2 test =========================");
	ft_start = clock();
	for (size_t i = 0; i < 100; i++) {
		ft::vector<int> ft_vec(10, 100);
		ft_vec.resize(100, 42);
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 100; i++){
		std::vector<int> std_vec(10, 100);
		std_vec.resize(100, 42);
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::vector<int> ft_vec2(10, 100);
	std::vector<int> std_vec2(10, 100);
	ft_vec2.resize(100, 42);
	std_vec2.resize(100, 42);
	equal = ft::equal(ft_vec2.begin(), ft_vec2.end(), std_vec2.begin());

	print_time_cmp(ft_time, std_time, equal);


	print_white("========================= reserve test =========================");
	ft_start = clock();
	for (size_t i = 0; i < 100; i++) {
		ft::vector<int> ft_vec;
		ft_vec.reserve(1000);
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 100; i++){
		std::vector<int> std_vec(10, 100);
		std_vec.reserve(1000);
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::vector<int> ft_vec3(10, 100);
	std::vector<int> std_vec3(10, 100);
	ft_vec3.reserve(1000);
	std_vec3.reserve(1000);
	equal = ft_vec3.capacity() == std_vec3.capacity() ? true : false;

	print_time_cmp(ft_time, std_time, equal);
}


void tester_constructor() {
	print_white("--------------------------------------------------");
	print_white("|                Constructor Test                |");
	print_white("--------------------------------------------------");


	print_white("==================== empty constructor test ====================");
	clock_t ft_start = clock();
	for (size_t i = 0; i < 100; i++)
		ft::vector<int> ft_vec;
	clock_t ft_end = clock();
	double ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	clock_t std_start = clock();
	for (size_t i = 0; i < 100; i++)
		std::vector<int> std_vec;
	clock_t std_end = clock();
	double std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	print_time_cmp(ft_time, std_time, true);


	print_white("===================== fill constructor test ====================");
	ft_start = clock();
	for (size_t i = 0; i < 100; i++)
		ft::vector<std::string> ft_vec(50, "42Tokyo");
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 100; i++)
		std::vector<std::string> std_vec(50, "42Tokyo");
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::vector<std::string> ft_vec1(50, "42Tokyo");
	std::vector<std::string> std_vec1(50, "42Tokyo");
	bool equal = ft::equal(ft_vec1.begin(), ft_vec1.end(), std_vec1.begin());

	print_time_cmp(ft_time, std_time, equal);


	print_white("==================== range constructor test ====================");
	ft::vector<std::string> ft_vec2(50, "42Tokyo");
	std::vector<std::string> std_vec2(50, "42Tokyo");
	ft_start = clock();
	for (size_t i = 0; i < 100; i++)
		ft::vector<std::string> ft_vec(ft_vec2.begin(), ft_vec2.end());
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 100; i++)
		std::vector<std::string> std_vec(std_vec2.begin(), std_vec2.end());
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::vector<std::string> ft_vec3(ft_vec2.begin(), ft_vec2.end());
	std::vector<std::string> std_vec3(std_vec2.begin(), std_vec2.end());
	equal = ft::equal(ft_vec3.begin(), ft_vec3.end(), std_vec3.begin());

	print_time_cmp(ft_time, std_time, equal);


	print_white("==================== copy constructor test ====================");
	ft::vector<std::string> ft_vec4(50, "42Tokyo");
	std::vector<std::string> std_vec4(50, "42Tokyo");
	ft_start = clock();
	for (size_t i = 0; i < 100; i++)
		ft::vector<std::string> ft_vec(ft_vec4);
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 100; i++)
		std::vector<std::string> std_vec(std_vec4);
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::vector<std::string> ft_vec5(ft_vec4);
	std::vector<std::string> std_vec5(std_vec4);
	equal = ft::equal(ft_vec5.begin(), ft_vec5.end(), std_vec5.begin());

	print_time_cmp(ft_time, std_time, equal);
}
