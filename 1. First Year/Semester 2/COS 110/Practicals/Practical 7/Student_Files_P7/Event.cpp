#ifndef EVENT_CPP
#define EVENT_CPP

#include "Event.h"

using namespace std;

Event::Event(long int start, long int end, int id, string type)
{
    this->start = start;
    this->end = end;
    this->id = id;
    this->type = type;
    this->next = NULL;
}

Event::~Event()
{

}

ostream& operator<<(ostream& out, Event& event)
{
    out << event.type << " " << unix_to_string(event.start) << "->" << unix_to_string(event.end);
    return out;
};
#endif