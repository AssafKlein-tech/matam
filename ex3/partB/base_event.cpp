#include "base_event.h"


namespace mtm{

    BaseEvent::BaseEvent(DateWrap& date, std::string name):
        name(name),
        date(date)
        {member_list->clear();
        }



    void BaseEvent::unregisterParticipant(int student)
    {
    if(!member_list->sub(student))
        throw(NotRegistered());
    }

    
    void BaseEvent::printShort(std::ostream stream)
    {
        stream<< name<<" "<<this->date.day()<<"/"<<this->date.month()<<"/"<<this->date.year();
    }
    void BaseEvent::printLong(std::ostream stream)
    {
        stream<< name<<" "<<this->date.day()<<"/"<<this->date.month()<<"/"<<this->date.year();
        //printShort(stream);
        
        

    }
    BaseEvent* BaseEvent::clone()
    {
        
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

}


