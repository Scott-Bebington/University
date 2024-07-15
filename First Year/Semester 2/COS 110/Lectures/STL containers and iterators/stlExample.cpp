#include <vector>
#include <deque>

#include <iostream>
using namespace std;

class MyClass 
{
	int number;
	public:
		MyClass(int n) : number (n) {}
		int getNumber() {return number;}
};

int main()
{ 
    vector<int> vect(5, 0);
	
    for (int i = 0; i < 5; i++) {
        vect.push_back(i + 1); // insert at end of array
	//vect[i] = i + 1;
    }
 
    for (int j = 0; j < vect.size(); j++)
        cout << vect[ j ] << " ";
	
    cout << endl;
	
    vect.pop_back(); // remove one element
	
    for (int j = 0; j < vect.size(); j++)
        cout << vect[ j ] << " ";
 
    cout << endl;

    
    vector<MyClass> vect1;
    for (int i = 0; i < 5; i++)
        vect1.push_back(MyClass(i+1)); // insert at end of array
 
    for (int j = 0; j < vect1.size(); j++)
        cout << vect1[ j ].getNumber() << " ";
	
    cout << endl;
	
	
    deque<int> deq;
    for (int i = 0; i < 5; i++)
        deq.push_front(i + 1); // insert at front of array
 
    for (int j = 0; j < deq.size(); j++)
        cout << deq[ j ] << " ";
 
    cout << endl;
    
    deq.pop_front(); // remove one element
    deq.pop_back(); // remove one element
    
    for (int j = 0; j < deq.size(); j++)
        cout << deq[ j ] << " ";
 
    cout << endl;

} 
