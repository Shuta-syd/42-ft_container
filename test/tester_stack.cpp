#include "test.hpp"

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
}
