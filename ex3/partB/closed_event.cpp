#include "closed_event.h"


namespace mtm{

    
    
    ClosedEvent::ClosedEvent(DateWrap date, string name):
        BaseEvent(date,name)
    {
        invited_list->clear();
    }

    ClosedEvent::ClosedEvent(ClosedEvent& event)
    {
        node<int>* curr_invtee = event.invited_list->first;
        while(curr_invtee)
        {
            invited_list->add(curr_invtee->data);
            curr_invtee = curr_invtee->next;
        }
    }

    ClosedEvent::~ClosedEvent()
    {
        delete invited_list;
    }

    ClosedEvent* ClosedEvent::clone()
    {
        return new ClosedEvent(*this);
    }

    void ClosedEvent::addinvitee (int student)
    {
        node<int>* curr_invited = invited_list->first;
        while (curr_invited)
        {
            if(student==curr_invited->data)
                throw AlreadyInvited();
            curr_invited = curr_invited->next;
        }
        invited_list->add(student);
     }

    void ClosedEvent::registerParticipant(int student)
    {
        node<int>* curr_invited=invited_list->first;
        while(curr_invited)
        {
            if(student==curr_invited->data)
            {
               InsertParticipant(student);
            }
            curr_invited = curr_invited->next;
        }
        if(!curr_invited)
            throw(RegistrationBlocked());
    }

}