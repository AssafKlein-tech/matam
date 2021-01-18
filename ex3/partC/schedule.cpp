#include "schedule.h"

namespace mtm{

    Schedule::Schedule() {}
    void Schedule::addEvent(EventContainer& container)
    {

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