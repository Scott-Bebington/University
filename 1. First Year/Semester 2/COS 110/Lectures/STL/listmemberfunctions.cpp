#include<iostream>
#include<list>
using namespace std;

int main()
{
		//Define an empty list.
	list<int>  myList;
	
	//Declare iterator to a list
	list<int>::iterator it;// it is a bidirectional iterator type that points to elements
	
	
	
	//Add some values to the list.// set some initial values:
     for (int i=0; i<100; i+=10) 
	  myList.push_back(i); ///adds new element containing value at the end of the container.
	//myList.push_front(55);
	//use an iterator to display the values.
	cout<<"myList contains   ";
	for(it=myList.begin(); it!=myList.end(); it++)
		cout<<*it<<" ";
		cout<<endl;
	
	
	it = myList.begin();
	++it;       // it now points to second number in th list         ^

//inserts a new element before the one pointed to by it.
  myList.insert (it,105); // 0  105  10 20 30 40 50 60 70 80 90
  
  //use an iterator to display the values.
	cout<<"myList after insert contains   ";
	for(it=myList.begin(); it!=myList.end(); it++)
		cout<<*it<<" ";
		cout<<endl;
	
	// "it" still points to number 2                      ^
  myList.insert (it,2,20);                      // 0  105  10 20 30 40 50 60 70 80 90 20 20

  --it;       // it points now to the second 20     
  
  //use an iterator to display the values.
	cout<<"myList after second insert contains   ";
	for(it=myList.begin(); it!=myList.end(); it++)
		cout<<*it<<" ";
		cout<<endl;
		
		cout<<myList.front();//Returns a reference to the first element in the list container.
		cout<<endl;//
		
		
		  myList.reverse();// Reverses the order of the elements in the list container.
		   //use an iterator to display the values.
	cout<<"myList after reverse contains   ";
	for(it=myList.begin(); it!=myList.end(); it++)
		cout<<*it<<" ";
		cout<<endl;

		
		myList.pop_back();
		cout<<"myList after pop_back() contains   ";
	for(it=myList.begin(); it!=myList.end(); it++)
		cout<<*it<<" ";
		cout<<endl;
	

	
}
