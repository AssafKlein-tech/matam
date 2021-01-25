#ifndef CLOSED_EVENT_H
#define CLOSED_EVENT_H
#include "base_event.h"

namespace mtm{
    class ClosedEvent:public BaseEvent{
    
    protected:    
        LinkedList<int> invited_list;

    public:
        ClosedEvent(DateWrap date, std::string name);
        ClosedEvent(const ClosedEvent& event);
        ClosedEvent& operator=(const ClosedEvent& event);
        ClosedEvent* clone() const override;
        ~ClosedEvent() {}

        void registerParticipant(int student) override;
        void addInvitee(int student);
    };
}

#endif