#include "base_event.h"


namespace mtm{

    BaseEvent::BaseEvent(DateWrap& date, std::string name):
        name(name),
        date(date)
        {this}

    void BaseEvent::unregisterParticipant(int student)
    {


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
        return new BaseEvent(*this);

    }
}


