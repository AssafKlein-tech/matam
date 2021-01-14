#ifndef BASE_EVENT_H_
#define BASE_EVENT_H_
#include<string.h>
using std::ostream;
#include <iostream>
#include "date_wrap.h"
#include "generic_queue.h"
using std::string;

// we need <,>,==, copyC'tor
namespace mtm{
    class BaseEvent{
    public: 
        BaseEvent(DateWrap& date, string name);
        virtual void registerParticipant(int student)=0;
        virtual void unregisterParticipant(int student);
        virtual void printShort(ostream stream);
        virtual void printLong(ostream stream);
        virtual BaseEvent* clone();
    
    protected:    

        DateWrap date;
        string name;
        Stack<int> *member_stack;

    };

}

#endif