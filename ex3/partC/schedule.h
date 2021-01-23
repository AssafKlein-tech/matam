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

        /**
         * @brief checks if the student is valid
         * 
         * @param student - the student to check
         * @return true if is valid between 1 and 123456789
         * @return false otherwise
         */
        bool isValidStudent(int student);

        /**
         * @brief inserting an event to the schedule
         * 
         * @param event to enter
         */
        void insertEvent(BaseEvent& event);
        
        /**
         * @brief checks the schedule contains one or more events from the container
         * 
         * @param container container of events
         * @return true if the schedule contains those events
         * @return false otherwise
         */
        bool contains(const EventContainer& container);

        /**
         * @brief Inserting all the events of the container to the schedule
         * 
         * @param container - container of events
         */
        void insert(const EventContainer& container);

        /**
         * @brief Get the Event Position iterator of the list, which match the date and the name given
         * 
         * @param date of the event
         * @param name of the event
         * @param iteration_list a list to iterate
         * @return EventList::iterator - the position
         * 
         * Throws "EventDoesNotExist" exception if their is no event with the given arrguments 
         */
        EventList::iterator getEventPosition(DateWrap& date, string& name, EventList& iteration_list) const;
        
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