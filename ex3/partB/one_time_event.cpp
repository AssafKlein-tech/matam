#include "recurring_event.h"

namespace mtm{
    
    template <class EventType>
    OneTimeEvent<EventType>::OneTimeEvent(DateWrap& date, string name):
    {
        this.Insert(EventType(date,name));
    }

    template <class EventType>
    void OneTimeEvent<EventType>::add(BaseEvent& event)
    {
        throw NotSupported();
    }
}