#include "test.hpp"

int main(int argc, char const *argv[]) {

	if (argc != 2) {
		std::cerr << "Please select STL (vector or stack or map)" << std::endl;
		return 1;
	}

	std::string stl(argv[1]);
	if (stl == "test") {
		tester_vector();
		tester_stack();
		tester_map();
	}
	else if (stl == "vector")
		tester_vector();
	else if (stl == "map")
		tester_map();
	else if (stl == "stack")
		tester_stack();
	return 0;
}
