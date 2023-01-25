#include "test.hpp"
void tester_constructor();
void tester_capacity();
void tester_modifiers();

void tester_vector() {
	print_white("--------------------------------------------------");
	print_white("|                   Vector Test                  |");
	print_white("--------------------------------------------------");

	tester_constructor();
	tester_capacity();
	tester_modifiers();
}

void tester_modifiers() {
	print_white("--------------------------------------------------");
	print_white("|                 Modifiers Test                 |");
	print_white("--------------------------------------------------");
	print_white("========================== assign test =========================");
	clock_t ft_start = clock();
	for (size_t i = 0; i < 100; i++) {
		ft::vector<int> ft_vec;
		ft_vec.assign(1000, 42);
	}
	clock_t ft_end = clock();
	double ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	clock_t std_start = clock();
	for (size_t i = 0; i < 100; i++){
		std::vector<int> std_vec;
		std_vec.assign(1000, 42);
	}
	clock_t std_end = clock();
	double std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::vector<int> ft_vec1;
	std::vector<int> std_vec1;
	ft_vec1.assign(1000, 42);
	std_vec1.assign(1000, 42);
	bool equal = ft::equal(ft_vec1.begin(), ft_vec1.end(), std_vec1.begin());
	if (ft_vec1.size() != std_vec1.size())
		equal = false;

	print_time_cmp(ft_time, std_time, equal);


	print_white("========================= assign2 test =========================");
	ft::vector<std::string> ft_vec2(1000, "42Tokyo");
	ft_start = clock();
	for (size_t i = 0; i < 100; i++) {
		ft::vector<std::string> ft_vec;
		ft_vec.assign(ft_vec2.begin(), ft_vec2.end());
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std::vector<std::string> std_vec2(1000, "42Tokyo");
	std_start = clock();
	for (size_t i = 0; i < 100; i++){
		std::vector<std::string> std_vec;
		std_vec.assign(std_vec2.begin(), std_vec2.end());
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::vector<std::string> ft_vec3;
	std::vector<std::string> std_vec3;
	ft_vec3.assign(ft_vec2.begin(), ft_vec2.end());
	std_vec3.assign(std_vec2.begin(), std_vec2.end());
	equal = ft::equal(ft_vec3.begin(), ft_vec3.end(), std_vec3.begin());
	if (ft_vec3.size() != std_vec3.size())
		equal = false;

	print_time_cmp(ft_time, std_time, equal);


	print_white("======================== push_back test ========================");
	ft_start = clock();
	for (size_t i = 0; i < 100; i++) {
		ft::vector<std::string> ft_vec;
		for (size_t i = 0; i < 500; i++)
			ft_vec.push_back("42");
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 100; i++){
		std::vector<std::string> std_vec;
		for (size_t i = 0; i < 500; i++)
			std_vec.push_back("42");
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::vector<std::string> ft_vec4;
	for (size_t i = 0; i < 100; i++)
			ft_vec4.push_back("42");
	std::vector<std::string> std_vec4;
	for (size_t i = 0; i < 100; i++)
			std_vec4.push_back("42");
	equal = ft::equal(ft_vec4.begin(), ft_vec4.end(), std_vec4.begin());
	if (ft_vec4.size() != std_vec4.size())
		equal = false;
	print_time_cmp(ft_time, std_time, equal);


	print_white("========================= pop_back test =========================");
	ft_start = clock();
	for (size_t i = 0; i < 100; i++) {
		ft::vector<std::string> ft_vec(1000, "42tokyo");
		for (size_t i = 0; i < 1000; i++)
			ft_vec.pop_back();
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 1000; i++){
		std::vector<std::string> std_vec(1000, "42tokyo");
		for (size_t i = 0; i < 1000; i++)
			std_vec.pop_back();
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::vector<std::string> ft_vec5(100, "42Tokyo");
	for (size_t i = 0; i < 100; i++)
			ft_vec5.pop_back();
	std::vector<std::string> std_vec5(100, "42Tokyo");
	for (size_t i = 0; i < 100; i++)
			std_vec5.pop_back();
	equal = ft::equal(ft_vec5.begin(), ft_vec5.end(), std_vec5.begin());
	if (ft_vec5.size() != std_vec5.size())
		equal = false;

	print_time_cmp(ft_time, std_time, equal);


	print_white("========================== insert test ==========================");
	ft_start = clock();
	for (size_t i = 0; i < 100; i++) {
		ft::vector<std::string> ft_vec(5, "tokyo");
		for (size_t i = 0; i < 1000; i++)
			ft_vec.insert(ft_vec.begin() + 3, "42");
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 100; i++){
		std::vector<std::string> std_vec(5, "tokyo");
		for (size_t i = 0; i < 1000; i++)
			std_vec.insert(std_vec.begin() + 3, "42");
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::vector<std::string> ft_vec6(5, "tokyo");
	for (size_t i = 0; i < 100; i++)
			ft_vec6.insert(ft_vec6.begin() + 3, "42");
	std::vector<std::string> std_vec6(5, "tokyo");
	for (size_t i = 0; i < 100; i++)
			std_vec6.insert(std_vec6.begin() + 3, "42");
	equal = ft::equal(ft_vec6.begin(), ft_vec6.end(), std_vec6.begin());
	if (ft_vec6.size() != std_vec6.size())
		equal = false;

	print_time_cmp(ft_time, std_time, equal);


	print_white("========================== insert2 test =========================");
	ft_start = clock();
	for (size_t i = 0; i < 100; i++) {
		ft::vector<std::string> ft_vec(5, "tokyo");
		ft_vec.insert(ft_vec.begin() + 3, 100, "42");
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 100; i++){
		std::vector<std::string> std_vec(5, "tokyo");
		std_vec.insert(std_vec.begin() + 3, 100, "42");
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::vector<std::string> ft_vec7(5, "tokyo");
	ft_vec7.insert(ft_vec7.begin() + 3, 100, "42");
	std::vector<std::string> std_vec7(5, "tokyo");
	std_vec7.insert(std_vec7.begin() + 3, 100, "42");
	equal = ft::equal(ft_vec7.begin(), ft_vec7.end(), std_vec7.begin());
	if (ft_vec7.size() != std_vec7.size())
		equal = false;

	print_time_cmp(ft_time, std_time, equal);


	print_white("========================== insert3 test =========================");
	ft_start = clock();
	ft::vector<std::string> ft_vec8(100, "42");
	for (size_t i = 0; i < 100; i++) {
		ft::vector<std::string> ft_vec(5, "tokyo");
		ft_vec.insert(ft_vec.begin() + 3, ft_vec8.begin(), ft_vec8.end());
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	std::vector<std::string> std_vec8(100, "42");
	for (size_t i = 0; i < 100; i++){
		std::vector<std::string> std_vec(5, "tokyo");
		std_vec.insert(std_vec.begin() + 3, std_vec8.begin(), std_vec8.end());
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::vector<std::string> ft_vec9(5, "tokyo");
	ft_vec9.insert(ft_vec9.begin(), ft_vec8.begin(), ft_vec8.end());
	std::vector<std::string> std_vec9(5, "tokyo");
	std_vec9.insert(std_vec9.begin(), std_vec8.begin(), std_vec8.end());

	equal = ft::equal(ft_vec9.begin(), ft_vec9.end(), std_vec9.begin());
	if (ft_vec9.size() != std_vec9.size())
		equal = false;

	print_time_cmp(ft_time, std_time, equal);

	print_white("=========================== erase test ==========================");
	ft_start = clock();
	for (size_t i = 0; i < 100; i++) {
		ft::vector<std::string> ft_vec(1000, "tokyo");
		for (size_t i = 0; i < 1000; i++) {
			ft_vec.erase(ft_vec.begin());
		}
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 100; i++){
		std::vector<std::string> std_vec(1000, "tokyo");
		for (size_t i = 0; i < 1000; i++)
			std_vec.erase(std_vec.begin());
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::vector<std::string> ft_vec10(100, "tokyo");
	for (size_t i = 0; i < 50; i++)
		ft_vec10.erase(ft_vec10.begin());
	std::vector<std::string> std_vec10(100, "tokyo");
		for (size_t i = 0; i < 50; i++)
		std_vec10.erase(std_vec10.begin());

	equal = ft::equal(ft_vec10.begin(), ft_vec10.end(), std_vec10.begin());
	if (ft_vec10.size() != std_vec10.size())
		equal = false;
	print_time_cmp(ft_time, std_time, equal);

	print_white("=========================== erase2 test =========================");
	ft_start = clock();
	for (size_t i = 0; i < 100; i++) {
		ft::vector<std::string> ft_vec(100, "tokyo");
		ft_vec.erase(ft_vec.begin(), ft_vec.end() - 10);
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 100; i++){
		std::vector<std::string> std_vec(100, "tokyo");
		std_vec.erase(std_vec.begin(), std_vec.end() - 10);
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::vector<std::string> ft_vec11(100, "tokyo");
	ft_vec11.erase(ft_vec11.begin(), ft_vec11.end() - 10);
	std::vector<std::string> std_vec11(100, "tokyo");
	std_vec11.erase(std_vec11.begin(), std_vec11.end() - 10);
	equal = ft::equal(ft_vec11.begin(), ft_vec11.end(), std_vec11.begin());
	if (ft_vec11.size() != std_vec11.size())
		equal = false;

	print_time_cmp(ft_time, std_time, equal);
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
