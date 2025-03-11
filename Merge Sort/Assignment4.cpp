#include <iostream>
#include <string>
#include <vector>
#include "linked_list.h"

int* binary_merge(int* a, int* b, int lenA, int lenB) {
	int lenC = lenA + lenB;
	int* C = new int [lenC];
	int i = 0, j = 0, c = 0;

	while(i < lenA && j < lenB){
		if(a[i] < b[j]){
			C[c++] = a[i++];
		}
		else{
			C[c++] = b[j++];
		}
	}
	while(i < lenA){
		C[c++] = a[i++];
	}
	while(j < lenB){
		C[c++] = b[j++];
	}
	return C;
}

void merge_sort(int* mergedArray, int left, int right, list_node* leftNode, list_node* rightNode) {
	if (left >= right){
		return;
	}

	int mid = (left + right)/2;
	list_node* midNode = leftNode;

	for (int i = left; i < mid; i++){
	    midNode = midNode->next;
	}

	merge_sort(mergedArray, left, mid, leftNode, midNode);
	merge_sort(mergedArray, mid + 1, right, midNode->next, rightNode);

	int k = left;
	list_node* tmp1 = leftNode;
	list_node* tmp2 = midNode->next;

	while (tmp1 != midNode->next && tmp2 != rightNode->next){
		if(tmp1->value < tmp2->value){
			mergedArray[k++] = tmp1->value;
			tmp1 = tmp1->next;
		}
		else{
			mergedArray[k++] = tmp2->value;
			tmp2 = tmp2->next;
		}
	}
	while(tmp1 != midNode->next){
		mergedArray[k++] = tmp1->value;
		tmp1 = tmp1->next;
	}
	while(tmp2 != rightNode->next){
		mergedArray[k++] = tmp2->value;
		tmp2 = tmp2->next;
	}
	k = left;
	list_node* tmp3 = leftNode;

	while(tmp3 != rightNode->next){
		tmp3->value = mergedArray[k++];
		tmp3 = tmp3->next;
	}	
}
	

//No monty python and the holy grail on this list is a crime btw

std::vector<std::string> common_elements(std::string* A, std::string* B, int lenA, int lenB) {
	std::vector<std::string> C;
	int a = 0, b = 0;

	while(a < lenA && b < lenB){
		if(A[a] < B[b]){
			a++;
		}
		else if(A[a] > B[b]){
			b++;
		}
		else{
			if(C.empty() || C.back() != A[a]){
				C.push_back(A[a]);
			}
			a++;
			b++;
		}
	}


	return C;
}

