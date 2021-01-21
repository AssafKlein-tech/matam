#include "festival.h"

namespace mtm{
    Festival::Festival(DateWrap& date): EventContainer(), date(DateWrap(date))
    {
    }

    void Festival::add(BaseEvent& event)
    {
        if(!event.compareEventsDateWithADate(date))
        {
            throw DateMismatch();
        }
        Insert(event);
    }

}