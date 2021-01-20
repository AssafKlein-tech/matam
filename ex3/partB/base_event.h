#ifndef BASE_EVENT_H_
#define BASE_EVENT_H_
#include<string.h>
#include <iostream>
using std::ostream;
#include "date_wrap.h"
#include "generic_linked_list.h"
using std::string;
#include "exceptions.h"
// we need <,>,==,!= (regular, and with date to compare) copyC'tor
namespace mtm{
    class BaseEvent{
    public: 
        BaseEvent(DateWrap& date, string& name);
        BaseEvent(BaseEvent& event);
        virtual ~BaseEvent();
        virtual BaseEvent& operator=(BaseEvent& event);
        virtual BaseEvent* clone() = 0;

        virtual void registerParticipant(int student);
        virtual void unregisterParticipant(int student);
        virtual ostream& printShort(ostream& stream);
        virtual ostream& printLong(ostream& stream);
        bool operator==(const BaseEvent& event) const;
        bool operator!=(const BaseEvent& event) const;
        bool operator>(const BaseEvent& event) const;
        bool operator<(const BaseEvent& event) const;
        bool compareEventsDateWithADate(DateWrap& date);
        bool isEventGreaterThanDate(DateWrap& date);
        bool compareEventsNameWithAName(string& name);
        
        
    protected:    
        DateWrap date;
        string name;
        LinkedList<int> *member_list;
        void InsertParticipant(int student);

    };

}

#endif