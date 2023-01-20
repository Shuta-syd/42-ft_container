#include "test.hpp"
#include <AVLtree.hpp>
void test_rotateR();
void test_rotateL();
void test_rotateLR();
void test_rotateRL();
void test_erase_no_rotate();
void test_erase_balance1();
void test_erase_balance2();
void test_erase_balance3();

typedef std::pair<int, std::string> T;

void test_avl_tree() {
	print_white("--------------------------------------------------");
	print_white("|                    AVL Tree                    |");
	print_white("--------------------------------------------------");

	// test_rotateR();
	// test_rotateL();
	// test_rotateLR();
	// test_rotateRL();
	test_erase_no_rotate();
	test_erase_balance1();
	test_erase_balance2();
}

void test_rotateR() {
	print_white("--------------------------------------------------");
	print_white("|                  TEST rotateR                  |");
	print_white("--------------------------------------------------");
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

void test_rotateL() {
	print_white("--------------------------------------------------");
	print_white("|                  TEST rotateL                  |");
	print_white("--------------------------------------------------");
	std::pair<int, std::string> node1(42, "node1");
	std::pair<int, std::string> node2(21, "node2");
	std::pair<int, std::string> node3(50, "node3");
	std::pair<int, std::string> node4(60, "node4");
	std::pair<int, std::string> node5(45, "node5");
	std::pair<int, std::string> node6(70, "node6");

	ft::AVLtree<T, std::less<int> > root_;
	root_.insert(node1);
	root_.insert(node2);
	root_.insert(node3);
	root_.insert(node4);
	root_.insert(node5);
	root_.insert(node6);
	root_.printAVL(NULL, 1);
}

void test_rotateLR() {
	print_white("--------------------------------------------------");
	print_white("|                 TEST rotateLR                  |");
	print_white("--------------------------------------------------");
	std::pair<int, std::string> node1(42, "node1");
	std::pair<int, std::string> node2(30, "node2");
	std::pair<int, std::string> node3(50, "node3");
	std::pair<int, std::string> node4(60, "node4");
	std::pair<int, std::string> node5(12, "node5");
	std::pair<int, std::string> node6(35, "node6");
	std::pair<int, std::string> node7(31, "node6");
	std::pair<int, std::string> node8(36, "node6");
	std::pair<int, std::string> node9(10, "node6");
	std::pair<int, std::string> node10(37, "node6");

	ft::AVLtree<T, std::less<int> > root_;
	root_.insert(node1);
	root_.insert(node2);
	root_.insert(node3);
	root_.insert(node4);
	root_.insert(node5);
	root_.insert(node6);
	root_.insert(node7);
	root_.insert(node8);
	root_.insert(node9);
	root_.insert(node10);
	root_.printAVL(NULL, 1);
}

void test_rotateRL() {
	print_white("--------------------------------------------------");
	print_white("|                 TEST rotateRL                  |");
	print_white("--------------------------------------------------");
	std::pair<int, std::string> node1(42, "node1");
	std::pair<int, std::string> node2(30, "node2");
	std::pair<int, std::string> node3(90, "node3");
	std::pair<int, std::string> node4(70, "node4");
	std::pair<int, std::string> node5(20, "node5");
	std::pair<int, std::string> node6(100, "node6");
	std::pair<int, std::string> node7(60, "node6");
	std::pair<int, std::string> node8(80, "node6");
	std::pair<int, std::string> node9(120, "node6");
	std::pair<int, std::string> node10(50, "node6");

	ft::AVLtree<T, std::less<int> > root_;
	root_.insert(node1);
	root_.insert(node2);
	root_.insert(node3);
	root_.insert(node4);
	root_.insert(node5);
	root_.insert(node6);
	root_.insert(node7);
	root_.insert(node8);
	root_.insert(node9);
	root_.insert(node10);
	root_.printAVL(NULL, 1);
}


void test_erase_no_rotate() {
	print_white("--------------------------------------------------");
	print_white("|              TEST erase no rotate              |");
	print_white("--------------------------------------------------");
	std::pair<int, std::string> node1(42, "node1");
	std::pair<int, std::string> node2(30, "node2");
	std::pair<int, std::string> node3(90, "node3");
	std::pair<int, std::string> node4(20, "node4");
	std::pair<int, std::string> node5(35, "node5");

	ft::AVLtree<T, std::less<int> > root_;
	root_.insert(node1);
	root_.insert(node2);
	root_.insert(node3);
	root_.insert(node4);
	root_.insert(node5);
	root_.printAVL(NULL, 1);
	std::cout << std::endl;
	root_.erase(30);
	root_.printAVL(NULL, 1);
}


void test_erase_balance1() {
	print_white("--------------------------------------------------");
	print_white("|              TEST erase balance 1              |");
	print_white("--------------------------------------------------");
	std::pair<int, std::string> node1(42, "node1");
	std::pair<int, std::string> node2(30, "node2");
	std::pair<int, std::string> node3(90, "node3");
	std::pair<int, std::string> node5(35, "node5");
	std::pair<int, std::string> node4(20, "node4");

	ft::AVLtree<T, std::less<int> > root_;
	root_.insert(node1);
	root_.insert(node2);
	root_.insert(node3);
	root_.insert(node4);
	root_.insert(node5);
	root_.printAVL(NULL, 1);
	std::cout << std::endl;
	root_.erase(90);
	root_.printAVL(NULL, 1);
}

void test_erase_balance2() {
	print_white("--------------------------------------------------");
	print_white("|              TEST erase balance 2              |");
	print_white("--------------------------------------------------");
	std::pair<int, std::string> node1(80, "node1");
	std::pair<int, std::string> node2(90, "node2");
	std::pair<int, std::string> node3(50, "node3");
	std::pair<int, std::string> node4(42, "node4");
	std::pair<int, std::string> node5(95, "node5");
	std::pair<int, std::string> node6(55, "node6");

	ft::AVLtree<T, std::less<int> > root_;
	root_.insert(node1);
	root_.insert(node2);
	root_.insert(node3);
	root_.insert(node4);
	root_.insert(node5);
	root_.insert(node6);
	root_.printAVL(NULL, 1);
	std::cout << std::endl;
	root_.erase(80);
	root_.printAVL(NULL, 1);
}
