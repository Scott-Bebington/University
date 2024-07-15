#include <iostream>
#include "ArrayList.h"

using namespace std;

int main(){
	
	ArrayList* arr = new DescendingArrayList(10); 
	
	arr->insertElement(10);
	arr->insertElement(20);
	arr->insertElement(15);
	arr->insertElement(25);
	arr->insertElement(5);
	
	arr->print();
	
	arr->sort();
	
	arr->print();

	delete arr;
	
	return 0;
}
