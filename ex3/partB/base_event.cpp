#include "base_event.h"


namespace mtm{

    BaseEvent::BaseEvent(DateWrap& date, string& name):
        name(name),
        date(date)
        {
            member_list->clear();
        }
    
    BaseEvent::BaseEvent(const BaseEvent& event): 
        date(event.date)
        {
            name = event.name;
            member_list 
        }

    BaseEvent& BaseEvent::operator=(const BaseEvent& event)
    {

    }

    BaseEvent::~BaseEvent()
    {
        delete member_list;
    }

    void BaseEvent::unregisterParticipant(int student)
    {
        if(!member_list->sub(student))
            throw(NotRegistered());
    }

    ostream& BaseEvent::printShort(ostream& stream)
    {
        return stream<< name<<" "<<this->date.day()<<"/"<<this->date.month()<<"/"<<this->date.year();
    }

    ostream& BaseEvent::printLong(ostream& stream)
    {
        return stream<< name<<" "<<this->date.day()<<"/"<<this->date.month()<<"/"<<this->date.year();
        //printShort(stream);
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
}


