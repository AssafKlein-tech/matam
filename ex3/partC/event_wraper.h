#ifndef EVENT_WRAPER_H_
#define EVENT_WRAPER_H_
#include "base_event.h"


namespace mtm{

   
    class EventWrap{

    public:
        
        EventWrap();
        EventWrap(const EventWrap& datewrap);
        EventWrap& operator=(const EventWrap& datewrap);
        ~EventWrap();

        bool operator==(const EventWrap& eventwrap) const;
        bool operator>(const EventWrap& eventwrap) const;
        bool operator<(const EventWrap& eventwrap) const;
        bool operator<=(const EventWrap& eventwrap) const;
        bool operator>=(const EventWrap& eventwrap) const;
        bool operator!=(const EventWrap& eventwrap) const;

    };

}

#endif