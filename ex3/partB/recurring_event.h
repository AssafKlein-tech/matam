#ifndef RECURRING_EVENT_H_
#define RECURRING_EVENT_H_
#include "event_container.h"


namespace mtm{

    template <class EventType>
    class RecurringEvent: public EventContainer{
    public:
        RecurringEvent(const DateWrap& first_date,const std::string& name, int num_occurrences, int interval_days);
        void add(const BaseEvent& event);
        ~RecurringEvent()=default;
    };

    template <class EventType>
    RecurringEvent<EventType>::RecurringEvent(const DateWrap& first_date, const std::string& name, int num_occurrences, int interval_days)
    {
        if (num_occurrences <= 0)
            throw InvalidNumber();
        if (interval_days <= 0)
            throw InvalidInterval();
        EventType event_to_enter = EventType(first_date,name);
        DateWrap date = first_date;
        Insert(event_to_enter);
        for(int i = 1; i < num_occurrences; i++)
        {
            event_to_enter = EventType(date + (i * interval_days),name);
            Insert(event_to_enter);
        }
    }

    template <class EventType>
    void RecurringEvent<EventType>::add(const BaseEvent& event)
    {
        throw NotSupported();
    }

}
#endif