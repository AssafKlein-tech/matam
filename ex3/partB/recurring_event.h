#ifndef RECURRING_EVENT_H_
#define RECURRING_EVENT_H_
#include "event_container.h"


namespace mtm{

    template <class EventType>
    class RecurringEvent: public EventContainer{
    public:
        RecurringEvent(DateWrap& first_date, string name, int num_occurrences, int interval_days);
        void add(BaseEvent& event);
        ~RecurringEvent(){}
    };
}
#endif