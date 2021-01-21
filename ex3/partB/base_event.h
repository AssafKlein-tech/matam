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
        BaseEvent(DateWrap date, string name);
        BaseEvent(const BaseEvent& event);
        virtual ~BaseEvent();
        virtual BaseEvent& operator=(BaseEvent& event);
        virtual BaseEvent* clone() const = 0;

        virtual void registerParticipant(int student);
        virtual void unregisterParticipant(int student);
        virtual ostream& printShort(ostream& stream);
        virtual ostream& printLong(ostream& stream);
        bool operator==(const BaseEvent& event) const;
        bool operator!=(const BaseEvent& event) const;
        bool operator>(const BaseEvent& event) const;
        bool operator<(const BaseEvent& event) const;
        bool compareEventsDateWithADate(DateWrap& date) const;
        bool isEventGreaterThanDate(DateWrap& date) const;
        bool compareEventsNameWithAName(string& name) const; 
        void copyMembersFromEvent(BaseEvent& event);
        

        //temp for tests
        string getName()
        {
            return name;
        }

    protected:    
        DateWrap date;
        string name;
        LinkedList<int> *member_list;
        void InsertParticipant(int student);
        void assign(const BaseEvent& event);

    };

}

#endif