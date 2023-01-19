#include "test.hpp"
#include <AVLtree.hpp>
void print_white(std::string str);

typedef std::pair<int, std::string> T;

void test_avl_tree() {
	print_white("--------------------------------------------------");
	print_white("|                    AVL Tree                    |");
	print_white("--------------------------------------------------");

	test_rotateR();
}


void test_rotateR() {
	std::pair<int, std::string> node1(42, "node1");
	std::pair<int, std::string> node2(50, "node2");
	std::pair<int, std::string> node3(10, "node3");
	std::pair<int, std::string> node4(5, "node4");
	std::pair<int, std::string> node5(21, "node5");
	std::pair<int, std::string> node6(2, "node6");

	ft::AVLtree<T, std::less<int> > root_;
	root_.insert(node1);
	root_.insert(node2);
	root_.insert(node3);
	root_.insert(node4);
	root_.insert(node5);
	root_.insert(node6);
	root_.printAVL(NULL, 1);
}
