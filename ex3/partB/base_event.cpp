#include "base_event.h"

namespace mtm{

    void BaseEvent::InsertParticipant(int student)
     {
 
        Node<int>* curr_member = member_list.first;
            while(curr_member)
            {
                if(curr_member->data==student)
                throw AlreadyRegistered();
                curr_member=curr_member->next;
            }
        
        member_list.add(student);
    }
    
    bool BaseEvent::isValidStudent(int student)
    {
        return (student > 0) && (student <= 1234567890);
    }

    void BaseEvent::copyMembersFromEvent(const BaseEvent& event)
    {
        LinkedList<int> temp_member_list;
        Node<int>* curr_member = event.member_list.first;
        while(curr_member)
        {
            
            temp_member_list.add(curr_member->data);
            curr_member = curr_member->next;
        }
        member_list.clear();
        member_list = temp_member_list;
    }

    void BaseEvent::assign(const BaseEvent& event)
    {
        copyMembersFromEvent(event);
        name = event.name;
        date = event.date;
    }

    BaseEvent::BaseEvent(DateWrap date, string name):
        date(date),
        name(name),
        member_list()
    {
    }
    
    BaseEvent::BaseEvent(const BaseEvent& event): 
        date(event.date),
        name(event.name)
    {
        Node<int>* curr_member = event.member_list.first;
        while(curr_member)
        {
            member_list.add(curr_member->data);
            curr_member = curr_member->next;
        }
    }

    BaseEvent& BaseEvent::operator=(const BaseEvent& event)
    {
        assign(event);
        return *this;
    }

    BaseEvent::~BaseEvent()
    {
    }

    void BaseEvent::unregisterParticipant(int student)
    {
        if(!isValidStudent(student))
        {
            throw(InvalidStudent());
        }
        if(!member_list.sub(student))
        {
            throw(NotRegistered());
        }
    }

    ostream& BaseEvent::printShort(ostream& stream)
    {
        return stream<<name<<" "<<this->date.day()<<"/"<<this->date.month()<<"/"<<this->date.year()<<"\n";
    }

    ostream& BaseEvent::printLong(ostream& stream)
    {
        printShort(stream);
        Node<int>* curr_member = member_list.first;
        while(curr_member)
        {
            stream<<curr_member->data<<"\n";
            curr_member=curr_member->next;
        }
        return stream;
    }

    bool BaseEvent::operator==(const BaseEvent& event) const
    {
        return(this->date==event.date&&this->name==event.name);
    }

    bool BaseEvent::operator!=(const BaseEvent& event) const
    {
        return(!(this->date==event.date&&this->name==event.name));
    }

    bool BaseEvent::operator<(const BaseEvent& event) const
    {
        if(this->date==event.date)
        {
            return(this->name<event.name);
        }
        return(this->date<event.date);
    }

    bool BaseEvent::operator>(const BaseEvent& event) const
    {
        if(this->date==event.date)
        {
            return(this->name>event.name);
        }
        return(this->date>event.date);
    }

    //extra methods
    bool BaseEvent::compareEventsDateWithADate(DateWrap& date) const
    {
        return this->date == date;
    }
    
    bool BaseEvent::isEventGreaterThanDate(DateWrap& date) const
    {
        return this->date > date;
    }

    bool BaseEvent::compareEventsNameWithAName(string& name) const
    {
        return this->name == name;
    }


}


