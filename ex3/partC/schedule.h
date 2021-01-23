#ifndef SCHEDULE_H_
#define SCHEDULE_H_
#include "event_container.h"
#include <memory>
#include <list>
using std::list;
using std::shared_ptr;
using std::cout;
using std::endl;
typedef std::shared_ptr<mtm::BaseEvent> EventPointer;
typedef list<std::shared_ptr<mtm::BaseEvent>> EventList;
typedef mtm::EventContainer::EventIterator EventIter;

namespace mtm{

   
    class Schedule{
        EventList event_list;

        bool isValidStudent(int student);
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
        template <typename Predicate>
        void printSomeEvents(Predicate predicate_func, bool verbose = false) const
        {
            for (EventPointer event_ptr: event_list)
            {
                if (predicate_func(*event_ptr))
                {
                    if (verbose)
                    {
                        event_ptr->printLong(cout);
                    }
                    else
                    {
                        event_ptr->printShort(cout);
                    }
                    cout<<endl;
                }
            }
        }
        void printEventDetails(DateWrap date, string name) const;
        ~Schedule() {}
    };

}

#endif