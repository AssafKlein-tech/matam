#ifndef BASE_EVENT_H_
#define BASE_EVENT_H_
#include<string.h>
using std::ostream;
#include <iostream>
#include "date_wrap.h"

namespace mtm{
    class BaseEvent{
    public:
    BaseEvent::BaseEvent(DateWrap date, std::string name);
    virtual void BaseEvent::registerParticipant(int student)=0;
    virtual void BaseEvent::unregisterParticipant(int student);
    virtual void BaseEvent::printShort(std::ostream stream);
    virtual void BaseEvent::printLong(std::ostream stream);
    virtual BaseEvent& BaseEvent::clone();
    
    protected:    
        DateWrap date;
         std::string name;
         struct Members_list
    {
        int member;
        struct Members_list *next;
    } *members; 
    };

}

#endif