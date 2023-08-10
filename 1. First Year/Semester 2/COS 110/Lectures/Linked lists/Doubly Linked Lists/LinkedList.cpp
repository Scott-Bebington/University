#include <iostream>

#include "LinkedList.h"

using namespace std;

template <class T>
LinkedList<T>::LinkedList()
{
}

template <class T>
void LinkedList<T>::appendNode(T num) // adding node to the end of the list
{
    ListNode *newNode = new ListNode(num);
    ListNode *nodePtr = head;

    if (!nodePtr)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    return;
}

template <class T>
void LinkedList<T>::insert(T num)
{
    ListNode *newNode = new ListNode(num);
    ListNode *nodePtr = head;
    if (!nodePtr)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    if (num < head->value)
    {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
        return;
    }
    if (num > tail->value)
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        return;
    }
    while (nodePtr && num > nodePtr->value)
    {
        nodePtr = nodePtr->next;
    }
    nodePtr->prev->next = newNode;
    newNode->prev = nodePtr->prev;
    newNode->next = nodePtr;
    nodePtr->prev = newNode;

    return;
}

template<class T>
void LinkedList<T>::deleteNode(T num)
{
    ListNode* nodePtr = head;
    if (!nodePtr)
    {
        cout << "Cant remove from an empty list" << endl;
        return;
    }
    if (num == head->value)
    {
        nodePtr = nodePtr->next;
        delete head;
        head = nodePtr;
        return;
    }
    if (num == tail->value)
    {
        tail = tail->prev;
        delete tail->next;
        tail->next = NULL;
        return;
    }
    while (nodePtr && num != nodePtr->value)
    {
        nodePtr = nodePtr->next;
    }
    
    if (!nodePtr)
    {
        cout << "Value not found, cannot delete node" << endl;
        return;
    }
    nodePtr->next->prev = nodePtr->prev;
    nodePtr->prev->next = nodePtr->next;
    delete nodePtr;
    return;
    
}

template <class T>
void LinkedList<T>::print()
{
    ListNode *nodePtr = head;
    if (!nodePtr)
    {
        cout << "List is empty" << endl;
        return;
    }
    cout << "List Contents: ";
    while (nodePtr)
    {
        cout << nodePtr->value << " ";
        nodePtr = nodePtr->next;
    }
    cout << endl;
}
