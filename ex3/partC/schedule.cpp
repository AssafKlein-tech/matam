#include "schedule.h"
typedef mtm::EventContainer::EventIterator EventIter;
typedef std::shared_ptr<mtm::BaseEvent> EventPointer;

namespace mtm{


    //Schedule private functions
    EventList::iterator Schedule::insertEvent(BaseEvent& event)
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
            EventList::iterator pos = insertEvent(*iter);
        }
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
        
    }

    void Schedule::unregisterToEvent(DateWrap& date, string& name, int& student)
    {

    }

    void Schedule::printAllEvents()
    {}

    void Schedule::printMonthEvents(int& month, int& year)
    {

    }

    template <class predicate>
    void Schedule::printSomeEvents(predicate& predicate_func, bool verbose = true)
    {}

    void Schedule::printEventDetails(string& name,DateWrap& date)
    {}

    Schedule::~Schedule()
    {

    }
}