#include "base_event.h"


namespace mtm{

    void BaseEvent::assign(const BaseEvent& event)
    {
        member_list = event.member_list;
        name = event.name;
        date = event.date;
    }

    BaseEvent::BaseEvent(DateWrap date, string name):
        date(date),
        name(name)
    {
        member_list->clear();
    }
    
    BaseEvent::BaseEvent(const BaseEvent& event): 
        date(event.date)
    {
        name = event.name;
        node<int>* curr_member = event.member_list->first;
        while(curr_member)
        {
            member_list->add(curr_member->data);
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
        delete member_list;
    }

    void BaseEvent::unregisterParticipant(int student)
    {
        if(student<1)
            throw(InvalidStudent());
        if(!member_list->sub(student))
            throw(NotRegistered());
    }

    ostream& BaseEvent::printShort(ostream& stream)
    {
        return stream<<name<<" "<<this->date.day()<<"/"<<this->date.month()<<"/"<<this->date.year();
    }

    ostream& BaseEvent::printLong(ostream& stream)
    {
        printShort(stream);
        stream<<"\n";
        node<int>* curr_member = member_list->first;
        while(curr_member)
        {
            stream<<curr_member->data<<"\n";
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
            return(this->name<event.name);
        return(this->date<event.date);
    }

    bool BaseEvent::operator>(const BaseEvent& event) const
    {
        if(this->date==event.date)
            return(this->name>event.name);
        return(this->date>event.date);
    }

    bool BaseEvent::compareEventsDateWithADate(DateWrap& date) const
    {
        return this->date==date;
    }
    
    bool BaseEvent::isEventGreaterThanDate(DateWrap& date) const
    {
        return this->date>date;
    }

    bool BaseEvent::compareEventsNameWithAName(string& name) const
    {
        return this->name==name;
    }

    void BaseEvent::InsertParticipant(int student)
    {
        node<int>* curr_member=member_list->first;
        while(curr_member)
        {
            if(curr_member->data == student)
                throw AlreadyRegistered();
            member_list->add(student);
        }
    }
}


