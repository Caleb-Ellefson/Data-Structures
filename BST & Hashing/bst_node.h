#pragma once
#include <iostream>

struct bst_node {
	int value;
	bst_node* left;
	bst_node* right;
	bst_node* parent;

	bst_node(int value) {
		this->value = value;
		left = right = parent = nullptr;
	}

	~bst_node() {
		delete left;
		delete right;
	}

	void print() {
		if (parent == nullptr) {
			std::cout << "<" << value << ", null>";
		}
		else {
			std::cout << "<" << value << ", " << parent->value << ">";
		}
	}
};