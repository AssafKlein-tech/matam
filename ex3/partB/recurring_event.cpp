#include "recurring_event.h"

namespace mtm{
    
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
    void RecurringEvent<EventType>::add(const BaseEvent& event)
    {
        throw NotSupported();
    }
}