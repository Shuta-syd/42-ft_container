#include "test.hpp"


void print_white(std::string str) {
	std::cout << str  << std::endl;
}

void print_mgn(std::string str) {
	std::cout << MGN << str << RES << std::endl;
}

void print_time_cmp(double ft, double std, bool ok) {
	double perf = ft / std;

	if (ok && perf < 20.0)
		print_white("FT: " + std::to_string(ft) + " [s] | STD: " + std::to_string(std) + " [s] | PERF: " + std::to_string(perf) + " | PASS \e[32mOK\e[m");
	else if (perf > 20.0)
	print_white("FT: " + std::to_string(ft) + " [s] | STD: " + std::to_string(std) + " [s] | PERF: " + std::to_string(perf) + " | PASS \e[33mTIMEOUT\e[m");
	else
		print_white("FT: " + std::to_string(ft) + " [s] | STD: " + std::to_string(std) + " [s] | PERF: " + std::to_string(perf) + " | PASS \e[31mKO\e[m");
}
