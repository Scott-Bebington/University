#ifndef CALENDAR_CPP
#define CALENDAR_CPP

#include "Calendar.h"

using namespace std;

Calendar::Calendar()
{
    head = NULL;
}

Calendar::Calendar(vector<event_data> input)
{
    head = NULL;
    for (int i = 0; i < input.size(); i++)
    {
        createEvent(input[i]);
    }
}

Calendar::~Calendar()
{
    clearCalendar();
}

Event *Calendar::getUpcomingEvent(long int now)
{
    if (head != NULL)
    {
        int count = 0;
        Event *nodePtr = head;
        Event *returnvalue;
        long int tempstart = nodePtr->start;
        while (nodePtr->next != NULL)
        {
            if (tempstart > now && count == 0)
            {
                count++;
                returnvalue = nodePtr;
            }
            nodePtr = nodePtr->next;
            tempstart = nodePtr->start;
            if (tempstart > now && tempstart < returnvalue->start)
            {
                returnvalue = nodePtr;
            }
        }
        if (returnvalue == NULL)
        {
            return NULL;
        }
        else
        {
            return returnvalue;
        }
    }
    return NULL;
}

vector<Event> Calendar::filterEvents(int *id, long int *start, long int *end, string *type)
{
    vector<Event> vec;
    if (head != NULL)
    {
        Event *nodePtr = head;

        while (nodePtr != NULL)
        {
            if (id != NULL && nodePtr->id == *id)
            {
                if (start != NULL && nodePtr->start > *start)
                {
                    if (end != NULL && nodePtr->end < *end)
                    {
                        if (type != NULL && nodePtr->type == *type)
                        {
                            vec.push_back(*nodePtr);
                        }
                        else if (type == NULL)
                        {
                            vec.push_back(*nodePtr);
                        }
                    }
                    else if (end == NULL)
                    {
                        if (type != NULL && nodePtr->type == *type)
                        {
                            vec.push_back(*nodePtr);
                        }
                        else if (type == NULL)
                        {
                            vec.push_back(*nodePtr);
                        }
                    }
                }
                if (start == NULL)
                {
                    if (end != NULL && nodePtr->end < *end)
                    {
                        if (type != NULL && nodePtr->type == *type)
                        {
                            vec.push_back(*nodePtr);
                        }
                        else if (type == NULL)
                        {
                            vec.push_back(*nodePtr);
                        }
                    }
                    else if (end == NULL)
                    {
                        if (type != NULL && nodePtr->type == *type)
                        {
                            vec.push_back(*nodePtr);
                        }
                        else if (type == NULL)
                        {
                            vec.push_back(*nodePtr);
                        }
                    }
                }
            }
            else if (id == NULL)
            {
                if (start != NULL && nodePtr->start > *start)
                {
                    if (end != NULL && nodePtr->end < *end)
                    {
                        if (type != NULL && nodePtr->type == *type)
                        {
                            vec.push_back(*nodePtr);
                        }
                        else if (type == NULL)
                        {
                            vec.push_back(*nodePtr);
                        }
                    }
                    else if (end == NULL)
                    {
                        if (type != NULL && nodePtr->type == *type)
                        {
                            vec.push_back(*nodePtr);
                        }
                        else if (type == NULL)
                        {
                            vec.push_back(*nodePtr);
                        }
                    }
                }
                if (start == NULL)
                {
                    if (end != NULL && nodePtr->end < *end)
                    {
                        if (type != NULL && nodePtr->type == *type)
                        {
                            vec.push_back(*nodePtr);
                        }
                        else if (type == NULL)
                        {
                            vec.push_back(*nodePtr);
                        }
                    }
                    else if (end == NULL)
                    {
                        if (type != NULL && nodePtr->type == *type)
                        {
                            vec.push_back(*nodePtr);
                        }
                        else if (type == NULL)
                        {
                            vec.push_back(*nodePtr);
                        }
                    }
                }
            }
            nodePtr = nodePtr->next;
        }
        return vec;
    }
    return vec;
}

void Calendar::alterEvent(int id, long int *end, string *type)
{
    if (head != NULL)
    {
        Event *nodePtr = head;
        while (nodePtr->next != NULL)
        {
            if (nodePtr->id == id)
            {
                if (end != NULL)
                {
                    nodePtr->end = *end;
                    
                }
                if (type != NULL)
                {
                    nodePtr->type = *type;
                }
            }
            nodePtr = nodePtr->next;
        }
    }
}

void Calendar::removeEvent(int id)
{
    Event *nodePtr = head;
    Event *previousNode = NULL;

    if (head)
    {
        while (nodePtr && nodePtr->id != id)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        if (nodePtr)
        {
            if (nodePtr == head)
            {
                head = head->next;
                delete nodePtr;
            }
            else
            {
                previousNode->next = nodePtr->next;
                delete nodePtr;
            }
        }
    }
}

void Calendar::createEvent(event_data data)
{
    Event *newNode;
    Event *nodePtr;
    Event *previousNode;

    newNode = new Event(data.start, data.end, data.id, data.type);

    if (!head)
    {
        head = newNode;
    }
    else
    {
        nodePtr = head;
        previousNode = NULL;

        while (nodePtr && nodePtr->start < newNode->start)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        if (!previousNode)
        {
            head = newNode;
            newNode->next = nodePtr;
        }
        else
        {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}

void Calendar::clearCalendar()
{
    if (head != NULL)
    {
        Event *nodePtr = head;
        while (nodePtr)
        {
            head = head->next;
            delete nodePtr;
            nodePtr = head;
        }
    }
}

Event *Calendar::getFirstEvent()
{
    if (head != NULL)
    {
        return head;
    }
    return NULL;
}

ostream &operator<<(ostream &out, Calendar &calendar)
{
    if (calendar.head != NULL)
    {
        int count = 0;
        Event *nodePtr = calendar.head;
        out << count << ": " << *nodePtr << endl;

        while (nodePtr->next != NULL)
        {
            count++;
            nodePtr = nodePtr->next;
            out << count << ": " << *nodePtr << endl;
        }
        return out;
    }
    return out;
};
#endif
