#ifndef SCHEDULE_H_
#define SCHEDULE_H_
#include "event_container.h"
#include "exceptions.h"
#include <list>
using std::list;

namespace mtm{

   
    class Schedule{

        list<BaseEvent> event_list;
        
    public:
        
        Schedule() {}
        void addEvent(EventContainer& container);
        void registerToEvent(DateWrap& date, string& name, int& student);
        void unregisterToEvent(DateWrap& date, string& name, int& student);
        void printAllEvents();
        void printMonthEvents(int& month, int& year);
        void printSomeEvents(predicate& predicate_func, bool verbose = true);
        void printEventDetails(string& name,DateWrap& date)
        virtual ~Schedule();
    };

}

#endif