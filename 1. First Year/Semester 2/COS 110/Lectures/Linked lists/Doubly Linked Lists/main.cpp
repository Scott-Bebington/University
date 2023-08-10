#include <iostream>
#include <stack>
#include "LinkedList.cpp"

using namespace std;

int main()
{
    LinkedList<int>* list1 = new LinkedList<int>();
    list1->appendNode(5);
    list1->appendNode(9);
    list1->appendNode(10);
    list1->appendNode(7);

    list1->print();

}