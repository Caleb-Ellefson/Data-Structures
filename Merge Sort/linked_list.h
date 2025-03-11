#pragma once
#include <iostream>

class list_node {
public:
	int value;
	list_node* next;

	list_node(int value) {
		this->value = value;
		this->next = nullptr;
	}
};

class linked_list {
private:
	list_node* head;
	list_node* tail;
	int size;

public:
	linked_list() {
		head = tail = nullptr;
		size = 0;
	}

	linked_list(int* array, int length) : linked_list() {
		for (int i = 0; i < length; i++) {
			insert_at_end(array[i]);
		}
	}

	~linked_list() {
		list_node* temp = head;
		while (temp != nullptr) {
			list_node* next = temp->next;
			delete temp;
			temp = next;
		}
	}

	list_node* insert_at_front(int value) {
		list_node* newNode = new list_node(value);

		if (size == 0) {
			head = tail = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
		}

		size++;
		return newNode;
	}

	list_node* insert_at_end(int value) {
		list_node* newNode = new list_node(value);

		if (size == 0) {
			head = tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}

		size++;
		return newNode;
	}

	list_node* get_head() {
		return head;
	}

	list_node* get_tail() {
		return tail;
	}

	int get_size() {
		return size;
	}

	void print() {
		list_node* temp = head;
		while (temp != nullptr) {
			std::cout << temp->value << " -> ";
			temp = temp->next;
		}

		std::cout << "null" << std::endl;
	}
};