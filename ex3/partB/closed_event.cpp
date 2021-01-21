#include "closed_event.h"


namespace mtm{

    ClosedEvent::ClosedEvent(DateWrap date, string name):
        BaseEvent(date,name)
    {
        invited_list->clear();
    }

    ClosedEvent::ClosedEvent(ClosedEvent& event):
        BaseEvent(event)
    {
        node<int>* curr_invtee = event.invited_list->first;
        while(curr_invtee)
        {
            invited_list->add(curr_invtee->data);
            curr_invtee = curr_invtee->next;
        }
    }

    ClosedEvent ClosedEvent::operator=(ClosedEvent& event)
    {
        LinkedList<int>* temp_member_list;
        node<int>* curr_member = event.member_list->first;
        while(curr_member)
        {
            temp_member_list->add(curr_member->data);
            curr_member = curr_member->next;
        }
        delete member_list;
        member_list = temp_member_list;


        LinkedList<int>* temp_invited_list;
        node<int>* curr_invited = event.invited_list->first;
        while(curr_invited)
        {
            temp_invited_list->add(curr_invited->data);
            curr_invited = curr_invited->next;
        }
        delete invited_list;
        member_list = temp_invited_list;


        name = event.name;
        date = event.date;
    }

    ClosedEvent::~ClosedEvent()
    {
        delete invited_list;
    }

    ClosedEvent* ClosedEvent::clone()
    {
        return new ClosedEvent(*this);
    }

    void ClosedEvent::addInvitee(int student)
    {
        if(student<1)
            throw(InvalidStudent());
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
        if(student<1)
            throw(InvalidStudent());
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