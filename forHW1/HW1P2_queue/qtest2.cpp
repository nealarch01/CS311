#include <iostream>
#include "queue.h"

int main() {
	queue q1;
	std::string test = "a", tempstr;
	for(int i = 0; i < 10; i++) {
		q1.add(test);
		test[0]++;
	}
	try {
		q1.add("K");
	} catch(queue::QueueOverflow) {
		std::cout << "Queue Overflow. Too many elements" << std::endl;
	}
	q1.displayAll();
	std::cout << "Size: " << q1.getSize() << std::endl;
	for(int i = 0; i < 3; i++) {
		q1.remove(tempstr);
		std::cout << tempstr << " has been removed from the queue" << std::endl;
	}
	q1.displayAll();
	std::cout << "Size (before removing): " << q1.getSize() << std::endl;
	int size = q1.getSize();
	for(int i = 0; i < size; i++) {
		q1.remove(tempstr);
		std::cout << tempstr << " has been removed from the queue" << std::endl;
	}
	try {
		q1.remove(tempstr);
	} catch(queue::QueueUnderflow) {
		std::cout << "Queue Underflow" << std::endl;
	}
	q1.displayAll();
	std::cout << "Size: " << q1.getSize() << std::endl;

	std::cout << " ------------------------ " << std::endl;
	q1.add("a");	
	q1.add("b");
	q1.add("c");

	for(int i = 0; i < 10; i++) {
		q1.displayAll();
		q1.goToBack();
	}	
	queue q2 = q1;
	std::cout << "Queue 1: " << std::endl;
	q1.displayAll();
	std::cout << "Queue 2: " << std::endl;
	q2.displayAll();
	return 0;
}

