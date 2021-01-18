#include "schedule.h"

namespace mtm{
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
}