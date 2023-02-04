#include "test.hpp"
void tester_operator_stack();

void tester_stack() {
	print_yel("--------------------------------------------------");
	print_yel("|                    Stack Test                  |");
	print_yel("--------------------------------------------------");

	print_white("==================== empty constructor test ====================");
	clock_t ft_start = clock();
	for (size_t i = 0; i < 100; i++)
		ft::stack<int> ft_stack;
	clock_t ft_end = clock();
	double ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	clock_t std_start = clock();
	for (size_t i = 0; i < 100; i++)
		std::stack<int> std_stack;
	clock_t std_end = clock();
	double std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	print_time_cmp(ft_time, std_time, true);

	print_white("==================== copy constructor test ====================");
	ft::stack<int> ft_stack2;
	std::stack<int> std_stack2;
	for (size_t i = 0; i < 100; i++) {
		ft_stack2.push(i);
		std_stack2.push(i);
	}

	ft_start = clock();
	for (size_t i = 0; i < 100; i++)
		ft::stack<int> ft_stack(ft_stack2);
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 100; i++)
		std::stack<int> std_stack(std_stack2);
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::stack<int> ft_stack3(ft_stack2);
	std::stack<int> std_stack3(std_stack2);
	bool equal = true;
	for (size_t i = 0; i < 100; i++) {
		if (ft_stack3.top() != std_stack3.top())
			equal = false;
		ft_stack3.pop();
		std_stack3.pop();
	}
	if (ft_stack3.size() != std_stack3.size())
		equal = false;
	print_time_cmp(ft_time, std_time, equal);


	print_white("========================== empty test =========================");
	ft::stack<int> ft_stack4;
	std::stack<int> std_stack4;

	ft_start = clock();
	for (size_t i = 0; i < 100; i++) {
		ft::stack<int> ft_stack(ft_stack4);
		ft_stack.empty();
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 100; i++) {
		std::stack<int> std_stack(std_stack4);
		std_stack.empty();
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::stack<int> ft_stack5(ft_stack4);
	std::stack<int> std_stack5(std_stack4);
	equal = true;
	if (ft_stack5.empty() != std_stack5.empty())
	if (ft_stack5.size() != std_stack5.size())
		equal = false;
	print_time_cmp(ft_time, std_time, equal);

	print_white("=========================== size test =========================");
	ft::stack<int> ft_stack6;
	std::stack<int> std_stack6;
	for (size_t i = 0; i < 100; i++) {
		ft_stack2.push(i);
		std_stack2.push(i);
	}

	ft_start = clock();
	for (size_t i = 0; i < 100; i++) {
		ft::stack<int> ft_stack(ft_stack6);
		ft_stack.size();
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 100; i++) {
		std::stack<int> std_stack(std_stack6);
		std_stack.size();
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::stack<int> ft_stack7(ft_stack6);
	std::stack<int> std_stack7(std_stack6);
	equal = true;
	if (ft_stack7.size() != std_stack7.size())
		equal = false;
	print_time_cmp(ft_time, std_time, equal);


	print_white("=========================== top test ==========================");
	ft::stack<int> ft_stack8;
	std::stack<int> std_stack8;
	for (size_t i = 0; i < 100; i++) {
		ft_stack8.push(i);
		std_stack8.push(i);
	}

	ft_start = clock();
	for (size_t i = 0; i < 100; i++) {
		ft::stack<int> ft_stack(ft_stack8);
		ft_stack.top();
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 100; i++) {
		std::stack<int> std_stack(std_stack8);
		std_stack.top();
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::stack<int> ft_stack9(ft_stack8);
	std::stack<int> std_stack9(std_stack8);
	equal = true;
	if (ft_stack9.top() != std_stack9.top())
		equal = false;
	print_time_cmp(ft_time, std_time, equal);

	print_white("=========================== top test ==========================");
	ft::stack<int> ft_stack10;
	std::stack<int> std_stack10;
	for (size_t i = 0; i < 100; i++) {
		ft_stack10.push(i);
		std_stack10.push(i);
	}

	ft_start = clock();
	for (size_t i = 0; i < 100; i++) {
		ft::stack<int> ft_stack(ft_stack10);
		for (size_t i = 0; i < 100; i++) {
			ft_stack.pop();
		}
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 100; i++) {
		std::stack<int> std_stack(std_stack10);
		for (size_t i = 0; i < 100; i++) {
			std_stack.pop();
		}
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::stack<int> ft_stack11(ft_stack10);
	std::stack<int> std_stack11(std_stack10);
	equal = true;
	for (size_t i = 0; i < 100; i++) {
		ft_stack11.pop();
		std_stack11.pop();
	}
	if (ft_stack11.empty() != std_stack11.empty())
		equal = false;
	print_time_cmp(ft_time, std_time, equal);

  tester_operator_stack();
}

void tester_operator_stack() {
  	print_white("--------------------------------------------------");
	print_white("|                  operator Test                 |");
	print_white("--------------------------------------------------");
	print_white("======================= operator== test ========================");
	ft::stack<int> ft_vec2;
	std::stack<int> std_vec2;
	for (size_t i = 0; i < 5001; i++) {
		ft_vec2.push(i);
		std_vec2.push(i);
	}

	clock_t ft_start = clock();
	for (size_t i = 0; i < 500; i++) {
		ft::stack<int> ft_vec(ft_vec2);
		if (ft_vec == ft_vec2)
			continue;
	}
	clock_t ft_end = clock();
	double ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	clock_t std_start = clock();
	for (size_t i = 0; i < 500; i++){
		std::stack<int> std_vec(std_vec2);
		if (std_vec == std_vec2)
			continue;
	}
	clock_t std_end = clock();
	double std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::stack<int> ft_vec3(ft_vec2);
	std::stack<int> std_vec3(std_vec2);
	bool equal = false;
	if (ft_vec2 == ft_vec3)
			equal = true;

	print_time_cmp(ft_time, std_time, equal);

	print_white("======================= operator!= test ========================");
	ft::stack<int> ft_vec4;
	std::stack<int> std_vec4;
	for (size_t i = 0; i < 5001; i++) {
		ft_vec4.push(i);
		std_vec4.push(i);
	}

	ft_start = clock();
	for (size_t i = 0; i < 500; i++) {
		ft::stack<int> ft_vec(ft_vec4);
		if (ft_vec != ft_vec4)
			continue;
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 500; i++){
		std::stack<int> std_vec(std_vec4);
		if (std_vec != std_vec4)
			continue;
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::stack<int> ft_vec5(ft_vec4);
	std::stack<int> std_vec5(std_vec4);
	equal = false;
	if ((ft_vec5 != ft_vec4) == false)
			equal = true;

	print_time_cmp(ft_time, std_time, equal);


	print_white("====================== operator < test ========================");
	ft::stack<int> ft_vec6;
	std::stack<int> std_vec6;
	for (size_t i = 0; i < 5001; i++) {
		ft_vec6.push(i);
		std_vec6.push(i);
	}

	ft_start = clock();
	for (size_t i = 0; i < 500; i++) {
		ft::stack<int> ft_vec(ft_vec6);
		if (ft_vec < ft_vec6)
			continue;
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 500; i++){
		std::stack<int> std_vec(std_vec6);
		if (std_vec < std_vec6)
			continue;
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::stack<int> ft_vec7(ft_vec6);
	std::stack<int> std_vec7(std_vec6);
	equal = false;
	if ((ft_vec7 < ft_vec6) == false)
			equal = true;

	print_time_cmp(ft_time, std_time, equal);

	print_white("====================== operator > test ========================");
	ft::stack<int> ft_vec8;
	std::stack<int> std_vec8;
	for (size_t i = 0; i < 5001; i++) {
		ft_vec8.push(i);
		std_vec8.push(i);
	}

	ft_start = clock();
	for (size_t i = 0; i < 500; i++) {
		ft::stack<int> ft_vec(ft_vec8);
		if (!(ft_vec > ft_vec8))
			continue;
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 500; i++){
		std::stack<int> std_vec(std_vec8);
		if (!(std_vec > std_vec8))
			continue;
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::stack<int> ft_vec9(ft_vec8);
	ft_vec9.push(50000);
	equal = false;
	if (ft_vec9 > ft_vec8)
			equal = true;

	print_time_cmp(ft_time, std_time, equal);

	print_white("====================== operator <= test ========================");
	ft::stack<int> ft_vec10;
	std::stack<int> std_vec10;
	for (size_t i = 0; i < 5001; i++) {
		ft_vec10.push(i);
		std_vec10.push(i);
	}

	ft_start = clock();
	for (size_t i = 0; i < 500; i++) {
		ft::stack<int> ft_vec(ft_vec10);
		if (ft_vec <= ft_vec10)
			continue;
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 500; i++){
		std::stack<int> std_vec(std_vec10);
		if (!(std_vec <= std_vec10))
			continue;
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::stack<int> ft_vec11(ft_vec10);
	equal = false;
	if (ft_vec11 <= ft_vec10)
			equal = true;

	print_time_cmp(ft_time, std_time, equal);

	print_white("====================== operator >= test ========================");
	ft::stack<int> ft_vec12;
	std::stack<int> std_vec12;
	for (size_t i = 0; i < 5001; i++) {
		ft_vec12.push(i);
		std_vec12.push(i);
	}

	ft_start = clock();
	for (size_t i = 0; i < 500; i++) {
		ft::stack<int> ft_vec(ft_vec12);
		if (ft_vec >= ft_vec12)
			continue;
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 500; i++){
		std::stack<int> std_vec(std_vec12);
		if (!(std_vec >= std_vec12))
			continue;
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::stack<int> ft_vec13(ft_vec12);
	equal = false;
	if (ft_vec13 >= ft_vec12)
			equal = true;

	print_time_cmp(ft_time, std_time, equal);
}
