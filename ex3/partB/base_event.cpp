#include "base_event.h"


namespace mtm{

    BaseEvent::BaseEvent(DateWrap& date, std::string name):
        name(name),
        date(date)
        {member_list->clear();
        }
    
    BaseEvent::BaseEvent():
            name(NULL),
            date(NULL)
            {
                member_list->clear();
            }

    void BaseEvent::unregisterParticipant(int student)
    {
    if(!member_list->sub(student))
        //להחזיר שגיאה מסוג סטודנט לא נמצא במאגר



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
        return new BaseEvent&(this);

    }
}


