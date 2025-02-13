#include <iostream>
#include <stdexcept>
#include <iomanip>

template <typename T>
class Stack {
private:
	static const int MAX_SIZE = 5;
	//stack starts empty
	int top_of_stack = -1;
	T array[MAX_SIZE];

public:

	void PUSH(T value){
		if(top_of_stack == MAX_SIZE-1){
			 std::cout<<"stack is full"<<std::endl;
			 return;
		}
		else{
			//PRE-INCREMENT THE TOP OF STACK FIRST
			array[++top_of_stack]=value;
		}
	}

	T POP(){
		if (top_of_stack == -1){
			 std::cout<<"stack is empty"<<std::endl;
			 return T();
		}
		else{
			//POST-INCREMENT return value THEN change the index
			//No need to set the value to NULL it will just be overwriten
			return array[top_of_stack--];
		}
	}

	T PEEK(){
		if (top_of_stack == -1){
			 std::cout<<"stack is empty"<<std::endl;
			 return T();
		}
		else{
			return array[top_of_stack];
		}
	}

	int SIZE(){
		return top_of_stack+1;
	}

	void print_stack(){
		if (top_of_stack == -1){
			return;
		}
		for (int i = 0; i <= top_of_stack; i++){
		 std::cout << std::right << array[i];
		 if (i != top_of_stack){
		 	std::cout << ",";
		 }
		}
	}

	void print() {
		std::cout<<"[";
		print_stack();
		std::cout <<"]";

		std::cout <<
		std::setw(20)
		<< std::right
		<< std::setw(10) 
		<< top_of_stack
		<< std::setw(10) 
		<< SIZE()
		<< std::endl;

	}

};

int main(){
	try{
		Stack<std::string> s;
		        // Push some values to the stack
        std::cout <<"Stack Content"
        << std::right
        << std::setw(50) << "Top" 
        << std::setw(50) << "Size\n" 
        << std::endl;


        s.PUSH("C");
        s.print();
        s.PUSH("S");
        s.print();
        s.PUSH("-");
        s.print();
        s.PUSH("2");
        s.print();
        s.PUSH("2");
        s.print();
        s.PUSH("1");
        s.print();
        s.POP();
        s.print();
        s.POP();
        s.print();
        s.POP();
        s.print();
        s.PUSH("2");
        s.print();
        s.PUSH("2");
        s.print();
        s.PUSH("1");
        s.print();
      	s.POP();
      	s.print();
      	s.PUSH("3");
      	s.print();
      	s.POP();
      	s.print();
      	s.POP();
      	s.print();
      	s.POP();
      	s.print();
      	s.POP();
      	s.print();
      	s.POP();
      	s.print();
      	s.POP();
      	s.print();





		
	}
	catch(const std::runtime_error& e){
		std::cout << e.what() << std::endl;
	}

}