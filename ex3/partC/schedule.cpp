#include "schedule.h"
#include <cstdlib>
#include <iostream>

using std::cout;
typedef mtm::EventContainer::EventIterator EventIter;
typedef std::shared_ptr<mtm::BaseEvent> EventPointer;

namespace mtm{


    //Schedule private functions
    void Schedule::insertEvent(BaseEvent& event)
    {
        EventList::iterator pos = event_list.begin();
        EventPointer event_ptr((&event)->clone());
        if(pos == event_list.end())
        {
            event_list.push_back(event_ptr);
        }
        while (pos != event_list.end() && (*pos)->operator<(*event_ptr))
        {
            ++pos;
        }
        event_list.insert(pos, event_ptr);
    }

    bool Schedule::contains(EventContainer& container)
    {
        for (EventIter iter = container.begin(); iter!= container.end(); ++iter)
        {
            for (EventPointer event_ptr: event_list)
            {  
                if (*iter == *event_ptr)
                {
                    return true;
                }       
            }
        }
        return false;
    }

    void Schedule::insert(EventContainer& container)
    {
        for (EventIter iter = container.begin(); iter!= container.end(); ++iter)
        {
            insertEvent(*iter);
        }
    }

    EventList::iterator Schedule::getEventPosition(DateWrap& date, string& name)
    {
        for (EventList::iterator pos = event_list.begin(); pos != event_list.end(); ++pos)
        {  
            if((**pos).compareEventsDateWithADate(date) && (**pos).compareEventsNameWithAName(name))
            {
                return pos;
            }         
        }
        throw EventDoesNotExist();
    }

    //Schedule methods
    Schedule::Schedule(){}

    void Schedule::addEvent(EventContainer& container)
    {
        if(contains(container))
        {
            throw EventAlreadyExists();
        }
        insert(container);
    }
    
    void Schedule::registerToEvent(DateWrap& date, string& name, int& student)
    {
        EventList::iterator pos = getEventPosition(date,name);
        (*pos)->registerParticipant(student);
    }

    void Schedule::unregisterToEvent(DateWrap& date, string& name, int& student)
    {
        EventList::iterator pos = getEventPosition(date,name);
        (**pos).unregisterParticipant(student);

    }

    void Schedule::printAllEvents()
    {
        for (EventPointer event_ptr: event_list)
        {
            event_ptr->printShort(cout);
        }
    }

    void Schedule::printMonthEvents(int& month, int& year)
    {
        DateWrap date(1, month, year);
        for (EventPointer event_ptr: event_list)
        {
            while (event_ptr->isEventGreaterThanDate(date) && date.day() < 30)
            {
                date++;
            }
            if (event_ptr->compareEventsDateWithADate(date))
            {
                event_ptr->printShort(cout);
            }
        }
    }

    template <class predicate>
    void Schedule::printSomeEvents(predicate& predicate_func, bool verbose)
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
            }
        }
    }

    void Schedule::printEventDetails(string& name,DateWrap& date)
    {
        EventList::iterator pos = getEventPosition(date,name);
        (*pos)->printLong(cout);
    }

}