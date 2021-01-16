#ifndef CLOSED_EVENT_H
#define CLOSED_EVENT_H
#include "base_event.h"

namespace mtm{
    class ClosedEvent:public BaseEvent{
    
    public:
     ClosedEvent::ClosedEvent(DateWrap date, std::string name);
     void ClosedEvent::addinvitee (int student);
     void ClosedEvent::registerParticipant(int student) override;
     ClosedEvent* clone() override;
    
    protected:    
          LinkedList<int> *invited_list;

    };

}

#endif