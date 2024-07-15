#include <iostream>
#include "ArrayList.h"

ArrayList::ArrayList(){
	size = 50;
	storage = new int[size];
	current = -1;
}

ArrayList::ArrayList(int s) {
	size = s;
	storage = new int[size];
	current = -1;
}

bool ArrayList::insertElement(int element) {
	if (!isFull()) {
		current++;
		storage[current] = element;
		return true;
	}
	return false;
}

void ArrayList::sort(){
	for (int i = current; i > 0; --i) {
		for (int j = 1; j <= i ; ++j) {
			if (directionOperator(storage[j-1],storage[j])) {
				int temp = storage[j-1];
				storage[j-1] = storage[j];
				storage[j] = temp;
			}
		}
	}
}

bool ArrayList::isFull(){
	return current >= size;
}

bool ArrayList::isEmpty(){
	return current == -1;
}

void ArrayList::print(){
	for (int i = 0; i <= current; i++) {
		std::cout << storage[i] <<  " ";
	}
	std::cout  << std::endl;
}

ArrayList::~ArrayList() {
	delete [] storage;
}


bool ArrayList::directionOperator(int, int) {
	std::cout << "Please implement this function in the subclasses" << std::endl;
	return true;
}


AscendingArrayList::AscendingArrayList() : ArrayList() {
}

AscendingArrayList::AscendingArrayList(int size) : ArrayList(size) {
}


bool AscendingArrayList::directionOperator(int operand1, int operand2){
	if (operand1 > operand2) {
		return true;
	}
	else 
		return false;
}

DescendingArrayList::DescendingArrayList() : ArrayList() {
}

DescendingArrayList::DescendingArrayList(int size) : ArrayList(size) {
}


bool DescendingArrayList::directionOperator(int operand1, int operand2){
	if (operand1 < operand2) {
		return true;
	}
	else 
		return false;
}

