#include "festival.h"

namespace mtm{
    Festival::Festival(DateWrap& date): date(DateWrap(date))
    {
    }

    void Festival::add(BaseEvent& event)
    {
        if(event != date)
        {
            throw DateMismatch();
        }
        Insert(event);
    }

}