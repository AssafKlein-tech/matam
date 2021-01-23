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
    class BaseEvent
    {
    protected:    
        DateWrap date;
        string name;
        LinkedList<int> member_list;
        void InsertParticipant(int student);
        void assign(const BaseEvent& event);
        void copyMembersFromEvent(const BaseEvent& event);
        bool isValidStudent(int student);

    public: 
        BaseEvent(DateWrap date, string name);
        BaseEvent(const BaseEvent& event);
        virtual ~BaseEvent();
        virtual BaseEvent& operator=(const BaseEvent& event);
        virtual BaseEvent* clone() const = 0;

        virtual void registerParticipant(int student) = 0;
        virtual void unregisterParticipant(int student);
        virtual ostream& printShort(ostream& stream);
        virtual ostream& printLong(ostream& stream);
        bool operator==(const BaseEvent& event) const;
        bool operator!=(const BaseEvent& event) const;
        bool operator>(const BaseEvent& event) const;
        bool operator<(const BaseEvent& event) const;

        /**
         * @brief compare between the event and a given date
         * 
         * @param date - a date to compare
         * @return true if the date match to the event date
         * @return false otherwise
         */
        bool compareEventsDateWithADate(DateWrap& date) const;

        /**
         * @brief check if the event.date is greater(later) than the given date
         * 
         * @param date a date to compare to
         * @return true if the event is later
         * @return false otherwise
         */
        bool isEventGreaterThanDate(DateWrap& date) const;
        bool compareEventsNameWithAName(string& name) const; 
    
        
       //temp for tests
        string getName()
        {
            return name;
        }

    };

}

#endif