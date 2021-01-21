#ifndef ONE_TIME_EVENT_H_
#define ONE_TIME_EVENT_H_
#include "event_container.h"


namespace mtm{

    template <class EventType>
    class OneTimeEvent: public EventContainer
    {
    public:
        OneTimeEvent(DateWrap date, string name);
        void add(const BaseEvent& event);
        OneTimeEvent* clone() const;
        ~OneTimeEvent(){}
    };
    
    template <class EventType>
    OneTimeEvent<EventType>::OneTimeEvent(DateWrap date, string name)
    {
        Insert(EventType(date,name));
    }

    template <class EventType>
    void OneTimeEvent<EventType>::add(const BaseEvent& event)
    {
        throw NotSupported();
    }

    template <class EventType>
    OneTimeEvent<EventType>* OneTimeEvent<EventType>::clone() const
    {
        return new OneTimeEvent<EventType>(*this);
    }
}
#endif