#pragma region DO NOT MODIFY
std::string letterboxd_top_100[100] = { "12 Angry Men", "A Brighter Summer Day", "A Man Escaped", "A Separation", "A Woman Under the Influence", "All About Eve", "Andrei Rublev", "Apocalypse Now", "Autumn Sonata", "Barry Lyndon", "Before Sunrise", "Before Sunset", "Cinema Paradiso", "City Lights", "City of God", "Close-Up", "Come and See", "Do the Right Thing", "Eternity and a Day", "Everything Everywhere All at Once", "Fanny and Alexander", "Goodfellas", "Grave of the Fireflies", "Harakiri", "High and Low", "I Am Cuba", "Ikiru", "In the Mood for Love", "Incendies", "Inglourious Basterds", "It's a Wonderful Life", "It's Such a Beautiful Day", "La Haine", "Late Spring", "Lawrence of Arabia", "Le Trou", "Love Exposure", "M", "Memories of Murder", "Mirror", "Mishima: A Life in Four Chapters", "Neon Genesis Evangelion: The End of Evangelion", "Nights of Cabiria", "No Country for Old Men", "Oldboy", "Once Upon a Time in the West", "One Flew Over the Cuckoo's Nest", "Parasite", "Paris Texas", "Paths of Glory", "Perfect Blue", "Persona", "Portrait of a Lady on Fire", "Princess Mononoke", "Psycho", "Ran", "Rear Window", "Sansho the Bailiff", "Satantango", "Scenes from a Marriage", "Schindler's List", "Seven Samurai", "Sherlock Jr.", "Spider-Man: Across the Spider-Verse", "Spider-Man: Into the Spider-Verse", "Spirited Away", "Stalker", "Star Wars: Episode V - The Empire Strikes Back", "Sunset Boulevard", "The 400 Blows", "The Apartment", "The Ascent", "The Battle of Algiers", "The Cranes Are Flying", "The Dark Knight", "The Godfather", "The Godfather: Part II", "The Good the Bad and the Ugly", "The Handmaiden", "The Human Condition I: No Greater Love", "The Human Condition II: Road to Eternity", "The Human Condition III: A Soldier's Prayer", "The Lord of the Rings: The Fellowship of the Ring", "The Lord of the Rings: The Return of the King", "The Lord of the Rings: The Two Towers", "The Passion of Joan of Arc", "The Pianist", "The Red Shoes", "The Seventh Seal", "The Shawshank Redemption", "The Silence of the Lambs", "The Thing", "There Will Be Blood", "Three Colours: Red", "Tokyo Story", "Where Is the Friend's House?", "Whiplash", "Wild Strawberries", "Woman in the Dunes", "Yi Yi" };
std::string imdb_top_100[100] = { "12 Angry Men", "2001: A Space Odyssey", "3 Idiots", "A Clockwork Orange", "Alien", "Aliens", "Amadeus", "American Beauty", "American History X", "Apocalypse Now", "Avengers: Endgame", "Avengers: Infinity War", "Back to the Future", "Braveheart", "Capernaum", "Casablanca", "Cinema Paradiso", "City Lights", "City of God", "Coco", "Come and See", "Das Boot", "Django Unchained", "Dr. Strangelove or: How I Learned to Stop Worrying and Love the Bomb", "Eternal Sunshine of the Spotless Mind", "Fight Club", "Forrest Gump", "Full Metal Jacket", "Gladiator", "Good Will Hunting", "Goodfellas", "Grave of the Fireflies", "Hamilton", "Harakiri", "Heat", "High and Low", "Inception", "Inglourious Basterds", "Interstellar", "It's a Wonderful Life", "Jai Bhim", "Joker", "Leon: The Professional", "Life Is Beautiful", "Memento", "Modern Times", "Oldboy", "Once Upon a Time in America", "Once Upon a Time in the West", "One Flew Over the Cuckoo's Nest", "Oppenheimer", "Parasite", "Paths of Glory", "Psycho", "Pulp Fiction", "Raiders of the Lost Ark", "Rear Window", "Requiem for a Dream", "Reservoir Dogs", "Saving Private Ryan", "Scarface", "Schindler's List", "Se7en", "Seven Samurai", "Spider-Man: Across the Spider-Verse", "Spider-Man: Into the Spider-Verse", "Spirited Away", "Star Wars: Episode IV - A New Hope", "Star Wars: Episode V - The Empire Strikes Back", "Sunset Boulevard", "Terminator 2: Judgment Day", "The Dark Knight", "The Dark Knight Rises", "The Departed", "The Godfather", "The Godfather: Part II", "The Good the Bad and the Ugly", "The Great Dictator", "The Green Mile", "The Hunt", "The Intouchables", "The Lion King", "The Lives of Others", "The Lord of the Rings: The Fellowship of the Ring", "The Lord of the Rings: The Return of the King", "The Lord of the Rings: The Two Towers", "The Matrix", "The Pianist", "The Prestige", "The Shawshank Redemption", "The Shining", "The Silence of the Lambs", "The Usual Suspects", "Top Gun: Maverick", "Toy Story", "Up", "WALLE", "Whiplash", "Witness for the Prosecution", "Your Name." };

void merge_sort(linked_list* list) {
	int* mergedArray = new int[list->get_size()];
	merge_sort(mergedArray, 0, list->get_size() - 1, list->get_head(), list->get_tail());
}

void print(int* array, int length) {
	std::cout << '[';

	for (int i = 0; i < length - 1; i++) {
		std::cout << array[i] << ", ";
	}

	std::cout << array[length - 1] << ']' << std::endl;
}

int main() {
	// PART 1
	std::cout << "Part 1: Binary Merge" << std::endl;

	const int lenA = 12;
	const int lenB = 13;
	int* a = new int[lenA] { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24 };
	int* b = new int[lenB] { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25 };

	std::cout << "Merging:" << std::endl;
	print(a, 12);
	std::cout << "With:" << std::endl;
	print(b, 13);

	int* c = binary_merge(a, b, lenA, lenB);

	std::cout << "Result:" << std::endl;
	print(c, lenA + lenB);

	// PART 2
	std::cout << "\nPart 2: Linked List Merge Sort" << std::endl;

	const int lenNums = 25;
	int* nums = new int[lenNums] { 16, 16, 15, 14, 9, 8, 21, 0, 7, 6, 7, 7, 9, 18, 1, 20, 24, 6, 19, 21, 7, 22, 17, 7, 14 };
	linked_list* list = new linked_list(nums, lenNums);

	std::cout << "Before:" << std::endl;
	list->print();

	merge_sort(list);

	std::cout << "After:" << std::endl;
	list->print();

	// PART 3
	std::cout << "\nPart 3: Common Elements" << std::endl;

	std::vector<std::string> sharedMovies = common_elements(letterboxd_top_100, imdb_top_100, 100, 100);

	std::cout << "Letterboxd/IMDB Consensus Top " << sharedMovies.size() << " Movies:" << std::endl;
	for (int i = 0; i < sharedMovies.size(); i++) {
		std::string movie = sharedMovies[i];
		std::cout << "\t" << i + 1 << ")\t" << movie << std::endl;
	}

	delete[] a;
	delete[] b;
	delete[] c;
	delete[] nums;
	delete list;
	return 0;
}
#pragma endregion