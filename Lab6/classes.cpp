#include "classes.h"
#include <iomanip>

Node* Tree::createTree(int n, int max) {

	Node* current = new Node(n);
	if (n < max) {
		n++;
		current->left = createTree(n, max);
		current->right = createTree(n, max);
	}
	return current;
}

void Tree::createTree(int n) {
	root = createTree(1, n);
}

void Tree::print(Node* node, int level) {
	if (node) {
		print(node->left, level + 1);
		std::cout << std::setw(level * 6) << node->data << std::endl;
		print(node->right, level + 1);
	}
}

void Tree::print() {
	print(root, 0);
}