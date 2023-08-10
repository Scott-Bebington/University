#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
void square(T&);

int main()
{
    list<int> li;
    for (int nCount=0; nCount < 6; nCount++)
        li.push_back(nCount);
 
    list<int>::iterator it; // declare an iterator
	
    for (it = li.begin(); it != li.end(); it++) // for loop with iterators
        cout << *it << " ";
    cout << endl;
    	

    it = find(li.begin(), li.end(), 3); // find the value 3 in the list
	
    if(it == li.end()) cout << "Value was not found!" << endl;
    else cout << "Value " << *it << " was found" << endl;	
	
    li.insert(it, 8); // use list::insert to insert the value 8 before it
 
    for (it = li.begin(); it != li.end(); it++) // for loop with iterators
        cout << *it << " ";
    	
    cout << endl;
	
    vector<int> vect;
    vector<int>::iterator itVec; // declare an iterator
    vect.push_back(7);
    vect.push_back(-3);
    vect.push_back(6);
    vect.push_back(2);
    vect.push_back(-5);
    vect.push_back(0);
    vect.push_back(4);
 
    for (itVec = vect.begin(); itVec != vect.end(); itVec++) // for loop with iterators
        cout << *itVec << " ";
    cout << endl;
    
    random_shuffle(vect.begin(), vect.end()); // shuffle the vector
	
    for (itVec = vect.begin(); itVec != vect.end(); itVec++) // for loop with iterators
        cout << *itVec << " ";
    cout << endl;
  
    sort(vect.begin(), vect.end()); // sort the vector    
    
    for (itVec = vect.begin(); itVec != vect.end(); itVec++) // for loop with iterators
        cout << *itVec << " "; 
    cout << endl;
  
    cout << "element -5 ";
    if(binary_search(vect.begin(), vect.end(), -5)) cout << "was found";
    else cout << "was not found";
    cout << endl;
 

    reverse(vect.begin(), vect.end()); // reverse the vector

    for (itVec = vect.begin(); itVec != vect.end(); itVec++) // for loop with iterators
        cout << *itVec << " "; 	
    cout << endl;
   
    for_each(vect.begin(), vect.end(),    // range
				    square<int>);  // operation
    
    for (itVec = vect.begin(); itVec != vect.end(); itVec++) // for loop with iterators
        cout << *itVec << " "; 	
    cout << endl;
   
}

template <class T> // Does it have to be a template function?
void square(T& x) { // would this work without & ?
	x = x * x;
}

