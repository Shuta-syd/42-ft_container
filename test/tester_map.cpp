#include "test.hpp"
void tester_constructor_map();
void tester_iterator_map();
void tester_element_access_map();
void tester_modifiers_map();
void tester_lookup();
void tester_operator_map();
void mini_test();
void tester_other();

#define FT_PAIR(a, b) ft::pair<int, std::string>(a, b)
#define STD_PAIR(a, b) std::pair<int, std::string>(a, b)

void tester_map()
{
	print_yel("--------------------------------------------------");
	print_yel("|                     Map Test                   |");
	print_yel("--------------------------------------------------");

	tester_constructor_map();
	tester_iterator_map();
	tester_operator_map();
	tester_element_access_map();
	tester_modifiers_map();
	tester_lookup();
	tester_other();
}

void tester_other() {
	print_white("========================= make pair test ========================");
	bool equal = true;
	ft::pair<int, int> var1  = ft::make_pair<int, int>(5, 16);
	if (!(var1.first == 5 && var1.second == 16))
		equal = false;
	ft::pair<int, int> var2  = ft::make_pair<int, int>(42, 16);
	if (!(var2.first == 42 && var2.second == 16))
		equal = false;
	ft::pair<int, int> var3  = ft::make_pair<int, int>(10, 16);
	if (!(var3.first == 10 && var3.second == 16))
		equal = false;
	ft::pair<int, int> var4  = ft::make_pair<int, int>(99, 16);
	if (!(var4.first == 99 && var4.second == 16))
		equal = false;
	ft::pair<int, int> var5  = ft::make_pair<int, int>(100000, 16);
	if (!(var5.first == 100000 && var5.second == 16))
		equal = false;
	print_time_cmp(1.0, 1.0, equal);


	print_white("======================= value_compare test ======================");
	ft::map<int, std::string> ft_map;
	ft_map.insert(FT_PAIR(1, "42Tokyo"));
	ft_map.insert(FT_PAIR(2, "Hello"));

	equal = true;
	ft::map<int, std::string>::value_compare comp = ft_map.value_comp();
	ft::map<int, std::string>::iterator it = ft_map.begin();
	if (comp(*ft_map.find(1), FT_PAIR(1, "42Tokyo")) == false)
		equal = false;
	if (comp(*ft_map.find(2), FT_PAIR(1, "Hello")) == false)
		equal = false;
	print_time_cmp(1.0, 1.0, equal);
}

