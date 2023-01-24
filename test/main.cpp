#include "test.hpp"

int main(int argc, char const *argv[]) {

	if (argc != 2) {
		std::cerr << "Please select STL (vector or stack or map)" << std::endl;
		return 1;
	}

	std::string stl(argv[1]);
	if (stl == "vector")
		tester_vector();
	else if (stl == "map")
		; // map_test();
	else if (stl == "stack")
		; // stack_test();
	return 0;
}
