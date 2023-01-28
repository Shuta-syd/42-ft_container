#include "test.hpp"
void tester_constructor_vec();
void tester_element_access_vec();
void tester_capacity_vec();
void tester_modifiers_vec();
void tester_operator();
void tester_iterator_vec();
void mini_vec_test();

void tester_vector() {
	print_yel("--------------------------------------------------");
	print_yel("|                   Vector Test                  |");
	print_yel("--------------------------------------------------");

	tester_constructor_vec();
	tester_iterator_vec();
	tester_element_access_vec();
	tester_capacity_vec();
	tester_modifiers_vec();
	tester_operator();

	// mini_vec_test();
}

void mini_vec_test() {
	print_white("========================== insert test ==========================");
	clock_t ft_start = clock();
	std::cout << "1" << std::endl;
	for (size_t i = 0; i < 100; i++) {
	ft::vector<std::string> ft_vec(5, "tokyo");
		for (size_t i = 0; i < 1000; i++)
			ft_vec.insert(ft_vec.begin() + 3, "42");
	}
	std::cout << "2" << std::endl;
	clock_t ft_end = clock();
	double ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std::cout << "3" << std::endl;
	clock_t std_start = clock();
	for (size_t i = 0; i < 100; i++){
		std::vector<std::string> std_vec(5, "tokyo");
		for (size_t i = 0; i < 1000; i++)
			std_vec.insert(std_vec.begin() + 3, "42");
	}
	clock_t std_end = clock();
	double std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	std::cout << "4" << std::endl;
	ft::vector<std::string> ft_vec6(5, "tokyo");
	for (size_t i = 0; i < 100; i++)
			ft_vec6.insert(ft_vec6.begin() + 3, "42");
	std::cout << "5" << std::endl;
	std::vector<std::string> std_vec6(5, "tokyo");
	for (size_t i = 0; i < 100; i++)
			std_vec6.insert(std_vec6.begin() + 3, "42");
	std::cout << "6" << std::endl;
	bool equal = ft::equal(ft_vec6.begin(), ft_vec6.end(), std_vec6.begin());
	if (ft_vec6.size() != std_vec6.size())
		equal = false;

	print_time_cmp(ft_time, std_time, equal);
}

