#include <iostream>
#include <cstddef>

#include "RecursiveLinkList.cpp"
#include "RecursiveNode.cpp"

int main()
{
    RecursiveLinkList<int>* list = new RecursiveLinkList<int>();
    list->insert(5, 0);
    list->insert(7, 0);
    list->insert(15, 0);
    list->insert(1, 0);
    // list->printInOrder();
    // cout << "Size is: " << list->size() << endl;
    // list->size();
    return 0;
}