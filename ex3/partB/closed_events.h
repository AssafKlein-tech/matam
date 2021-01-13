#include "base_event.h"

namespace mtm{
    class ClosedEvent:public BaseEvent{
    public:
    ClosedEvent::ClosedEvent(DateWrap date, std::string name);
     void ClosedEvent::registerParticipant(int student);
     void ClosedEvent::unregisterParticipant(int student);
     void ClosedEvent::printShort(std::ostream stream);
     void ClosedEvent::printLong(std::ostream stream);
     ClosedEvent* clone() override {return new ClosedEvent(*this);}
    
    };

}