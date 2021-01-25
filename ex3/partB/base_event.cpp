#include "base_event.h"
using std::string;
namespace mtm{

    //protected functions
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
    
    void BaseEvent::assign(const BaseEvent& event)
    {
        member_list = event.member_list;
        name = event.name;
        date = event.date;
    }

    bool BaseEvent::isValidStudent(int student)
    {
        return (student > 0) && (student <= 1234567890);
    }

    //BaseEvent Methods
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

    void BaseEvent::unregisterParticipant(int student)
    {
        if(!isValidStudent(student))
        {
            throw InvalidStudent();
        }
        if(!member_list.sub(student))
        {
            throw NotRegistered();
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

    //Added operators
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
    bool BaseEvent::compareEventsDateWithADate(const DateWrap& date) const
    {
        return this->date == date;
    }
    
    bool BaseEvent::isEventGreaterThanDate(const DateWrap& date) const
    {
        return this->date > date;
    }

    bool BaseEvent::compareEventsNameWithAName(const string& name) const
    {
        return this->name == name;
    }

}


