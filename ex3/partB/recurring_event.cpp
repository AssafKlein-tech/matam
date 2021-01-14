<<<<<<< HEAD
#include "recurring_event.h"

namespace mtm{
    RecurringEvent::RecurringEvent(DateWrap& date):
    {
        try{
        this.
        } catch (NegativeDays()){
            throw InvalidInterval();
        }
    }

    void RecurringEvent::add(BaseEvent& event)
    {
        throw NotSupported();
    }
=======
#include "recurring_event.h"

namespace mtm{
    RecurringEvent::RecurringEvent(DateWrap& date): date(DateWrap(date))
    {
        this.
    }

    void RecurringEvent::add(BaseEvent& event)
    {
        throw NotSupported();
    }
>>>>>>> f084deb... חדש
}