#include "test.hpp"
#include <AVLtree.hpp>
void print_white(std::string str);

typedef std::pair<int, std::string> T;

void test_avl_tree() {
	print_white("--------------------------------------------------");
	print_white("|                    AVL Tree                    |");
	print_white("--------------------------------------------------");

	std::pair<int, std::string> node1(13, "node1");
	std::pair<int, std::string> node2(50, "node2");
	std::pair<int, std::string> node3(42, "node3");
	std::pair<int, std::string> node4(21, "node4");
	std::pair<int, std::string> node5(43, "node5");
	std::pair<int, std::string> node6(80, "node6");
	std::pair<int, std::string> node7(82, "node7");
	std::pair<int, std::string> node8(83, "node8");

	ft::AVLtree<T, std::less<int> > root_;
	root_.insert(node1);
	root_.insert(node2);
	root_.insert(node3);
	root_.insert(node4);
	root_.insert(node5);
	root_.insert(node6);
	root_.insert(node7);
	root_.insert(node8);

	/**
	 * 13
	 *		50
	 		42  80
		 21 43  82
		          83
	 */
	root_.printAVL(NULL, 1);
}
