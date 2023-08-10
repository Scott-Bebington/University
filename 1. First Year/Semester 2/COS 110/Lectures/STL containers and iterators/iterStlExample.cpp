#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
using namespace std;

int main() 
{
	
	vector<int> vect;
	for(int i = 0; i < 6; i++) vect.push_back(i);
	
	vector<int>::const_iterator it; // read-only iterator
	it = vect.end(); // assign it to the start of the vector
	it--;
	
	for(it; it != vect.begin(); it--) {
		cout << *it << " "; 
	}
	cout << *it << " ";
	cout << endl;
		
	
	vector<int>::reverse_iterator itr = vect.rbegin(); // read-only iterator
	while (itr != vect.rend()) // while it hasn't reach the end
	{
		cout << *itr << " "; // print the current value
		itr++; // and iterate to the next element
	}	
	
	cout << endl;
	
	
	std::vector<int> myvector (3,100); // 1st = size, 2nd = value
	std::cout << "myvector contains:";
	for (vector<int>::iterator myit=myvector.begin(); myit<myvector.end(); myit++)
		std::cout << ' ' << *myit;
	std::cout << '\n';
	
	std::vector<int>::iterator it2;

	it2 = myvector.begin();
	it2 = myvector.insert ( it2 , 200 );

	std::cout << "myvector contains:";
	for (vector<int>::iterator myit=myvector.begin(); myit<myvector.end(); myit++)
		std::cout << ' ' << *myit;
	std::cout << '\n';
	
	myvector.insert (it2,2,300);

	std::cout << "myvector contains:";
	for (vector<int>::iterator myit=myvector.begin(); myit<myvector.end(); myit++)
		std::cout << ' ' << *myit;
	std::cout << '\n';
	
	// "it2" no longer valid, get a new one:
	it2 = myvector.begin();

	std::vector<int> anothervector (2,400); // [400, 400]
	myvector.insert (it2+2,anothervector.begin(),anothervector.end());

	std::cout << "myvector contains:";
	for (vector<int>::iterator myit=myvector.begin(); myit<myvector.end(); myit++)
		std::cout << ' ' << *myit;
	std::cout << '\n';

	int myarray [] = { 501,502,503 };
	myvector.insert (myvector.begin(), myarray, myarray+3);

	std::cout << "myvector contains:";
	for (it2=myvector.begin(); it2<myvector.end(); it2++)
		std::cout << ' ' << *it2;
	std::cout << '\n';
	
	/*
	// Set: a container where all items must be unique.
	// Sets are ordered containers.
	cout << endl;
    set<int> myset;
    myset.insert(7);
    myset.insert(7);
    myset.insert(7);
    myset.insert(2);
    myset.insert(-6);
    myset.insert(8);
    myset.insert(1);
    myset.insert(-4);
 
    set<int>::const_iterator it2; // declare an iterator
    it2 = myset.begin(); // assign it to the start of the set
    while (it2 != myset.end()) // while it hasn't reach the end
    {
	cout << *it2 << " "; // print the value of the element it points to
	it2++; // and iterate to the next element
    }
 
    cout << endl;
    
    
	// Map: a container that stores data pairs: key value and a mapped value.
	// Key value is unique and is used to sort the data.
    
    map<int, string> mymap;
    
    mymap.insert(make_pair(4, "apple"));
    mymap.insert(make_pair(2, "orange"));
    mymap.insert(make_pair(1, "banana"));
    mymap.insert(make_pair(3, "grapes"));
    mymap.insert(make_pair(6, "mango"));
    mymap.insert(make_pair(5, "peach"));
 
    map<int, string>::const_iterator it3; // declare an iterator
    
    it3 = mymap.begin(); // assign it to the start of the vector
    while (it3 != mymap.end()) // while it hasn't reach the end
    {
        cout << it3->first << "=" << it3->second << " "; // print the value of the element it points to
        it3++; // and iterate to the next element
    }
 
    cout << endl;
*/
}
