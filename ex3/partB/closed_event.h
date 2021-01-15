#ifndef CLOSED_EVENT_H
#define CLOSED_EVENT_H
#include "base_event.h"

namespace mtm{
    class ClosedEvent:public BaseEvent{
    public:
     ClosedEvent::ClosedEvent(DateWrap date, std::string name);
     void addinvitee (int student);
     void ClosedEvent::registerParticipant(int student) override;
     void ClosedEvent::unregisterParticipant(int student);
     void ClosedEvent::printShort(std::ostream stream);
     void ClosedEvent::printLong(std::ostream stream);
     ClosedEvent* clone() override {return new ClosedEvent(*this);}
    
    protected:    
          LinkedList<int> invited_list;

    };



    };

#endif