#pragma once
#include <iostream>
struct Node {
	int data;
	Node* right, * left;
	Node(int data) : data(data), right(NULL), left(NULL) {}

};

class Tree {
	Node* root;
public:
	Tree() : root(NULL) {}

	Node* getRoot() { return root; }
	void setRoot(Node* root) { this->root = root; }

	Node* createTree(int n, int max);
	void createTree(int n);

	void print(Node* node, int level);
	void print();
};