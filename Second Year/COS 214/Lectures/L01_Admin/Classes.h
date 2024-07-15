//
//  Classes.h
//  
//
//  Created by Linda Marshall on 2021/08/14.
//

#ifndef Classes_h
#define Classes_h

#include <iostream>

using namespace std;

class A {
public:
	A();
	A(string);
	void print();
private:
	string identifier;
};

class B: public A {
public:
	B();
};

#endif /* Classes_h */
