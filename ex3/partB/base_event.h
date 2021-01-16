#ifndef BASE_EVENT_H_
#define BASE_EVENT_H_
#include<string.h>
#include <iostream>
using std::ostream;
#include "date_wrap.h"
#include "generic_linked_list.h"
using std::string;

// we need <,>,==,!= (regular, and with date to compare) copyC'tor
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
        BaseEvent();
        DateWrap date;
        string name;
        LinkedList<int> *member_list;

    };

}

#endif