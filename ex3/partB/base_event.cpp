#include "base_event.h"


namespace mtm{

    BaseEvent::BaseEvent(DateWrap& date, string& name):
        name(name),
        date(date)
        {
            member_list->clear();
        }
<<<<<<< HEAD

    BaseEvent::~BaseEvent()
    {
=======
    
    BaseEvent::BaseEvent(BaseEvent& event): 
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
        LinkedList<int>* temp_list;
        node<int>* curr_member = event->member_list->first;
        while(curr_member)
        {
            temp_list->add(curr_member->data);
            curr_member = curr_member->next;
        }
        delete member_list;
        member_list = temp_list;
        name = event.name;
        date = event.date;
    }

    BaseEvent::~BaseEvent()
    {
>>>>>>> 2cde6ab6c24f5fe7acff452dabb7bcd955101bd7
        delete member_list;
    }

    void BaseEvent::unregisterParticipant(int student)
    {
        if(!member_list->sub(student))
            throw(NotRegistered());
    }
<<<<<<< HEAD
    
=======

>>>>>>> 2cde6ab6c24f5fe7acff452dabb7bcd955101bd7
    ostream& BaseEvent::printShort(ostream& stream)
    {
        return stream<<name<<" "<<this->date.day()<<"/"<<this->date.month()<<"/"<<this->date.year();
    }

    ostream& BaseEvent::printLong(ostream& stream)
    {
        printShort(stream);
        stream<<"\n";
        member_list->sort();
        node<int>* curr_member = event->member_list->first;
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

    bool BaseEvent::compareEventsDateWithADate(DateWrap& date)
    {
        return this->date==date;
    }
    
    bool BaseEvent::isEventGreaterThanDate(DateWrap& date)
    {
        return this->date>date;
    }

    bool BaseEvent::compareEventsNameWithAName(string& name)
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


