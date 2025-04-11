#include <iostream>
#include "bst_node.h"

#pragma region DO NOT MODIFY
class bst {
public:
	//ptr to root
	bst_node* root;

	bst() {
		root = nullptr;
	}

	bst(int* arr, int length) {
		root = nullptr;
		for (int i = 0; i < length; i++) {
			insert(arr[i]);
		}
	}

	~bst() {
		delete root;
	}

	void print() {
		print(root);
		std::cout << std::endl;
	}

private:
	void print(bst_node* node) {
		if (node == nullptr) {
			return;
		}

		node->print();
		std::cout << ' ';

		print(node->left);
		print(node->right);
	}
#pragma endregion

public:
	//return ptr node
	bst_node* search(int key) {
		//start at root?
		bst_node* current = root;

		while (current != nullptr){
		//if x == key return true
			if (key == current->value){
				return current;
			}
			//if key < x key can only be found in nodes left of x
			else if (key < current->value){
				current = current->left;
			}
			else{
				current = current->right;
			}
	}
	return nullptr;
}

	bst_node* insert(int key) {
		//if root
		if(root == nullptr){
			root = new bst_node(key);
			return root;
		}

		bst_node* current = root;
		bst_node* parent = nullptr;

		while( current != nullptr){
			parent = current;

			if (key == current->value){
				return current;
			}
			else if (key <current->value){
				current = current->left;
			}
			else{
				current = current->right;
			}
		}

		bst_node* new_node = new bst_node(key);
		new_node->parent = parent;

		if (key < parent->value){
			parent->left = new_node;
		}
		else{
			parent->right = new_node;
		}

		return new_node;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
	}

	bool remove(int key) {
		bst_node* node_to_delete = search(key);
		if (node_to_delete == nullptr){
			return false;
		}
		//case 3
		if (node_to_delete->left != nullptr && node_to_delete->right != nullptr){
			bst_node* max = find_max(node_to_delete);
			node_to_delete->value = max->value;
			node_to_delete = max;
		}
		//case 1
		if (node_to_delete->left == nullptr && node_to_delete->right == nullptr){
			remove_leaf(node_to_delete);
		}
		//case 2 1 child
		else{
			remove_one_child(node_to_delete);
		}
		return true;

	}

private:
	bst_node* find_max(bst_node* node) {
		if (node == nullptr){
			return nullptr;
		}
		while (node->right != nullptr){
			node = node->right;
		}
		return node;
	}

	void remove_leaf(bst_node* leaf) {
		if(leaf == root){
			delete root;
			root = nullptr;
		}
		else{
			bst_node* parent = leaf->parent;
			if(parent->left == leaf){
				parent->left = nullptr;
			}
			else{
				parent->right = nullptr;
			}
			parent = nullptr;
			delete leaf;
		}

	}

	void remove_one_child(bst_node* node) {
		bst_node* child;

		if (node->left != nullptr){
			child = node->left;
			node->left = nullptr;
		}
		else{
			child = node->right;
			node->right = nullptr;
		}
		if(node == root){
			root = child;
			child->parent = nullptr;
			delete node;
		}
		else{
			if (node == node->parent->left){
				node->parent->left = child;
			}
			else{
				node->parent->right = child;
			}
			child->parent = node->parent;
			node->parent = nullptr;
			delete node;
		}
	}
};
