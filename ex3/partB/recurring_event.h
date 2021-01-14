#ifndef RECURRING_EVENT_H_
#define RECURRING_EVENT_H_
#include "event_container.h"


namespace mtm{

    template <class EventType>
    class RecurringEvent: public EventContainer{
<<<<<<< HEAD
    public:
        RecurringEvent(DateWrap& first_date, string name, int num_occurrences, int interval_days);
        void add(BaseEvent& event) override;
=======
        DateWrap date;
    public:
        RecurringEvent(DateWrap& first_date, string name, int num_occurrences, int interval_days);
        void add(BaseEvent& event);
>>>>>>> bce1169b88b6d3dbdb7ba1504b46e131a04fd5b5
        ~RecurringEvent(){}
    };

}
#endif