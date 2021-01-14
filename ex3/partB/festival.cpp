#include "festival.h"

namespace mtm{
    Festival::Festival(DateWrap& date): date(DateWrap(date))
    {
    }

    void Festival::add(BaseEvent& event)
    {
<<<<<<< HEAD
        if(event != date)
=======
        if(event != BaseEvent(date,""))
>>>>>>> f084deb... חדש
        {
            throw DateMismatch();
        }
        Insert(event);
    }

}