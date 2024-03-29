#include "closed_event.h" 

namespace mtm{

    ClosedEvent::ClosedEvent(DateWrap date, std::string name):
        BaseEvent(date,name)
    {
    }

    ClosedEvent::ClosedEvent(const ClosedEvent& event):
        BaseEvent(event)
    {
        Node<int>* curr_invtee = event.invited_list.first;
        while(curr_invtee)
        {
            invited_list.add(curr_invtee->data);
            curr_invtee = curr_invtee->next;
        }
    }

    ClosedEvent& ClosedEvent::operator=(const ClosedEvent& event)
    {
        assign(event);
        invited_list = event.invited_list;
        return *this;
    }

    ClosedEvent* ClosedEvent::clone() const
    {
        return new ClosedEvent(*this);
    }

    void ClosedEvent::addInvitee(int student)
    {
        if(!isValidStudent(student))
        {
            throw InvalidStudent();
        }
        Node<int>* curr_invited = invited_list.first;
        while (curr_invited)
        {
            if(student==curr_invited->data)
                throw AlreadyInvited();
            curr_invited = curr_invited->next;
        }
        invited_list.add(student);
     }

    void ClosedEvent::registerParticipant(int student)
    {
        if(!isValidStudent(student))
        {
            throw InvalidStudent();
        }
        Node<int>* curr_invited = invited_list.first;
        bool not_entered = true;
        while(curr_invited)
        {
            if(student==curr_invited->data)
            {
                not_entered = false;
                InsertParticipant(student);
            }
            curr_invited = curr_invited->next;
        }
        if(not_entered)
            throw(RegistrationBlocked());
    }

}