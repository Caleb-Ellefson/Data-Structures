#include <iostream>
#include <vector>
#include "bst.h"
#include "bst_node.h"
#include "hashtable.h"

int nums_to_insert[] = { 11, 12, 15, 17, 12, 19, 4, 5, 11, 19, 20, 32, 77, 65, 66, 88, 99, 10, 8, 19, 15, 66, 11, 19, 0, 3, 2, 55, 67, 78, 39 };
const int insert_length = sizeof(nums_to_insert) / sizeof(int);
int nums_to_search[] = { 29, 3, 19, 27, 12, 34, 4, 5, 19, 20, 32, 45, 37, 25, 99, 25, 8, 24, 12, 16 };
const int search_length = sizeof(nums_to_search) / sizeof(int);
int nums_to_delete[] = { 11, 16, 12, 15, 5, 17, 19, 4, 5, 20, 32, 17, 19, 39, 99, 10, 8, 19, 15, 21, 0, 55, 3, 78, 66 };
const int delete_length = sizeof(nums_to_delete) / sizeof(int);

void print(int* array, int table_size) {
	std::cout << '[';

	for (int i = 0; i < table_size - 1; i++) {
		std::cout << array[i] << ", ";
	}

	std::cout << array[table_size - 1] << ']' << std::endl;
}

void test_bst(bst* tree) {
	std::cout << "Inserting: ";
	print(nums_to_insert, insert_length);
	std::cout << std::endl;

	for (int i = 0; i < insert_length; i++) {
		tree->insert(nums_to_insert[i]);
	}

	std::cout << "Tree (After Insertion): " << std::endl;
	tree->print();
	std::cout << std::endl;

	std::cout << "Searching..." << std::endl;
	std::vector<int> found, not_found;

	for (int i = 0; i < search_length; i++) {
		bst_node* node = tree->search(nums_to_search[i]);

		if (node == nullptr) {
			not_found.push_back(nums_to_search[i]);
		}
		else {
			found.push_back(node->value);
		}
	}

	std::cout << "Found: ";
	print(found.data(), found.size());

	std::cout << "Not Found: ";
	print(not_found.data(), not_found.size());
	std::cout << std::endl;

	std::cout << "Deleting..." << std::endl;
	std::vector<int> deleted, not_deleted;

	for (int i = 0; i < delete_length; i++) {
		bool success = tree->remove(nums_to_delete[i]);

		if (success) {
			deleted.push_back(nums_to_delete[i]);
		}
		else {
			not_deleted.push_back(nums_to_delete[i]);
		}
	}

	std::cout << "Deleted: ";
	print(deleted.data(), deleted.size());

	std::cout << "Not Deleted: ";
	print(not_deleted.data(), not_deleted.size());
	std::cout << std::endl;

	std::cout << "Tree (After Deletion): " << std::endl;
	tree->print();
	std::cout << std::endl;
}

void test_hashtable(hashtable* table) {
	std::cout << "Inserting: ";
	print(nums_to_insert, insert_length);
	std::cout << std::endl;

	std::vector<int> inserted, not_inserted;

	for (int i = 0; i < insert_length; i++) {
		bool result = table->insert(nums_to_insert[i]);

		if (result) {
			inserted.push_back(nums_to_insert[i]);
		}
		else {
			not_inserted.push_back(nums_to_insert[i]);
		}
	}

	std::cout << "Inserted: ";
	print(inserted.data(), inserted.size());

	std::cout << "Not Inserted: ";
	print(not_inserted.data(), not_inserted.size());
	std::cout << std::endl;

	std::cout << "Table (After Insertion): " << std::endl;
	table->print();
	std::cout << std::endl;

	std::cout << "Size of Table: " << table->get_count() << std::endl;
	std::cout << std::endl;

	std::cout << "Searching..." << std::endl;
	std::vector<int> found, not_found;

	for (int i = 0; i < search_length; i++) {
		bool result = table->search(nums_to_search[i]);

		if (result) {
			found.push_back(nums_to_search[i]);
		}
		else {
			not_found.push_back(nums_to_search[i]);
		}
	}

	std::cout << "Found: ";
	print(found.data(), found.size());

	std::cout << "Not Found: ";
	print(not_found.data(), not_found.size());
	std::cout << std::endl;

	std::cout << "Deleting..." << std::endl;
	std::vector<int> deleted, not_deleted;

	for (int i = 0; i < delete_length; i++) {
		bool success = table->remove(nums_to_delete[i]);

		if (success) {
			deleted.push_back(nums_to_delete[i]);
		}
		else {
			not_deleted.push_back(nums_to_delete[i]);
		}
	}

	std::cout << "Deleted: ";
	print(deleted.data(), deleted.size());

	std::cout << "Not Deleted: ";
	print(not_deleted.data(), not_deleted.size());
	std::cout << std::endl;

	std::cout << "Table (After Deletion): " << std::endl;
	table->print();
	std::cout << std::endl;

	std::cout << "Size of Table: " << table->get_count() << std::endl;
	std::cout << std::endl;
}

int main() {
	std::cout << "Part 1: Binary Search Tree" << std::endl << std::endl;
	bst* tree = new bst();
	test_bst(tree);

	std::cout << "Part 2: Hash Table with Chaining" << std::endl << std::endl;
	hashtable* table = new hashtable(7);
	test_hashtable(table);

	delete tree;
	delete table;

	return 0;
}