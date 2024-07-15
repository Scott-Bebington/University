//
//  Classes.cpp
//  
//
//  Created by Linda Marshall on 2021/08/14.
//

#include <iostream>

#include "Classes.h"

using namespace std;

A::A(string str) {
	identifier = str;
}

A::A() {
	identifier = "Class A";
}

void A::print() {
	cout << "This is an object of " << identifier << endl;
}
 
B::B() : A("Class B"){
}

