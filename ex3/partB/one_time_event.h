#ifndef ONE_TIME_EVENT_H_
#define ONE_TIME_EVENT_H_
#include "event_container.h"


namespace mtm{

    template <class EventType>
    class OneTimeEvent: public EventContainer{
    public:
        OneTimeEvent(DateWrap& date, string name);
        void add(BaseEvent& event);
        ~OneTimeEvent(){}
    };
}
#endif