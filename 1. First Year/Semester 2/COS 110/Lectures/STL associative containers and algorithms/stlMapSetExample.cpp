#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
using namespace std;

int main() {
	
// Map: a container that stores data pairs: key value and a mapped value.
// Key value is unique and is used to sort the data.
    
    map<int, string> mymap;
    
    mymap.insert(make_pair(4, "apple"));
    mymap.insert(make_pair(2, "orange"));
    mymap.insert(make_pair(1, "banana"));
    mymap.insert(make_pair(3, "grapes"));
    mymap.insert(make_pair(6, "mango"));
    mymap.insert(make_pair(5, "grapes"));
    mymap.insert(make_pair(5, "strawberries"));
    mymap.insert(make_pair(5, "avocado"));
	mymap[5] = "strawberry";
	
    cout << "\nValue at key 2: " << mymap.at(2) << endl<< endl;	
 
    map<int, string>::const_iterator it3; // declare an iterator
    
    it3 = mymap.begin(); // assign it to the start of the vector
    while (it3 != mymap.end()) // while it hasn't reach the end
    {
        cout << it3->first << "=" << it3->second << " "; // print the value of the element it points to
        it3++; // and iterate to the next element
    }
 
    cout << endl;
 
    mymap.erase(2); // delete the orange
    
    it3 = mymap.begin(); // assign it to the start of the vector
    while (it3 != mymap.end()) // while it hasn't reach the end
    {
        cout << it3->first << "=" << it3->second << " "; // print the value of the element it points to
        it3++; // and iterate to the next element
    }
 
    cout << endl;
    
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
    
    set<string> mySset;
    mySset.insert("banana");
    mySset.insert("apple");
    mySset.insert("pear");
    mySset.insert("grapes");
    for(set<string>::iterator i = mySset.begin(); i != mySset.end(); i++) {
	    cout << *i << " ";
    }
	
    cout << endl;
    
}