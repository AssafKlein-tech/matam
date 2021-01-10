#ifndef BASE_EVENT_H_
#define BASE_EVENT_H_
#include<string.h>
using std::ostream;
#include <iostream>
#include "date_wrap.h"

namespace mtm{
    class BaseEvent{
         DateWrap date;
         std::string name;
         struct Members_list
    {
        int member;
        struct Members_list *next;
    } *members; 
     
    public:
    BaseEvent(DateWrap date, std::string name);
    registerParticipant(int student)
    unregisterParticipant(int student)
    printShort(std::ostream stream)
    printLong(std::ostream stream)
    clone()
    
    protected:    

    };

}

#endif