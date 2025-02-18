#include <iostream>
#include <stdexcept>
#include <iomanip>

template <typename T>
class Queue {
private:
	const static int MAX_SIZE = 5;
	int queue_size = 0;
	int front = 0;
	int rear = 0;
	int spacing = 0;
	T array[MAX_SIZE];

public:
	void ENQUEUE (T value){
		if (queue_size == MAX_SIZE){
				std::cout<<"Queue is full"<<std::endl;
				return;
		}
		else{
			if (rear == MAX_SIZE){
				rear = 0;
			}
			array[rear++] = value;
			queue_size++;
		}
	}

	T DEQUEUE (){
		if (queue_size == 0){
			std::cout<<"Queue is empty"<<std::endl;
			return T();
		}
		else{
			T value = array[front++];
			queue_size--;
			if (front == MAX_SIZE){
				front = 0;
			}
			return value;
		}
	}

	T PEEK(){
		if (queue_size == 0){
			std::cout<<"Queue is empty"<<std::endl;
			return T();
		}
		else{
			return array[front];
		}
	}

	int SIZE(){
		return queue_size;
	}

	//dynamic get the size of the queue then use that to even spacing the output
    std::string get_queue_contents() {
        std::ostringstream oss;
        oss << "[";
        if (queue_size > 0) {
            int index = front;
            for (int i = 0; i < queue_size; i++) {
                oss << array[index];
                if (i != queue_size - 1) {
                    oss << ", ";
                }
                index = (index + 1) % MAX_SIZE;
            }
        }
        oss << "]";
        return oss.str();
    }


	void print_queue(){
		if (queue_size == 0){
			return;
		}
		for (int i = 0; i < queue_size; i++){
		 std::cout << array[i];
		 if (i != queue_size - 1){
		 	std::cout << ",";
		 }
		}
	}

    void print() {
        std::cout << std::setw(40) << std::left << get_queue_contents()
                  << std::setw(15) << std::right << front
                  << std::setw(15) << rear
                  << std::setw(15) << SIZE()
                  << std::endl;
    }
};

	


int main(){


	Queue<std::string> s;

    std::cout << "Queue Contents"
    << std::setw(43) << "Front" 
    << std::setw(15) << "Rear" 
    << std::setw(15) << "Size\n" 
    << std::endl;

    s.print();
    s.ENQUEUE("Heywood");
    s.print();
    s.DEQUEUE();
    s.print();
    s.ENQUEUE("Kaminski");
    s.print();
    s.ENQUEUE("Hunter");
    s.print();
    s.ENQUEUE("Frank");
    s.print();
    s.ENQUEUE("Dave");
    s.print();
    s.ENQUEUE("Hal");
    s.print();
    s.ENQUEUE("Heywood");
    s.print();
    s.DEQUEUE();
    s.print();
    s.DEQUEUE();
    s.print();
    s.DEQUEUE();
    s.print();
    s.ENQUEUE("Heywood");
    s.print();
    s.ENQUEUE("Chandra");
    s.print();
    s.DEQUEUE();
    s.print();
    s.DEQUEUE();
    s.print();
    s.DEQUEUE();
    s.print();
    s.DEQUEUE();
    s.print();
    s.DEQUEUE();
    s.print();
    s.ENQUEUE("Frank");
    s.print();





	return 1;
}