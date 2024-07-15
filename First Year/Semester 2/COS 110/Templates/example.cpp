#include <string>
#include <iostream>

using namespace std;

template <class Type>
Type maximum(Type x, Type y);

//int maximum(int x, int y);

template <class T, class N>
double maximum(T x, N y);


int main() {
	double a = 0.6;
	double b = 20.25;
	
	cout << "Out of " << a << " and " << b;
	cout << ", " << maximum(a, b) << " is the larger one.\n";
		
	int c = 5;
	int d = 100;
	
	cout << "Out of " << c << " and " << d;
	cout << ", " << maximum(c, d) << " is the larger one.\n";
	
	cout << "Out of " << a << " and " << d;
	cout << ", " << maximum(a, d) << " is the larger one.\n";
		
	char one = 'A';
	char two = 'Z';
	
	cout << "Out of " << one << " and " << two;
	cout << ", " << maximum(one, two) << " is the larger one.\n";
	
	
	cout << "Out of " << one << " and " << a;
	cout << ", " << maximum(one, a) << " is the larger one.\n";
	
	return 0;
}

template <class T>
T maximum(T x, T y)
{
	if(x >= y) {
		return x;
	}
	else return y;
}

/*
int maximum(int x, int y) {
	cout << "int only" << endl;
	if(x >= y) {
		return x;
	}
	else return y;
}
*/

template <class T, class N>
double maximum(T x, N y) 
{
	if(x >= y) {
		return x;
	}
	else return y;
}

