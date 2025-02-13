#include <iostream>
#include <stdexcept>

template <typename T>
class Stack {
private:
	int MAX_SIZE = 5;
	//stack starts empty
	int top_of_stack = -1;
	T array[MAX_SIZE];

public:

	T PUSH(T value){
		if(top_of_stack == MAX_SIZE-1){
			throw std::runtime_error("stack is full")
		}
		else{
			//PRE-INCREMENT THE TOP OF STACK FIRST
			array[++top_of_stack]=value;
		}
	}

	T POP(){
		if (top_of_stack == -1){
			throw std::runtime_error("stack is empty")
		}
		else{
			//POST-INCREMENT return value THEN change the index
			//No need to set the value to NULL it will just be overwriten
			return array[top_of_stack--];
		}
	}

	PEEK(){
		if (top_of_stack == -1){
			throw std::runtime_error("stack is empty")
		}
		else{
			return array[top_of_stack];
		}
	}

	SIZE(){
		return top_of_stack+1;
	}
}

int main(){
	try{
		
		
	}
	catch(const std::runtime_error& e){
		std::cout << e.what() << std::endl;
	}

}