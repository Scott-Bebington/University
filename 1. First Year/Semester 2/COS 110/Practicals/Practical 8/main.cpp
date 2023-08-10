#include "SortList.h"
#include <iostream>
#include <string>

//Add any tests you want (as you should)
//This prac does not check memory usage, and even this main does not really delete allocated memory
//Keep that in mind should you wish to use valgrind

using namespace std;

int main()
{
	SortList<int>* ll = new SortList<int>(1);
	ll->add(new SortNode<int>(5));
	ll->add(new SortNode<int>(50));
	ll->add(new SortNode<int>(0));
	ll->add(new SortNode<int>(3));
	ll->add(new SortNode<int>(28));
	ll->add(new SortNode<int>(907));
	ll->add(new SortNode<int>(907));
	ll->add(new SortNode<int>(1));

	ll->add(new SortNode<int>(-10));
	ll->add(new SortNode<int>(-10));
	ll->add(new SortNode<int>(-9));
	ll->add(new SortNode<int>(-8));
	ll->add(new SortNode<int>(-7));
	ll->add(new SortNode<int>(-6));
	ll->add(new SortNode<int>(-5));
	ll->add(new SortNode<int>(0));
	ll->add(new SortNode<int>(0));
	
	cout<<"Initial print: "<<endl<<ll->print()<<endl;
	cout<<"Sorting:"<<endl;
	ll->sort();
	cout<<"Ascending: "<<endl<<ll->print()<<endl;
	ll->add(new SortNode<int>(908));
	ll->setAsc(0);
	ll->sort();
	cout<<"Ascending: "<<endl<<ll->print()<<endl;
	// ll->remove(908);
	ll->setAsc(0);
	ll->sort();
	cout<<"Ascending: "<<endl<<ll->print()<<endl;
	cout << "Remove Testing: "<<endl;
	ll->remove(907);
	ll->remove(907);
	ll->remove(-10);
	ll->remove(-10);
	ll->remove(-10);
	ll->remove(0);
	ll->remove(-9);
	ll->remove(-5);
	ll->remove(3);
	cout<<"After Remove: "<<endl<<ll->print()<<endl;
	cout<<"Sorting:"<<endl;
	ll->setAsc(1);
	ll->sort();
	cout<<"Sorted"<<endl<<ll->print()<<endl;
	cout << "Remove Testing 2: "<<endl;
	ll->remove(-8);
	ll->remove(-7);
	ll->remove(-6);
	ll->remove(0);
	ll->remove(0);
	ll->remove(1);
	ll->remove(5);
	ll->remove(8);
	ll->remove(50);
	ll->remove(28);
	cout<<"Print after removal"<<endl<<ll->print()<<endl;
	ll->setAsc(0);
	cout<<(ll->getHead()==NULL?"All Removed":"Something remained")<<endl;
	ll->add(new SortNode<int>(908));
	ll->sort();
	delete ll;

	return 0;
}

//Expected output
/*
Initial print: 
5,50,0,3,28,907,907,1,-10,-10,-9,-8,-7,-6,-5,0,0
Sorting:
Ascending:
-10,-10,-9,-8,-7,-6,-5,0,0,0,1,3,5,28,50,907,907
Descending:
907,907,50,28,5,3,1,0,0,0,-5,-6,-7,-8,-9,-10,-10
Remove Testing:
After Remove:
50,28,5,1,0,0,-6,-7,-8
Sorting:
Sorted
-8,-7,-6,0,0,1,5,28,50
Remove Testing 2:
Print after removal

All Removed
*/
