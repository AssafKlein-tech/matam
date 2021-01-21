#ifndef SCHEDULE_H_
#define SCHEDULE_H_
#include "event_container.h"
#include <memory>
#include <list>
using std::list;
using std::shared_ptr;
typedef list<std::shared_ptr<mtm::BaseEvent>> EventList;

namespace mtm{

   
    class Schedule{
        EventList event_list;


        void insertEvent(BaseEvent& event);
        bool contains(const EventContainer& container);
        void insert(const EventContainer& container);
        EventList::iterator getEventPosition(DateWrap& date, string& name) const;
        
    public:
        
        Schedule() {}
        void addEvents(const EventContainer& container);
        void registerToEvent(DateWrap date, string name, int student);
        void unregisterFromEvent(DateWrap date, string name, int student);
        void printAllEvents() const;
        void printMonthEvents(int month, int year) const ; 
        template <class predicate>
        void printSomeEvents(predicate predicate_func, bool verbose = false) const;
        void printEventDetails(DateWrap date, string name) const;
        ~Schedule() {}
    };

}

#endif