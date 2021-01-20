#include "closed_event.h"


namespace mtm{

    ClosedEvent::ClosedEvent(DateWrap date, std::string name):
    BaseEvent(date,name)
    {
        invited_list->clear();
    }

    ClosedEvent::~ClosedEvent()
    {
        delete(invited_list);
    }

    void ClosedEvent::addinvitee (int student){
        node<int>* curr_invited=invited_list->first;
        while (curr_invited)
        {
            if(student==curr_invited->data)
            throw AlreadyInvited();
        }
        
       invited_list->add(student);
     }

    void ClosedEvent::registerParticipant(int student)
    {
        node<int>* curr_invited=invited_list->first;
        node<int>* curr_member=member_list->first;
        while(curr_invited)
        {
            if(student==curr_invited->data)
            {
               InsertParticipant(student);
                return;
            }
        curr_invited=curr_invited->next;
        }
       throw(RegistrationBlocked());
    }

     ClosedEvent* clone()
     {
         



     }










}