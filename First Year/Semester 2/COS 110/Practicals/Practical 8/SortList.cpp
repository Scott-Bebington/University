
using namespace std;

template <class T>
SortList<T>::SortList(bool asc)
{
    head = NULL;
    tail = NULL;
    ascending = asc;
}

template <class T>
void SortList<T>::add(SortNode<T> *a)
{
    SortNode<T> *newNode;

    newNode = a;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (!head) // test whether head is null
    {
        head = newNode; // make the new node the head of the list
        tail = newNode;
    }
    else // insert at the end of the list
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

template <class T>
SortNode<T> *SortList<T>::remove(T val)
{
    SortNode<T> *nodePtr = head;
    
    if (!head)
    {
        return NULL;
    }
    if (head == tail && head->getValue() == val)
    {
        head = NULL;
        tail = NULL;
        return nodePtr;
    }
    if (head->getValue() == val)
    {
        head = head->next;
        return nodePtr;
    }
    
    while(nodePtr && nodePtr->getValue() != val)
    {
        nodePtr = nodePtr->next;
    }
    if (!nodePtr)
    {
        return NULL;
    }
    if (nodePtr == tail)
    {
        tail = tail->prev;
        tail->next = NULL;
        return nodePtr;
    }
    nodePtr->prev->next = nodePtr->next;
    nodePtr->next->prev = nodePtr->prev;
    return nodePtr;
}

template <class T>
void SortList<T>::sort()
{
    if (head)
    {
        SortList<T> *temp = new SortList<T>(1);
        SortNode<T> *nodePtr = head, *nodePtr2 = head, *small, *large = head;
        int count = 0;
        while (nodePtr) // traversing the list
        {
            if (nodePtr->getValue() > large->getValue()) // finding the largest value in the list
            {
                large = nodePtr;
            }
            nodePtr = nodePtr->next;
            count++; // to find out how many links are in the list
        }
        nodePtr = head;
        nodePtr2 = head->next;
        for (int i = 0; i < count; i++)
        {
            nodePtr2 = head;
            small = large;
            while (nodePtr2)
            {
                if (nodePtr2->getValue() < small->getValue())
                {
                    small = nodePtr2;
                }
                nodePtr2 = nodePtr2->next;
            }
            temp->add(new SortNode<T>(small->getValue()));
            remove(small->getValue());
        }
        head = temp->head;
        tail = temp->tail;
        if (!ascending)
        {
            SortList<T> *temp2 = new SortList<T>(1);
            nodePtr = tail;
            while (nodePtr) // traversing the list
            {
                temp2->add(new SortNode<T>(nodePtr->getValue()));
                nodePtr = nodePtr->prev;
            }
            head = temp2->head;
            tail = temp2->tail;
        }
    }
}

template <class T>
string SortList<T>::print()
{
    SortNode<T> *nodePtr;
    string output = "";
    nodePtr = head;
    if (head) // test whether head is null
    {
        while (nodePtr->next)
        {
            output += nodePtr->print();
            output += ",";
            nodePtr = nodePtr->next;
        }
        output += nodePtr->print();
    }
    return output;
}

template <class T>
SortNode<T> *SortList<T>::getHead()
{
    return head;
}

template <class T>
void SortList<T>::setAsc(bool a)
{
    ascending = a;
    sort();
}

template <class T>
string SortList<T>::debug()
{
    return *this;
}