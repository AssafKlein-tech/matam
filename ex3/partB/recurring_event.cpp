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
}