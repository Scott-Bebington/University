#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

using namespace std;

template <class T>
class LinkedList
{
    private:
        struct ListNode
        {
            T value;
            ListNode* next;
            ListNode* prev;
            ListNode(T nodeValue) : value(nodeValue)
            {
                next = NULL;
                prev = NULL;
            }
        };
        ListNode* head;
        ListNode* tail;
    public:
        LinkedList();
        void appendNode(T num);   
        void insert(T num);
        void deleteNode(T num);
        void print();
};

#endif // __LINKEDLIST_H__