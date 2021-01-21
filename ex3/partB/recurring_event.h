#ifndef RECURRING_EVENT_H_
#define RECURRING_EVENT_H_
#include "event_container.h"


namespace mtm{

    template <class EventType>
    class RecurringEvent: public EventContainer{
    public:
        RecurringEvent(DateWrap first_date, string name, int num_occurrences, int interval_days);
        void add(BaseEvent& event);
        ~RecurringEvent(){}
    };

    template <class EventType>
    RecurringEvent<EventType>::RecurringEvent(DateWrap first_date, string name, int num_occurrences, int interval_days)
    {
        if (num_occurrences <= 0)
            throw InvalidNumber();
        if (interval_days <= 0)
            throw InvalidInterval();
        EventType event_to_enter;
        for(int i = 0; i < num_occurrences; i++)
        {
            event_to_enter = EventType(first_date + (i * interval_days),name);
            this.Insert(event_to_enter);
        }
    }

    template <class EventType>
    void RecurringEvent<EventType>::add(BaseEvent& event)
    {
        throw NotSupported();
    }
}
#endif