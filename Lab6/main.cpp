#include "classes.h"

int main() {
	int n = -1;
	while (n < 1) {
		std::cout << "Enter n:\n";
		std::cin >> n;
	}
	Tree myTree;
	myTree.createTree(n);
	std::cout << "Tree:\n\n";
	myTree.print();
	return 0;
}