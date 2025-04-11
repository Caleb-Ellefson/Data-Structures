#pragma once
#include <list>
#include <iostream>

#pragma region DO NOT MODIFY
class hashtable {
private:
	int table_size;
	int count;
	std::list<int>* table;

public:
	hashtable(int table_size) {
		this->table_size = table_size;
		table = new std::list<int>[table_size];
		count = 0;
	}

	~hashtable() {
		delete[] table;
	}

	int get_count() {
		return count;
	}
#pragma endregion

private:
	int compute_hash(int key) {

		//H(x) =(37x + 61 ) % TABLE_SIZE;
		return ((37 * key) + 61) % table_size;
	}

public:
	bool insert(int key) {
		if (search(key)){
			return false;
		}
		int hash = compute_hash(key);
		table[hash].push_back(key);
		count++;
		return true;

	}

	bool remove(int key) {
		int hash = compute_hash(key);
		std::list<int> &list = table[hash];

		for (auto i = list.begin(); i != list.end(); ++i){
			if(*i == key){
				list.erase(i);
				count--;
				return true;
			}
		}
		return false;
	}

	bool search(int key) {
		int hash = compute_hash(key);

		std::list<int> &list = table[hash];

		for (auto i = list.begin(); i != list.end(); ++i){
			if(*i == key){
				return true;
			}
		}
		return false;
	}

	void print() {
		for (int i = 0; i < table_size; ++i) {
			std::cout << "Slot " << i << ": ";

			std::list<int>& list = table[i];
			for (int val : list) {
				std::cout << val << " ";
		}

		std::cout << std::endl;
	}
	}
};