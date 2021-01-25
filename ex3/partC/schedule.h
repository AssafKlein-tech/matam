#ifndef SCHEDULE_H_
#define SCHEDULE_H_
#include "event_container.h"
#include <memory>
#include <list>

typedef std::shared_ptr<mtm::BaseEvent> EventPointer;
typedef std::list<std::shared_ptr<mtm::BaseEvent>> EventList;
typedef mtm::EventContainer::EventIterator EventIter;

namespace mtm{

   
    class Schedule{

        EventList event_list;

        /**
         * @brief inserting an event to the schedule
         * 
         * @param event to enter
         */
        void insertEvent(const BaseEvent& event);
        
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
        EventList::iterator getEventPosition(const DateWrap& date, const string& name, EventList& iteration_list) const;
    public:
        
        Schedule() {}
        Schedule(const Schedule& schedule) = default;
        Schedule& operator=(const Schedule& schedule) = default;
        ~Schedule() = default;
        void addEvents(const EventContainer& container);
        void registerToEvent(const DateWrap& date, const string& name, int student);
        void unregisterFromEvent(const DateWrap& date, const string& name, int student);
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
                        event_ptr->printLong(std::cout);
                    }
                    else
                    {
                        event_ptr->printShort(std::cout);
                    }
                    std::cout<<std::endl;
                }
            }
        }
        void printEventDetails(const DateWrap& date,const string& name) const;
    };
}

#endif