void tester_iterator_map() {
	print_white("--------------------------------------------------");
	print_white("|                  iterator Test                 |");
	print_white("--------------------------------------------------");
	print_white("================== bidirectional iterator test ==================");
	ft::map<int, std::string> ft_map;
	std::map<int, std::string> std_map;
	for (size_t i = 0; i < 1001; i++) {
		ft_map.insert(FT_PAIR(i, "42tokyo"));
		std_map.insert(STD_PAIR(i, "42tokyo"));
	}

	clock_t ft_start = clock();
	for (size_t i = 0; i < 1000; i++) {
		ft::map<int, std::string> ft_map_(ft_map.begin(), ft_map.end());
		ft::map<int, std::string>::iterator rit = ft_map_.begin();
		ft::map<int, std::string>::iterator rit_end = ft_map_.end();
		for (; rit != rit_end; rit++) ;
	}
	clock_t ft_end = clock();
	double ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	clock_t std_start = clock();
	for (size_t i = 0; i < 1000; i++){
		std::map<int, std::string> std_map_(std_map.begin(), std_map.end());
		std::map<int, std::string>::iterator rit = std_map_.begin();
		std::map<int, std::string>::iterator rit_end = std_map_.end();
		for (; rit != rit_end; rit++) ;
	}
	clock_t std_end = clock();
	double std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::map<int, std::string> ft_map2(ft_map.begin(), ft_map.end());
	std::map<int, std::string> std_map2(std_map.begin(), std_map.end());
	bool equal = ft::equal_map(ft_map2.begin(), ft_map2.end(), std_map2.begin());
	print_time_cmp(ft_time, std_time, equal);

	print_white("=============== const bidirectional iterator test ===============");
	ft::map<int, std::string> ft_map42;
	std::map<int, std::string> std_map42;
	for (size_t i = 0; i < 1001; i++) {
		ft_map42.insert(FT_PAIR(i, "42tokyo"));
		std_map42.insert(STD_PAIR(i, "42tokyo"));
	}

	ft_start = clock();
	for (size_t i = 0; i < 1000; i++) {
		ft::map<int, std::string> ft_map42_(ft_map42.begin(), ft_map42.end());
		ft::map<int, std::string>::const_iterator rit = ft_map42_.begin();
		ft::map<int, std::string>::const_iterator rit_end = ft_map42_.end();
		for (; rit != rit_end; rit++) ;
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 1000; i++){
		std::map<int, std::string> std_map42_(std_map42.begin(), std_map42.end());
		std::map<int, std::string>::const_iterator rit = std_map42_.begin();
		std::map<int, std::string>::const_iterator rit_end = std_map42_.end();
		for (; rit != rit_end; rit++) ;
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::map<int, std::string> ft_map43(ft_map42.begin(), ft_map42.end());
	std::map<int, std::string> std_map43(std_map42.begin(), std_map42.end());
	equal = ft::equal_map(ft_map43.begin(), ft_map43.end(), std_map43.begin());
	print_time_cmp(ft_time, std_time, equal);


	print_white("===================== reverse iterator test =====================");
	ft::map<int, std::string> ft_map4;
	std::map<int, std::string> std_map4;
	for (size_t i = 0; i < 1001; i++) {
		ft_map4.insert(FT_PAIR(i, "42tokyo"));
		std_map4.insert(STD_PAIR(i, "42tokyo"));
	}

	ft_start = clock();
	for (size_t i = 0; i < 1000; i++) {
		ft::map<int, std::string> ft_map4_(ft_map4.begin(), ft_map4.end());
		ft::map<int, std::string>::reverse_iterator rit = ft_map4_.rbegin();
		ft::map<int, std::string>::reverse_iterator rit_end = ft_map4_.rend();
		for (; rit != rit_end; rit++) ;
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 1000; i++){
		std::map<int, std::string> std_map4_(std_map4.begin(), std_map4.end());
		std::map<int, std::string>::reverse_iterator rit = std_map4_.rbegin();
		std::map<int, std::string>::reverse_iterator rit_end = std_map4_.rend();
		for (; rit != rit_end; rit++) ;
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::map<int, std::string> ft_map3(ft_map4.begin(), ft_map4.end());
	std::map<int, std::string> std_map3(std_map4.begin(), std_map4.end());
	equal = ft::equal_map(ft_map3.rbegin(), ft_map3.rend(), std_map3.rbegin());
	print_time_cmp(ft_time, std_time, equal);


	print_white("================= const reverse iterator test ===================");
	ft::map<int, std::string> ft_map5;
	std::map<int, std::string> std_map5;
	for (size_t i = 0; i < 1001; i++) {
		ft_map5.insert(FT_PAIR(i, "42tokyo"));
		std_map5.insert(STD_PAIR(i, "42tokyo"));
	}

	ft_start = clock();
	for (size_t i = 0; i < 1000; i++) {
		ft::map<int, std::string> ft_map5_(ft_map5.begin(), ft_map5.end());
		ft::map<int, std::string>::const_reverse_iterator rit = ft_map5_.rbegin();
		ft::map<int, std::string>::const_reverse_iterator rit_end = ft_map5_.rend();
		for (; rit != rit_end; rit++) ;
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 1000; i++){
		std::map<int, std::string> std_map5_(std_map5.begin(), std_map5.end());
		std::map<int, std::string>::const_reverse_iterator rit = std_map5_.rbegin();
		std::map<int, std::string>::const_reverse_iterator rit_end = std_map5_.rend();
		for (; rit != rit_end; rit++) ;
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::map<int, std::string> ft_map6(ft_map5.begin(), ft_map5.end());
	std::map<int, std::string> std_map6(std_map5.begin(), std_map5.end());
	equal = ft::equal_map(ft_map6.rbegin(), ft_map6.rend(), std_map6.rbegin());
	print_time_cmp(ft_time, std_time, equal);
}

void tester_operator_map() {
	print_white("--------------------------------------------------");
	print_white("|                  operator Test                 |");
	print_white("--------------------------------------------------");
	print_white("======================= operator== test ========================");
	ft::map<int, std::string> ft_map;
	std::map<int, std::string> std_map;
	for (size_t i = 0; i < 2501; i++) {
		ft_map.insert(FT_PAIR(i, "42tokyo"));
		std_map.insert(STD_PAIR(i, "42tokyo"));
	}

	clock_t ft_start = clock();
	for (size_t i = 0; i < 2500; i++) {
		ft::map<int, std::string> ft_map_(ft_map.begin(), ft_map.end());
		if (ft_map_ == ft_map)
			continue;
	}
	clock_t ft_end = clock();
	double ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	clock_t std_start = clock();
	for (size_t i = 0; i < 2500; i++){
		std::map<int, std::string> std_map_(std_map.begin(), std_map.end());
		if (std_map_ == std_map)
			continue;
	}
	clock_t std_end = clock();
	double std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::map<int, std::string> ft_map2(ft_map.begin(), ft_map.end());
	bool equal = false;
	if (ft_map2 == ft_map)
			equal = true;
	print_time_cmp(ft_time, std_time, equal);


	print_white("======================= operator!= test ========================");
	ft::map<int, std::string> ft_map3;
	std::map<int, std::string> std_map3;
	for (size_t i = 0; i < 2501; i++) {
		ft_map3.insert(FT_PAIR(i, "42tokyo"));
		std_map3.insert(STD_PAIR(i, "42tokyo"));
	}

	ft_start = clock();
	for (size_t i = 0; i < 2500; i++) {
		ft::map<int, std::string> ft_map3_(ft_map3.begin(), --ft_map3.end());
		if (ft_map3_ != ft_map3)
			continue;
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 2500; i++){
		std::map<int, std::string> std_map3_(std_map3.begin(), --std_map3.end());
		if (std_map3_ != std_map3)
			continue;
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::map<int, std::string> ft_map4(ft_map3.begin(), --ft_map3.end());
	equal = false;
	if (ft_map4 != ft_map3)
			equal = true;
	print_time_cmp(ft_time, std_time, equal);


	print_white("======================= operator < test ========================");
	ft::map<int, std::string> ft_map5;
	std::map<int, std::string> std_map5;
	for (size_t i = 0; i < 2501; i++) {
		ft_map5.insert(FT_PAIR(i, "42tokyo"));
		std_map5.insert(STD_PAIR(i, "42tokyo"));
	}

	ft_start = clock();
	for (size_t i = 0; i < 2500; i++) {
		ft::map<int, std::string> ft_map5_(ft_map5.begin(), --ft_map5.end());
		if (ft_map5_ < ft_map5)
			continue;
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 2500; i++){
		std::map<int, std::string> std_map5_(std_map5.begin(), --std_map5.end());
		if (std_map5_ < std_map5)
			continue;
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::map<int, std::string> ft_map6(ft_map5.begin(), --ft_map5.end());
	equal = false;
	if (ft_map6 < ft_map5)
			equal = true;
	print_time_cmp(ft_time, std_time, equal);


	print_white("======================= operator <= test ========================");
	ft::map<int, std::string> ft_map7;
	std::map<int, std::string> std_map7;
	for (size_t i = 0; i < 2501; i++) {
		ft_map7.insert(FT_PAIR(i, "42tokyo"));
		std_map7.insert(STD_PAIR(i, "42tokyo"));
	}

	ft_start = clock();
	for (size_t i = 0; i < 2500; i++) {
		ft::map<int, std::string> ft_map7_(ft_map7.begin(), ft_map7.end());
		if (ft_map7_ <= ft_map7)
			continue;
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 2500; i++){
		std::map<int, std::string> std_map7_(std_map7.begin(), std_map7.end());
		if (std_map7_ <= std_map7)
			continue;
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::map<int, std::string> ft_map8(ft_map7.begin(), ft_map7.end());
	equal = false;
	if (ft_map8 <= ft_map7)
			equal = true;
	print_time_cmp(ft_time, std_time, equal);


	print_white("======================= operator > test ========================");
	ft::map<int, std::string> ft_map9;
	std::map<int, std::string> std_map9;
	for (size_t i = 0; i < 2501; i++) {
		ft_map9.insert(FT_PAIR(i, "42tokyo"));
		std_map9.insert(STD_PAIR(i, "42tokyo"));
	}

	ft_start = clock();
	for (size_t i = 0; i < 2500; i++) {
		ft::map<int, std::string> ft_map9_(ft_map9.begin(), ft_map9.end());
		ft_map9_.insert(FT_PAIR(2501, "42"));
		if (ft_map9_ > ft_map9)
			continue;
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 2500; i++){
		std::map<int, std::string> std_map9_(std_map9.begin(), std_map9.end());
		std_map9_.insert(STD_PAIR(2501, "42"));
		if (std_map9_ > std_map9)
			continue;
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::map<int, std::string> ft_map10(ft_map9.begin(), ft_map9.end());
	ft_map10.insert(FT_PAIR(2501, "42"));
	equal = false;
	if (ft_map10 > ft_map9)
			equal = true;
	print_time_cmp(ft_time, std_time, equal);

	print_white("======================= operator >= test ========================");
	ft::map<int, std::string> ft_map11;
	std::map<int, std::string> std_map11;
	for (size_t i = 0; i < 2501; i++) {
		ft_map11.insert(FT_PAIR(i, "42tokyo"));
		std_map11.insert(STD_PAIR(i, "42tokyo"));
	}

	ft_start = clock();
	for (size_t i = 0; i < 2500; i++) {
		ft::map<int, std::string> ft_map11_(ft_map11.begin(), ft_map11.end());
		if (ft_map11_ >= ft_map11)
			continue;
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 2500; i++){
		std::map<int, std::string> std_map11_(std_map11.begin(), std_map11.end());
		if (std_map11_ >= std_map11)
			continue;
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::map<int, std::string> ft_map12(ft_map11.begin(), ft_map11.end());
	equal = false;
	if (ft_map12 >= ft_map11)
			equal = true;
	print_time_cmp(ft_time, std_time, equal);
}


void tester_element_access_map() {
	print_white("--------------------------------------------------");
	print_white("|              element_access Test               |");
	print_white("--------------------------------------------------");
	print_white("======================= operator[] test ========================");
	ft::map<int, std::string> ft_map;
	std::map<int, std::string> std_map;
	for (size_t i = 0; i < 2501; i++) {
		ft_map.insert(FT_PAIR(i, "42tokyo"));
		std_map.insert(STD_PAIR(i, "42tokyo"));
	}

	clock_t ft_start = clock();
	for (size_t i = 0; i < 2500; i++) {
		ft::map<int, std::string> ft_map_(ft_map.begin(), ft_map.end());
		for (size_t i = 0; i < 2500; i++)
			ft_map_[i];
	}
	clock_t ft_end = clock();
	double ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	clock_t std_start = clock();
	for (size_t i = 0; i < 2500; i++){
		std::map<int, std::string> std_map_(std_map.begin(), std_map.end());
		for (size_t i = 0; i < 2500; i++)
			std_map_[i];
	}
	clock_t std_end = clock();
	double std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::map<int, std::string> ft_map2(ft_map.begin(), ft_map.end());
	std::map<int, std::string> std_map2(std_map.begin(), std_map.end());
	bool equal = true;
	for (size_t i = 0; i < 2500; i++){
		if (ft_map2[i] != std_map2[i])
			equal = false;
	}
	print_time_cmp(ft_time, std_time, equal);
}


void tester_lookup() {
	print_white("--------------------------------------------------");
	print_white("|                   Lookup Test                  |");
	print_white("--------------------------------------------------");
	print_white("========================== count test ==========================");
	ft::map<int, std::string> ft_map;
	std::map<int, std::string> std_map;
	for (size_t i = 0; i < 2500; i++) {
		ft_map.insert(FT_PAIR(i, "42tokyo"));
		std_map.insert(STD_PAIR(i, "42tokyo"));
	}

	clock_t ft_start = clock();
	for (size_t i = 0; i < 2500; i++) {
		ft::map<int, std::string> ft_map_(ft_map.begin(), ft_map.end());
		for (size_t i = 0; i < 2500; i++)
			ft_map_.count(i);
	}
	clock_t ft_end = clock();
	double ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	clock_t std_start = clock();
	for (size_t i = 0; i < 2500; i++){
		std::map<int, std::string> std_map_(std_map.begin(), std_map.end());
		for (size_t i = 0; i < 2500; i++)
			std_map_.count(i);
	}
	clock_t std_end = clock();
	double std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::map<int, std::string> ft_map2(ft_map.begin(), ft_map.end());
	std::map<int, std::string> std_map2(std_map.begin(), std_map.end());
	bool equal = true;
	for (size_t i = 0; i < 2500; i++){
		if (ft_map2.count(i) != std_map2.count(i))
			equal = false;
	}
	print_time_cmp(ft_time, std_time, equal);


	print_white("========================== find test ===========================");
	ft::map<int, std::string> ft_map3;
	std::map<int, std::string> std_map3;
	for (size_t i = 0; i < 2500; i++) {
		ft_map3.insert(FT_PAIR(i, "42tokyo"));
		std_map3.insert(STD_PAIR(i, "42tokyo"));
	}

	ft_start = clock();
	for (size_t i = 0; i < 2500; i++) {
		ft::map<int, std::string> ft_map(ft_map3.begin(), ft_map3.end());
		for (size_t i = 0; i < 2500; i++)
			ft_map.find(i);
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 2500; i++){
		std::map<int, std::string> std_map(std_map3.begin(), std_map3.end());
		for (size_t i = 0; i < 2500; i++)
			std_map.find(i);
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::map<int, std::string> ft_map4(ft_map3.begin(), ft_map3.end());
	std::map<int, std::string> std_map4(std_map3.begin(), std_map3.end());
	equal = true;
	for (size_t i = 0; i < 2500; i++){
		if (ft_map4.find(i)->first != std_map4.find(i)->first)
			equal = false;
	}
	print_time_cmp(ft_time, std_time, equal);


	print_white("====================== equal_range test ========================");
	ft::map<int, std::string> ft_map5;
	std::map<int, std::string> std_map5;
	for (size_t i = 0; i < 2505; i++) {
		ft_map5.insert(FT_PAIR(i, "42tokyo"));
		std_map5.insert(STD_PAIR(i, "42tokyo"));
	}

	ft_start = clock();
	for (size_t i = 0; i < 2500; i++) {
		ft::map<int, std::string> ft_map(ft_map5.begin(), ft_map5.end());
		for (size_t i = 0; i < 2500; i++)
			ft_map.equal_range(i);
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 2500; i++){
		std::map<int, std::string> std_map(std_map5.begin(), std_map5.end());
		for (size_t i = 0; i < 2500; i++)
			std_map.equal_range(i);
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::map<int, std::string> ft_map6(ft_map5.begin(), ft_map5.end());
	std::map<int, std::string> std_map6(std_map5.begin(), std_map5.end());
	equal = true;
	for (size_t i = 0; i < 2500; i++){
		if (ft_map6.equal_range(i).first->first != std_map6.equal_range(i).first->first )
			equal = false;
		else if (ft_map6.equal_range(i).second->first != std_map6.equal_range(i).second->first )
			equal = false;
	}
	print_time_cmp(ft_time, std_time, equal);


	print_white("====================== lower_bound test ========================");
	ft::map<int, std::string> ft_map7;
	std::map<int, std::string> std_map7;
	for (size_t i = 0; i < 2500; i++) {
		ft_map7.insert(FT_PAIR(i, "42tokyo"));
		std_map7.insert(STD_PAIR(i, "42tokyo"));
	}

	ft_start = clock();
	for (size_t i = 0; i < 2500; i++) {
		ft::map<int, std::string> ft_map(ft_map7.begin(), ft_map7.end());
		for (size_t i = 0; i < 2500; i++)
			ft_map.lower_bound(i);
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 2500; i++){
		std::map<int, std::string> std_map(std_map7.begin(), std_map7.end());
		for (size_t i = 0; i < 2500; i++)
			std_map.lower_bound(i);
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::map<int, std::string> ft_map8(ft_map7.begin(), ft_map7.end());
	std::map<int, std::string> std_map8(std_map7.begin(), std_map7.end());
	equal = true;
	for (size_t i = 0; i < 2500; i++){
		if (ft_map8.lower_bound(i)->first != std_map8.lower_bound(i)->first )
			equal = false;
	}
	print_time_cmp(ft_time, std_time, equal);


	print_white("====================== upper_bound test ========================");
	ft::map<int, std::string> ft_map9;
	std::map<int, std::string> std_map9;
	for (size_t i = 0; i < 2505; i++) {
		ft_map9.insert(FT_PAIR(i, "42tokyo"));
		std_map9.insert(STD_PAIR(i, "42tokyo"));
	}

	ft_start = clock();
	for (size_t i = 0; i < 2500; i++) {
		ft::map<int, std::string> ft_map(ft_map9.begin(), ft_map9.end());
		for (size_t i = 0; i < 2500; i++)
			ft_map.upper_bound(i);
	}
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 2500; i++){
		std::map<int, std::string> std_map(std_map9.begin(), std_map9.end());
		for (size_t i = 0; i < 2500; i++)
			std_map.upper_bound(i);
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::map<int, std::string> ft_map10(ft_map9.begin(), ft_map9.end());
	std::map<int, std::string> std_map10(std_map9.begin(), std_map9.end());
	equal = true;
	for (size_t i = 0; i < 2500; i++){
		if (ft_map10.upper_bound(i)->first != std_map10.upper_bound(i)->first ){
			std::cout << ft_map10.upper_bound(i)->first << " " << std_map10.upper_bound(i)->first << std::endl;
			equal = false;
			break ;
		}
	}
	print_time_cmp(ft_time, std_time, equal);
}


void tester_modifiers_map()
{
	print_white("--------------------------------------------------");
	print_white("|                 Modifiers Test                 |");
	print_white("--------------------------------------------------");
	print_white("========================== insert test ==========================");
	clock_t ft_start = clock();
	for (size_t i = 0; i < 250; i++) {
		ft::map<int, std::string> ft_map;
		for (size_t i = 0; i < 2500; i++)
			ft_map.insert(FT_PAIR(i, "42Tokyo"));
	}
	clock_t ft_end = clock();
	double ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	clock_t std_start = clock();
	for (size_t i = 0; i < 250; i++){
		std::map<int, std::string> std_map;
		for (size_t i = 0; i < 2500; i++)
			std_map.insert(STD_PAIR(i, "42Tokyo"));
	}
	clock_t std_end = clock();
	double std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::map<int, std::string> ft_map;
	for (size_t i = 0; i < 250; i++)
			ft_map.insert(FT_PAIR(i, "42Tokyo"));
	std::map<int, std::string> std_map;
	for (size_t i = 0; i < 250; i++)
			std_map.insert(STD_PAIR(i, "42Tokyo"));
	bool equal = ft::equal_map(ft_map.begin(), ft_map.end(), std_map.begin());
	if (ft_map.size() != std_map.size())
		equal = false;

	print_time_cmp(ft_time, std_time, equal);

	print_white("========================= insert2 test =========================");

	ft_start = clock();
	for (size_t i = 0; i < 250; i++) {
		ft::map<int, std::string> ft_map;
		for (size_t i = 0; i < 2500; i++) {
			ft_map.insert(ft_map.begin(), FT_PAIR(i, "42Tokyo"));
		}
	}
	ft_end = clock();
	ft_time = (double)difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 250; i++){
		std::map<int, std::string> std_map;
			for (size_t i = 0; i < 2500; i++) {
				std_map.insert(std_map.begin(), STD_PAIR(i, "42Tokyo"));
		}
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::map<int, std::string> ft_map2;
	for (size_t i = 0; i < 250; i++)
		ft_map2.insert(ft_map2.begin(), FT_PAIR(i, "42Tokyo"));
	std::map<int, std::string> std_map2;
	for (size_t i = 0; i < 250; i++)
		std_map2.insert(std_map2.begin(), STD_PAIR(i, "42Tokyo"));
	equal = ft::equal_map(ft_map2.begin(), ft_map2.end(), std_map2.begin());
	if (ft_map2.size() != std_map2.size())
		equal = false;

	print_time_cmp(ft_time, std_time, equal);


	print_white("========================= insert3 test =========================");
	ft::map<int, std::string> ft_map3;
	std::map<int, std::string> std_map3;
	for (size_t i = 0; i < 2500; i++) {
		ft_map3.insert(FT_PAIR(i, "42tokyo"));
		std_map3.insert(STD_PAIR(i, "42tokyo"));
	}

	ft_start = clock();
	for (size_t i = 0; i < 250; i++) {
		ft::map<int, std::string> ft_map;
		ft_map.insert(ft_map3.begin(), ft_map3.end());
	}
	ft_end = clock();
	ft_time = (double)difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 250; i++){
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
	for (size_t i = 0; i < 250; i++) {
		ft_map5.insert(FT_PAIR(i, "42tokyo"));
		std_map5.insert(STD_PAIR(i, "42tokyo"));
	}

	ft_start = clock();
	for (size_t i = 0; i < 250; i++) {
	ft::map<int, std::string> ft_map(ft_map5.begin(), ft_map5.end());
		for (size_t i = 0; i < 250; i++)
			ft_map.erase(i);
	}
	ft_end = clock();
	ft_time = (double)difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 250; i++){
		std::map<int, std::string> std_map(std_map5.begin(), std_map5.end());
		for (size_t i = 0; i < 250; i++)
			std_map.erase(i);
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::map<int, std::string> ft_map6(ft_map5.begin(), ft_map5.end());
	for (size_t i = 0; i < 250; i++)
		ft_map6.erase(i);
	std::map<int, std::string> std_map6(std_map5.begin(), std_map5.end());
	for (size_t i = 0; i < 250; i++)
		std_map6.erase(i);
	equal = ft::equal_map(ft_map6.begin(), ft_map6.end(), std_map6.begin());
	if (ft_map6.size() != std_map6.size())
		equal = false;

	print_time_cmp(ft_time, std_time, equal);


	print_white("========================= erase2 test ========================");
	ft::map<int, std::string> ft_map7;
	std::map<int, std::string> std_map7;
	for (size_t i = 0; i < 250; i++) {
		ft_map7.insert(FT_PAIR(i, "42tokyo"));
		std_map7.insert(STD_PAIR(i, "42tokyo"));
	}

	ft_start = clock();
	for (size_t i = 0; i < 250; i++) {
	ft::map<int, std::string> ft_map(ft_map7.begin(), ft_map7.end());
		for (size_t i = 0; i < 200; i++)
			ft_map.erase(ft_map.begin());
	}
	ft_end = clock();
	ft_time = (double)difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 250; i++){
		std::map<int, std::string> std_map(std_map7.begin(), std_map7.end());
		for (size_t i = 0; i < 250; i++)
			std_map.erase(std_map.begin());
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::map<int, std::string> ft_map8(ft_map7.begin(), ft_map7.end());
	for (size_t i = 0; i < 50; i++)
		ft_map8.erase(++ft_map8.begin());
	std::map<int, std::string> std_map8(std_map7.begin(), std_map7.end());
	for (size_t i = 0; i < 50; i++)
		std_map8.erase(++std_map8.begin());
	equal = ft::equal_map(ft_map8.begin(), ft_map8.end(), std_map8.begin());
	if (ft_map8.size() != std_map8.size())
		equal = false;

	print_time_cmp(ft_time, std_time, equal);


	print_white("========================= erase3 test ========================");
	ft::map<int, std::string> ft_map9;
	std::map<int, std::string> std_map9;
	for (size_t i = 1; i < 2500; i++) {
		ft_map9.insert(FT_PAIR(i, "42tokyo"));
		std_map9.insert(STD_PAIR(i, "42tokyo"));
	}

	ft_start = clock();
	for (size_t i = 0; i < 2500; i++) {
		ft::map<int, std::string> ft_map(ft_map9.begin(), ft_map9.end());
		ft_map.erase(ft_map.begin(), ft_map.end());
	}
	ft_end = clock();
	ft_time = (double)difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 2500; i++){
		std::map<int, std::string> std_map(std_map9.begin(), std_map9.end());
		std_map.erase(std_map.begin(), std_map.end());
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::map<int, std::string> ft_map10(ft_map9.begin(), ft_map9.end());
	ft_map10.erase(ft_map10.begin(), --ft_map10.end());
	std::map<int, std::string> std_map10(std_map9.begin(), std_map9.end());
	std_map10.erase(std_map10.begin(), --std_map10.end());
	equal = ft::equal_map(ft_map10.begin(), ft_map10.end(), std_map10.begin());
	if (ft_map10.size() != std_map10.size())
		equal = false;

	print_time_cmp(ft_time, std_time, equal);


	print_white("========================= clear test ========================");
	ft::map<int, std::string> ft_map11;
	std::map<int, std::string> std_map11;
	for (size_t i = 1; i < 2500; i++) {
		ft_map11.insert(FT_PAIR(i, "42tokyo"));
		std_map11.insert(STD_PAIR(i, "42tokyo"));
	}

	ft_start = clock();
	for (size_t i = 0; i < 2500; i++) {
		ft::map<int, std::string> ft_map(ft_map11.begin(), ft_map11.end());
		ft_map.clear();
	}
	ft_end = clock();
	ft_time = (double)difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 2500; i++){
		std::map<int, std::string> std_map(std_map11.begin(), std_map11.end());
		std_map.clear();
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::map<int, std::string> ft_map12(ft_map11.begin(), ft_map11.end());
	ft_map12.clear();
	std::map<int, std::string> std_map12(std_map11.begin(), std_map11.end());
	std_map12.clear();
	if (ft_map12.size() == std_map12.size())
		equal = true;
	else
		equal = false;

	print_time_cmp(ft_time, std_time, equal);


	print_white("========================= swap test =======================");
	ft::map<int, std::string> ft_map13;
	std::map<int, std::string> std_map13;
	for (size_t i = 1; i < 2500; i++) {
		ft_map13.insert(FT_PAIR(i, "42tokyo"));
		std_map13.insert(STD_PAIR(i, "42tokyo"));
	}

	ft_start = clock();
	for (size_t i = 0; i < 2500; i++) {
		ft::map<int, std::string> ft_map(ft_map13.begin(), ft_map13.end());
		ft_map.swap(ft_map13);
	}
	ft_end = clock();
	ft_time = (double)difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 2500; i++){
		std::map<int, std::string> std_map(std_map13.begin(), std_map13.end());
		std_map.swap(std_map13);
	}
	std_end = clock();
	std_time = difftime(std_end, std_start) / CLOCKS_PER_SEC;

	ft::map<int, std::string> ft_map14(ft_map13.begin(), --ft_map13.end());
	ft_map14.swap(ft_map13);
	std::map<int, std::string> std_map14(std_map13.begin(), --std_map13.end());
	std_map14.swap(std_map13);
	equal = ft::equal_map(ft_map14.begin(), ft_map14.end(), std_map14.begin());
	if (ft_map14.size() != std_map14.size())
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
	for (size_t i = 0; i < 250; i++)
		ft::map<int, std::string> ft_map;
	clock_t ft_end = clock();
	double ft_time = (double)difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	clock_t std_start = clock();
	for (size_t i = 0; i < 250; i++)
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
	for (size_t i = 0; i < 250; i++)
		ft::map<int, std::string> ft_map(ft_map2.begin(), ft_map2.end());
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 250; i++)
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
	for (size_t i = 0; i < 250; i++)
		ft::map<int, std::string> ft_map(ft_map4);
	ft_end = clock();
	ft_time = difftime(ft_end, ft_start) / CLOCKS_PER_SEC;

	std_start = clock();
	for (size_t i = 0; i < 250; i++)
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
	std::cout << "std :";
	typename std::map<T1, T2>::iterator it = test.begin();
	for (; it != test.end(); it++) {
		std::cout << "[" << std::setw(1) << std::right << std::setfill(' ') << it->first << "]";
	}
	std::cout << std::endl;
}

template <class T1, class T2>
void print_ft_map(ft::map<T1, T2> test) {
	std::cout << "ft  :";
	typename ft::map<T1, T2>::iterator it = test.begin();
	for (; it != test.end(); it++) {
		std::cout << "[" << std::setw(1) << std::right << std::setfill(' ') << it->first << "]";
	}
	std::cout << std::endl;
}
