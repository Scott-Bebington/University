#ifndef CALENDAR_H
#define CALENDAR_H

#include "Event.h"
#include <vector>

using namespace std;

class Calendar;
std::ostream& operator<<(std::ostream& out, Calendar& calendar);

class Calendar
{
    private:
        Event* head;
    public:
        Calendar();
        Calendar(vector<event_data> input);
        ~Calendar();

        Event* getUpcomingEvent(long int now);
        vector<Event> filterEvents(int* id, long int* start, long int* end, string* type);
        void alterEvent(int id, long int* end, string* type);
        void removeEvent(int id);
        void createEvent(event_data data);
        void clearCalendar();
        Event* getFirstEvent();
        friend std::ostream& operator<<(std::ostream& out, Calendar& calendar);
};

#endif // CALENDAR_H