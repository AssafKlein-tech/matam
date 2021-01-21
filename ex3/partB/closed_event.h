#ifndef CLOSED_EVENT_H
#define CLOSED_EVENT_H
#include "base_event.h"

namespace mtm{
    class ClosedEvent:public BaseEvent{
    
    public:
        ClosedEvent(DateWrap date, string name);
        ClosedEvent(ClosedEvent& event);
        ClosedEvent operator=(ClosedEvent& event);
        ClosedEvent* clone() override;
        ~ClosedEvent();

        void registerParticipant(int student) override;
        void addinvitee(int student);

    protected:    
        LinkedList<int> *invited_list;

    };
}

#endif