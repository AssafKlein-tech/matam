#ifndef OPEN_EVENT_H
#define OPEN_EVENT_H
#include "base_event.h"

namespace mtm{
    class OpenEvent:public BaseEvent{
    
    public:
        OpenEvent(DateWrap date, string name): BaseEvent(date,name) {}
        void OpenEvent::registerParticipant(int student);
        OpenEvent* clone() const override;
        ~OpenEvent() {}
    };

}

#endif