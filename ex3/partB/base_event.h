#ifndef BASE_EVENT_H_
#define BASE_EVENT_H_
#include<string.h>
using std::ostream;
#include <iostream>
#include "date_wrap.h"
#include "generic_stack.h"

// we need <,>,==, copyC'tor
namespace mtm{
    class BaseEvent{
    public: 
    BaseEvent(DateWrap& date, std::string name);
    virtual void registerParticipant(int student)=0;
    virtual void unregisterParticipant(int student);
    virtual void printShort(std::ostream stream);
    virtual void printLong(std::ostream stream);
    virtual BaseEvent* BaseEvent::clone();
    
    protected:    

        DateWrap date;
         std::string name;
         Stack<int> *member_stack;

    };

}

#endif