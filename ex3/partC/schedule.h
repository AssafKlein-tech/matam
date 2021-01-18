#ifndef SCHEDULE_H_
#define SCHEDULE_H_
#include "event_container.h"
#include "event_wraper.h"
#include <memory>
#include <list>
using std::list;
using std::shared_ptr;
typedef list<std::shared_ptr<mtm::BaseEvent>> EventList;

namespace mtm{

   
    class Schedule{
        EventList event_list;


        EventList::iterator insertEvent(BaseEvent& event);
        bool contains(EventContainer& container);
        void insert(EventContainer& container);
        
    public:
        
        Schedule() {}
        void addEvent(EventContainer& container);
        void registerToEvent(DateWrap& date, string& name, int& student);
        void unregisterToEvent(DateWrap& date, string& name, int& student);
        void printAllEvents();
        void printMonthEvents(int& month, int& year);
        template <class predicate>
        void printSomeEvents(predicate& predicate_func, bool verbose = true);
        void printEventDetails(string& name,DateWrap& date);
        ~Schedule();
    };

}

#endif