void tester_iterator_vec() {
	print_white("--------------------------------------------------");
	print_white("|                  iterator Test                 |");
	print_white("--------------------------------------------------");
	print_white("================== random access iterator test ==================");
	ft::vector<int> ft_map;
	std::vector<int> std_map;
	for (size_t i = 0; i < 1001; i++) {
		ft_map.push_back(i);
		std_map.push_back(i);
	}

	clock_t ft_start = clock();
	for (size_t i = 0; i < 1000; i++) {
		ft::vector<int> ft_map_(ft_map.begin(), ft_map.end());
		ft::vector<int>::iterator rit = ft_map_.begin();
		ft::vector<int>::iterator rit_end = ft_map_.end();
		for (; rit != rit_end; rit++) ;
	}
	clock_t ft_end = clock();
	double ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	clock_t std_start = clock();
	for (size_t i = 0; i < 1000; i++){
		std::vector<int> std_map_(std_map.begin(), std_map.end());
		std::vector<int>::iterator rit = std_map_.begin();
		std::vector<int>::iterator rit_end = std_map_.end();
		for (; rit != rit_end; rit++) ;
	}
	clock_t std_end = clock();
	double std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::vector<int> ft_map2(ft_map.begin(), ft_map.end());
	std::vector<int> std_map2(std_map.begin(), std_map.end());
	bool equal = ft::equal(ft_map2.begin(), ft_map2.end(), std_map2.begin());
	print_time_cmp(ft_time, std_time, equal);


	print_white("===================== reverse iterator test =====================");
	ft::vector<int> ft_map4;
	std::vector<int> std_map4;
	for (size_t i = 0; i < 1001; i++) {
		ft_map4.push_back(i);
		std_map4.push_back(i);
	}

	ft_start = clock();
	for (size_t i = 0; i < 1000; i++) {
		ft::vector<int> ft_map4_(ft_map4.begin(), ft_map4.end());
		ft::vector<int>::reverse_iterator rit = ft_map4_.rbegin();
		ft::vector<int>::reverse_iterator rit_end = ft_map4_.rend();
		for (; rit != rit_end; rit++) ;
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 1000; i++){
		std::vector<int> std_map4_(std_map4.begin(), std_map4.end());
		std::vector<int>::reverse_iterator rit = std_map4_.rbegin();
		std::vector<int>::reverse_iterator rit_end = std_map4_.rend();
		for (; rit != rit_end; rit++) ;
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::vector<int> ft_map3(ft_map4.begin(), ft_map4.end());
	std::vector<int> std_map3(std_map.begin(), std_map.end());
	// std::cout << *ft_map3.rend() << std::endl;
	// std::cout << *_map3.rend() << std::endl;
	equal = ft::equal(ft_map3.rbegin(), ft_map3.rend(), std_map3.rbegin());
	print_time_cmp(ft_time, std_time, equal);
}

void tester_operator() {
	print_white("--------------------------------------------------");
	print_white("|                  operator Test                 |");
	print_white("--------------------------------------------------");
	print_white("======================= operator== test ========================");
	ft::vector<int> ft_vec2;
	std::vector<int> std_vec2;
	for (size_t i = 0; i < 1001; i++) {
		ft_vec2.push_back(i);
		std_vec2.push_back(i);
	}

	clock_t ft_start = clock();
	for (size_t i = 0; i < 100; i++) {
		ft::vector<int> ft_vec(ft_vec2);
		if (ft_vec == ft_vec2)
			continue;
	}
	clock_t ft_end = clock();
	double ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	clock_t std_start = clock();
	for (size_t i = 0; i < 100; i++){
		std::vector<int> std_vec(std_vec2);
		if (std_vec == std_vec2)
			continue;
	}
	clock_t std_end = clock();
	double std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::vector<int> ft_vec3(ft_vec2);
	std::vector<int> std_vec3(std_vec2);
	bool equal = false;
	if (ft_vec2 == ft_vec3)
			equal = true;

	print_time_cmp(ft_time, std_time, equal);

	print_white("======================= operator!= test ========================");
	ft::vector<int> ft_vec4;
	std::vector<int> std_vec4;
	for (size_t i = 0; i < 1001; i++) {
		ft_vec4.push_back(i);
		std_vec4.push_back(i);
	}

	ft_start = clock();
	for (size_t i = 0; i < 100; i++) {
		ft::vector<int> ft_vec(ft_vec4.begin(), ft_vec4.end() - 5);
		if (ft_vec != ft_vec4)
			continue;
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 100; i++){
		std::vector<int> std_vec(std_vec4.begin(), std_vec4.end() - 5);
		if (std_vec != std_vec4)
			continue;
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::vector<int> ft_vec5(ft_vec4.begin(), ft_vec4.end() - 5);
	std::vector<int> std_vec5(std_vec4.begin(), std_vec4.end() - 5);
	equal = false;
	if (ft_vec5 != ft_vec4)
			equal = true;

	print_time_cmp(ft_time, std_time, equal);


	print_white("====================== operator < test ========================");
	ft::vector<int> ft_vec6;
	std::vector<int> std_vec6;
	for (size_t i = 0; i < 1001; i++) {
		ft_vec6.push_back(i);
		std_vec6.push_back(i);
	}

	ft_start = clock();
	for (size_t i = 0; i < 100; i++) {
		ft::vector<int> ft_vec(ft_vec6.begin(), ft_vec6.end() - 5);
		if (ft_vec < ft_vec6)
			continue;
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 100; i++){
		std::vector<int> std_vec(std_vec6.begin(), std_vec6.end() - 5);
		if (std_vec < std_vec6)
			continue;
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::vector<int> ft_vec7(ft_vec6.begin(), ft_vec6.end() - 5);
	std::vector<int> std_vec7(std_vec6.begin(), std_vec6.end() - 5);
	equal = false;
	if (ft_vec7 < ft_vec6)
			equal = true;

	print_time_cmp(ft_time, std_time, equal);

	print_white("====================== operator > test ========================");
	ft::vector<int> ft_vec8;
	std::vector<int> std_vec8;
	for (size_t i = 0; i < 1001; i++) {
		ft_vec8.push_back(i);
		std_vec8.push_back(i);
	}

	ft_start = clock();
	for (size_t i = 0; i < 100; i++) {
		ft::vector<int> ft_vec(ft_vec8.begin(), ft_vec8.end() - 5);
		if (!(ft_vec > ft_vec8))
			continue;
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 100; i++){
		std::vector<int> std_vec(std_vec8.begin(), std_vec8.end() - 5);
		if (!(std_vec > std_vec8))
			continue;
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::vector<int> ft_vec9(ft_vec8.begin(), ft_vec8.end());
	ft_vec9.push_back(10000);
	equal = false;
	if (ft_vec9 > ft_vec8)
			equal = true;

	print_time_cmp(ft_time, std_time, equal);

	print_white("====================== operator <= test ========================");
	ft::vector<int> ft_vec10;
	std::vector<int> std_vec10;
	for (size_t i = 0; i < 1001; i++) {
		ft_vec10.push_back(i);
		std_vec10.push_back(i);
	}

	ft_start = clock();
	for (size_t i = 0; i < 100; i++) {
		ft::vector<int> ft_vec(ft_vec10.begin(), ft_vec10.end());
		if (ft_vec <= ft_vec10)
			continue;
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 100; i++){
		std::vector<int> std_vec(std_vec10.begin(), std_vec10.end());
		if (!(std_vec <= std_vec10))
			continue;
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::vector<int> ft_vec11(ft_vec10.begin(), ft_vec10.end());
	equal = false;
	if (ft_vec11 <= ft_vec10)
			equal = true;

	print_time_cmp(ft_time, std_time, equal);

	print_white("====================== operator >= test ========================");
	ft::vector<int> ft_vec12;
	std::vector<int> std_vec12;
	for (size_t i = 0; i < 1001; i++) {
		ft_vec12.push_back(i);
		std_vec12.push_back(i);
	}

	ft_start = clock();
	for (size_t i = 0; i < 100; i++) {
		ft::vector<int> ft_vec(ft_vec12.begin(), ft_vec12.end());
		if (ft_vec >= ft_vec12)
			continue;
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 100; i++){
		std::vector<int> std_vec(std_vec12.begin(), std_vec12.end());
		if (!(std_vec >= std_vec12))
			continue;
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::vector<int> ft_vec13(ft_vec12.begin(), ft_vec12.end());
	equal = false;
	if (ft_vec13 >= ft_vec12)
			equal = true;

	print_time_cmp(ft_time, std_time, equal);
}


void tester_element_access_vec() {
	print_white("--------------------------------------------------");
	print_white("|              element_access Test               |");
	print_white("--------------------------------------------------");
	print_white("======================= operator[] test ========================");
	ft::vector<int> ft_vec2;
	std::vector<int> std_vec2;
	for (size_t i = 0; i < 1001; i++) {
		ft_vec2.push_back(i);
		std_vec2.push_back(i);
	}

	clock_t ft_start = clock();
	for (size_t i = 0; i < 100; i++) {
		ft::vector<int> ft_vec(ft_vec2);
		for (size_t i = 0; i < 1000; i++) {
			ft_vec[i];
		}
	}
	clock_t ft_end = clock();
	double ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	clock_t std_start = clock();
	for (size_t i = 0; i < 100; i++){
		std::vector<int> std_vec(std_vec2);
		for (size_t i = 0; i < 1000; i++)
			std_vec[i];
	}
	clock_t std_end = clock();
	double std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::vector<int> ft_vec3(ft_vec2);
	std::vector<int> std_vec3(std_vec2);
	bool equal = true;
	for (size_t i = 0; i < 1000; i++) {
		if (ft_vec3[i] != std_vec3[i])
			equal = false;
	}
	if (ft_vec3.size() != std_vec3.size())
		equal = false;

	print_time_cmp(ft_time, std_time, equal);


	print_white("=========================== at test ============================");
	ft::vector<int> ft_vec4;
	std::vector<int> std_vec4;
	for (size_t i = 0; i < 1001; i++) {
		ft_vec4.push_back(i);
		std_vec4.push_back(i);
	}

	ft_start = clock();
	for (size_t i = 0; i < 100; i++) {
		ft::vector<int> ft_vec(ft_vec4);
		for (size_t i = 0; i < 1000; i++) {
			ft_vec.at(i);
		}
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 100; i++){
		std::vector<int> std_vec(std_vec4);
		for (size_t i = 0; i < 1000; i++)
			std_vec.at(i);
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::vector<int> ft_vec5(ft_vec4);
	std::vector<int> std_vec5(std_vec4);
	equal = true;
	for (size_t i = 0; i < 1000; i++) {
		if (ft_vec5.at(i) != std_vec5.at(i))
			equal = false;
	}
	if (ft_vec5.size() != std_vec5.size())
		equal = false;

	print_time_cmp(ft_time, std_time, equal);


	print_white("========================= front test ===========================");
	ft::vector<int> ft_vec6;
	std::vector<int> std_vec6;
	for (size_t i = 0; i < 1001; i++) {
		ft_vec6.push_back(i);
		std_vec6.push_back(i);
	}

	ft_start = clock();
	for (size_t i = 0; i < 100; i++) {
		ft::vector<int> ft_vec(ft_vec6);
		for (size_t i = 0; i < 1000; i++) {
			ft_vec.front();
		}
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 100; i++){
		std::vector<int> std_vec(std_vec6);
		for (size_t i = 0; i < 1000; i++)
			std_vec.front();
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::vector<int> ft_vec7(ft_vec6);
	std::vector<int> std_vec7(std_vec6);
	equal = true;
	for (size_t i = 0; i < 1000; i++) {
		if (ft_vec7.front() != std_vec7.front())
			equal = false;
		ft_vec7.pop_back();
		std_vec7.pop_back();
	}

	print_time_cmp(ft_time, std_time, equal);


	print_white("========================== back test ===========================");
	ft::vector<int> ft_vec8;
	std::vector<int> std_vec8;
	for (size_t i = 0; i < 1001; i++) {
		ft_vec8.push_back(i);
		std_vec8.push_back(i);
	}

	ft_start = clock();
	for (size_t i = 0; i < 100; i++) {
		ft::vector<int> ft_vec(ft_vec8);
		for (size_t i = 0; i < 1000; i++) {
			ft_vec.back();
		}
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 100; i++){
		std::vector<int> std_vec(std_vec8);
		for (size_t i = 0; i < 1000; i++)
			std_vec.back();
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::vector<int> ft_vec9(ft_vec8);
	std::vector<int> std_vec9(std_vec8);
	equal = true;
	for (size_t i = 0; i < 1000; i++) {
		if (ft_vec9.back() != std_vec9.back())
			equal = false;
		ft_vec9.pop_back();
		std_vec9.pop_back();
	}

	print_time_cmp(ft_time, std_time, equal);

	print_white("========================== data test ===========================");
	ft::vector<int> ft_vec10;
	std::vector<int> std_vec10;
	for (size_t i = 0; i < 1001; i++) {
		ft_vec10.push_back(i);
		std_vec10.push_back(i);
	}

	ft_start = clock();
	for (size_t i = 0; i < 100; i++) {
		ft::vector<int> ft_vec(ft_vec10);
		for (size_t i = 0; i < 1000; i++) {
			ft_vec.data();
		}
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 100; i++){
		std::vector<int> std_vec(std_vec10);
		for (size_t i = 0; i < 1000; i++)
			std_vec.data();
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::vector<int> ft_vec11(ft_vec10);
	std::vector<int> std_vec11(std_vec10);
	equal = true;
	for (size_t i = 0; i < 1000; i++) {
		if (ft_vec11.data()[i] != std_vec11.data()[i])
			equal = false;
		ft_vec11.pop_back();
		std_vec11.pop_back();
	}

	print_time_cmp(ft_time, std_time, equal);
}

void tester_modifiers_vec() {
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

	print_white("========================== clear test ==========================");
	ft::vector<int> ft_vec12;
	std::vector<int> std_vec12;
	for (size_t i = 0; i < 1001; i++) {
		ft_vec12.push_back(i);
		std_vec12.push_back(i);
	}

	ft_start = clock();
	for (size_t i = 0; i < 100; i++) {
		ft::vector<int> ft_vec(ft_vec12);
			ft_vec.clear();
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 100; i++){
		std::vector<int> std_vec(std_vec12);
		std_vec.clear();
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::vector<int> ft_vec13(ft_vec12);
	std::vector<int> std_vec13(std_vec12);
	equal = true;
	ft_vec13.clear();
	std_vec13.clear();
	if (ft_vec13.empty() != std_vec13.empty())
		equal = false;
	print_time_cmp(ft_time, std_time, equal);

	print_white("========================== swap test ==========================");
	ft::vector<int> ft_vec14;
	std::vector<int> std_vec14;
	for (size_t i = 0; i < 1001; i++) {
		ft_vec14.push_back(i);
		std_vec14.push_back(i);
	}

	ft_start = clock();
	for (size_t i = 0; i < 100; i++) {
		ft::vector<int> ft_vec(ft_vec14);
			ft_vec.swap(ft_vec14);
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 100; i++){
		std::vector<int> std_vec(std_vec14);
		std_vec.swap(std_vec14);
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::vector<int> ft_vec15(ft_vec14);
	std::vector<int> std_vec15(std_vec14);
	equal = true;
	ft_vec15.swap(ft_vec14);
	std_vec15.swap(std_vec14);
	if (ft_vec15.size() != std_vec15.size())
		equal = false;
	print_time_cmp(ft_time, std_time, equal);
}


void tester_capacity_vec() {
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


void tester_constructor_vec() {
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
