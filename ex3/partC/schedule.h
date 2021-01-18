#ifndef SCHEDULE_H_
#define SCHEDULE_H_
#include "event_container.h"
#include "base_event.h"
#include <memory>
#include <iostream>
#include <list>
using MyType_t = std::shared_ptr<BaseEvent>;

using std::list;

namespace mtm{

   
    class Schedule{
        
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
        virtual ~Schedule();
    };

}

#endif