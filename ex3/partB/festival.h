#ifndef FESTIVAL_H_
#define FESTIVAL_H_
#include "event_container.h"

namespace mtm{

    class Festival: public EventContainer{

        DateWrap date;
        
    public:
        Festival(DateWrap date);
        void add(const BaseEvent& event);
        ~Festival()=default;
    };
}
#endif