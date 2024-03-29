#ifndef BASE_EVENT_H_
#define BASE_EVENT_H_
#include<string.h>
#include <iostream>
#include "date_wrap.h"
#include "linked_list.h"

namespace mtm{
    class BaseEvent{

    protected:    
        //member parameters
        DateWrap date;
        std::string name;
        LinkedList<int> member_list;
        /**
         * @brief Inserts a new particiapnt to the event.
         * @param student The particiapnt's ID
         */
        void InsertParticipant(int student);

         /**
         * @brief Copy all event's details.
         * @param event The event to be copied.
         */
        void assign(const BaseEvent& event);


        /**
         * @brief checks if the student is valid
         * 
         * @param student The particiapnt's ID
         * @return true if its valid
         * @return false otherwise
         */
        bool isValidStudent(int student);

    public: 
        BaseEvent(DateWrap date, std::string name);
        BaseEvent(const BaseEvent& event);
        virtual ~BaseEvent() =default;
        virtual BaseEvent& operator=(const BaseEvent& event);
        virtual BaseEvent* clone() const = 0;

        virtual void registerParticipant(int student) = 0;
        virtual void unregisterParticipant(int student);
        virtual std::ostream& printShort(std::ostream& stream);
        virtual std::ostream& printLong(std::ostream& stream);
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
        bool compareEventsDateWithADate(const DateWrap& date) const;

        /**
         * @brief check if the event.date is greater(later) than the given date
         * 
         * @param date a date to compare to
         * @return true if the event is later
         * @return false otherwise
         */
        bool isEventGreaterThanDate(const DateWrap& date) const;

        /**
         * @brief compare this event.name with the given name
         * 
         * @param name the name to compare to
         * @return true if the event name is the same as given
         * @return false otherwise
         */
        bool compareEventsNameWithAName(const std::string& name) const; 
    

        //for yans tests
        std::string getName()
        {
            return name;
        }
    };
}
#endif