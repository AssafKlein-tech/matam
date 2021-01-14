#ifndef RECURRING_EVENT_H_
#define RECURRING_EVENT_H_
#include "event_container.h"


namespace mtm{

    template <class EventType>
    class Recurring: public EventContainer{
        DateWrap date;
    public:
        Festival(DateWrap& date);
        void add(BaseEvent& event);
        ~Festival(){}
    };

}
#endif