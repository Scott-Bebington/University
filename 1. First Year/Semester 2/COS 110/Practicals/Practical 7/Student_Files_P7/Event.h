#ifndef EVENT_H
#define EVENT_H

#include <string>
#include "Utils.h"

using namespace std;

class Event;
std::ostream& operator<<(std::ostream& out, Event& event);

class Event
{
    public:
        long int start;
        long int end;
        int id;
        string type;
        Event* next;

        Event(long int start, long int end, int id, string type);
        ~Event();
        friend std::ostream& operator<<(std::ostream& out, Event& event);
};
#endif // EVENT_H