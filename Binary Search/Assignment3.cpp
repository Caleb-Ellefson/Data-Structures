#include <iostream>

int min_index_binary_search(int* array, int length, int key) {
	int left = 0;
	int right = length - 1;
	int min_Index = -1;
	while(left <= right){
		int mid = (left + right) / 2;
		if(array[mid] == key){
			min_Index = mid;
			right = mid-1;
		}
		else if (array[mid] > key){
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}
	}

	return min_Index;
}

int max_index_binary_search(int* array, int length, int key) {
	int left = 0;
	int right = length - 1;
	int max_Index = -1;
	while(left <= right){
		int mid = (left + right) / 2;
		if(array[mid] == key){
			max_Index = mid;
			left = mid+1;
		}
		else if (array[mid] > key){
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}
	}

	return max_Index;
}

int count_number_of_keys(int* array, int length, int key) {
	int min_Index = min_index_binary_search(array, length, key);
	int max_Index = max_index_binary_search(array , length , key);

	if (min_Index == -1 || max_Index == -1){
		return 0;
	}

	return (max_Index - min_Index + 1);
}


int predecessor(int* array, int length, int key) {
	int left = 0;
	int right = length - 1;
	int pred = -1;
	while(left <= right){
		int mid = (left + right) / 2;

		if(array[mid] == key){
			return array[mid];
		}
		else if (array[mid] < key){
			//indexing outside of the array on the last value?
			pred = mid;
			left = mid + 1;
		}
		else{
			right = mid - 1;
		}
	}

	return pred;
}

int find_peak(int* array, int length) {
	int left = 0;
	int right = length - 1;
	int peak = -1;
	while(left <= right){
		int mid = (left + right) / 2;

		if(left == right){
			return left;
		}
		else if (right == left + 1){
			if(array[left] > array[right]){
				return left;
			}
			return right;
		}

		mid = (left + right) / 2;
		if( array[mid] < array[mid + 1]){

			left = mid + 1;
		}
		else if(array[mid] < array[mid - 1]){

			right = mid - 1;
		}
		else{
			return mid;
		}
	}

	return peak;
}

void print(int* array, int length) {
	std::cout << '[';

	for (int i = 0; i < length - 1; i++) {
		std::cout << array[i] << ", ";
	}

	std::cout << array[length - 1] << ']' << std::endl;
}

#pragma region DO NOT MODIFY
int main() {
	std::cout << "Part 1: Frequency" << std::endl;
	int a[] = { 1, 1, 3, 7, 9, 14, 14, 14, 14, 14, 14, 18, 27, 39, 39, 39 };
	std::cout << "Array is ";
	print(a, 16);
	int testKeysA[] = { 1, 14, 39, 7, 100, -88, 16 };
	for (int i = 0; i < 7; i++) {
		int key = testKeysA[i];
		std::cout << "Frequency of " << key << " is " << count_number_of_keys(a, 16, key) << std::endl;
	}

	std::cout << "\nPart 2: Predecessor" << std::endl;
	int testKeysB[] = { 1, 0, 39, 47, 36, 12, 6 };
	std::cout << "Array is ";
	print(a, 16);
	for (int i = 0; i < 7; i++) {
		int key = testKeysB[i];
		int p = predecessor(a, 16, key);

		if (p == -1) {
			std::cout << "Predecessor of " << key << " is undefined" << std::endl;
		}
		else {
			std::cout << "Predecessor of " << key << " is " << a[p] << std::endl;
		}
	}

	std::cout << "\nPart 3: Peak Finding" << std::endl;
	int c1[] = { 15, 18, 21, 25, 29, 31, 35, 23, 14, 9, 1, -1 };
	std::cout << "Array is ";
	print(c1, sizeof(c1) / sizeof(int));
	int peak = find_peak(c1, sizeof(c1) / sizeof(int));
	std::cout << "Peak is " << c1[peak] << " at index " << peak << std::endl;

	int c2[] = { 31, 35, 23, 14, 9, 1, -1 };
	std::cout << "Array is ";
	print(c2, sizeof(c2) / sizeof(int));
	peak = find_peak(c2, sizeof(c2) / sizeof(int));
	std::cout << "Peak is " << c2[peak] << " at index " << peak << std::endl;

	int c3[] = { 31, 35, 37, 39 };
	std::cout << "Array is ";
	print(c3, sizeof(c3) / sizeof(int));
	peak = find_peak(c3, sizeof(c3) / sizeof(int));
	std::cout << "Peak is " << c3[peak] << " at index " << peak << std::endl;

	int c4[] = { 36, 35, 32, 29 };
	std::cout << "Array is ";
	print(c4, sizeof(c4) / sizeof(int));
	peak = find_peak(c4, sizeof(c4) / sizeof(int));
	std::cout << "Peak is " << c4[peak] << " at index " << peak << std::endl;

	return 0;
}
#pragma endregion