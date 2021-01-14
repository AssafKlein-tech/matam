#include "base_event.h"


namespace mtm{

    BaseEvent::BaseEvent(DateWrap& date, std::string name):
        name(name),
        date(date)
        {}

    void BaseEvent::unregisterParticipant(int student)
    {
        while(this->current_memeber)
        {
            if(this->current_memeber->member==student)
            {
            Members_list *clone=this->current_memeber;
            this->current_memeber=this->current_memeber->next;
            delete(clone);
            this->current_memeber=this->current_memeber->next;
            }
        }        
    }

    
    void BaseEvent::printShort(std::ostream stream)
    {
        stream<< name<<" "<<this->date.day()<<"/"<<this->date.month()<<"/"<<this->date.year();
    }
    void BaseEvent::printLong(std::ostream stream)
    {
        printShort(stream);
         Members_list *clone=this->current_memeber;
        while (clone)
        {
            stream<<"\n"<<clone->member;
            clone=clone->next;
        }
        

    }
    BaseEvent* BaseEvent::clone()
    {
        return new BaseEvent(*this);

    }
}


