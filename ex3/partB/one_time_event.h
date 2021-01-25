#ifndef ONE_TIME_EVENT_H_
#define ONE_TIME_EVENT_H_
#include "event_container.h"


namespace mtm{

    template <class EventType>
    class OneTimeEvent: public EventContainer
    {
    public:
<<<<<<< HEAD
        OneTimeEvent(DateWrap date, std::string name);
        void add(const BaseEvent& event);
        OneTimeEvent* clone() const;
        ~OneTimeEvent()=default;
=======
        OneTimeEvent(DateWrap date, string name);
        void add(const BaseEvent& event) override;
        OneTimeEvent* clone() const;
        ~OneTimeEvent() = default;
>>>>>>> 07eca301b4a802bddb0dfd7fd4053397b709db72
    };
    
    template <class EventType>
    OneTimeEvent<EventType>::OneTimeEvent(DateWrap date, std::string name)
    {
        EventType event_to_enter = EventType(date,name);
        Insert(event_to_enter);
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