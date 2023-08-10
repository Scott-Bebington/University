#include <iostream>

#include "Calendar.h"

#include "Event.h"

using namespace std;

int main(void)
{
    event_data event1;
    event1.start = 100, event1.end = 150, event1.id = 1, event1.type = "Booking";
    event_data event2;
    event2.start = 200, event2.end = 550, event2.id = 9, event2.type = "Meeting";
    event_data event3;
    event3.start = 300, event3.end = 450, event3.id = 4, event3.type = "Exam";
    event_data event4;
    event4.start = 800, event4.end = 4900, event4.id = 2, event4.type = "Meeting";
    event_data event5;
    event5.start = 850, event5.end = 900, event5.id = 5, event5.type = "Meeting";

    // testing create events
    // Calendar* cal1 = new Calendar();
    // cal1->createEvent(event1);
    // cal1->createEvent(event2);
    // cal1->createEvent(event3);
    // cal1->createEvent(event4);
    // cal1->createEvent(event5);

    // cout << *cal1 << endl; 

    // testing clear clendar
    // cal1->clearCalendar();

    // testing calendar
    vector<event_data> vec;
    vec.push_back(event1);
    vec.push_back(event2);
    vec.push_back(event3);
    vec.push_back(event4);
    vec.push_back(event5);
    Calendar* cal2 = new Calendar(vec);

    // // testing remove events
    // cal2->removeEvent(5);

    cout << *cal2 << endl;

    // // testing upcoming events
    // cout << "Upcoming event after: " << *cal2->getFirstEvent() << endl;
    // cout << "Is event:             " << *cal2->getUpcomingEvent(event1.start) << endl << endl;

    // // testing filter events
    // vector<Event> vec2 = cal2->filterEvents(new int(1), new long int(500), new long int(1000), new string("Meeting"));
    // for (int i = 0; i < vec2.size(); i++)
    // {
    //     cout << vec2[i] << endl;
    // }
    

    // // testing alter events
    // long int* end = new long int(900);
    // string* type = new string("Birthday Reminder");
    // cal2->alterEvent(2, end, type);
    // cout << *cal2 << endl;
    
    cout << "runs \n";
	return 0;
}
