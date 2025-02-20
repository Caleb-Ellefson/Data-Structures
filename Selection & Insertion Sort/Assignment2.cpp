#include <chrono>
#include <string>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <vector>

void selection_sort(std::string* array, int length);
void insertion_sort(std::string* array, int length);

int main() {
	std::string* paths = new std::string[8]{
		"./names/names-1k-unsorted.csv",
		"./names/names-10k-unsorted.csv",
		"./names/names-50k-unsorted.csv",
		"./names/names-100k-unsorted.csv",
		"./names/names-1k-sorted.csv",
		"./names/names-10k-sorted.csv",
		"./names/names-50k-sorted.csv",
		"./names/names-100k-sorted.csv",
	};

	for (int i = 0; i < 8; i++) {
		std::string path = paths[i];
		std::vector<std::string> names;
		std::ifstream input;
		input.open(path);

		if (input.is_open()) {
			std::string line;
			while (std::getline(input, line)) {
				names.push_back(line);
			}
			input.close();
		}
		else {
			std::cout << "Unable to open file: " << path << std::endl;
			return 1;
		}

		std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
		selection_sort(names.data(), names.size());
		std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
		std::cout << path << " took " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "ms to Selection Sort" << std::endl;
	}

	for (int i = 0; i < 8; i++) {
		std::string path = paths[i];
		std::vector<std::string> names;
		std::ifstream input;
		input.open(path);

		if (input.is_open()) {
			std::string line;
			while (std::getline(input, line)) {
				names.push_back(line);
			}
			input.close();
		}
		else {
			std::cout << "Unable to open file: " << path << std::endl;
			return 1;
		}

		std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
		insertion_sort(names.data(), names.size());
		std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
		std::cout << path << " took " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "ms to Insertion Sort" << std::endl;
	}

	delete[] paths;
	return 0;
}

void selection_sort(std::string* array, int length){
	for (int i = 0; i < length -1; i++ ){
		int min_index = i;
	

		for (int j = i + 1; j < length; j++){
			if(array[j] < array[min_index]){
				min_index = j;
			}
		}
		if (min_index != i ){
			std::swap(array[i], array[min_index]);
		}
	}
}

void insertion_sort(std::string* array, int length){
	for (int i = 1; i < length; i++){
		int j = i;
		std::string temp = array[j];

		while(j > 0 && temp < array[j-1]){
			array[j] = array[j-1];
			j--;
		}
		array[j] = temp;
	}
}