#ifndef EVENT_CONTAINER_H_
#define EVENT_CONTAINER_H_
#include <stdbool.h>
#include "base_event.h"
#include "exceptions.h"

namespace mtm{

    class Node_event
    {
        friend class EventContainer;
        BaseEvent* event_ptr;
        Node_event *next;
        
    public:
        /**
         * @brief Construct a new Node_event object 
         * @param base_event - BaseEvent object the for the bew node
         */
        Node_event(const BaseEvent& base_event):
            event_ptr((&base_event)->clone()){
            }
        /**
         * @brief Destroy the Node_event object 
         */
        ~Node_event();
    };

    class EventContainer
    {
        Node_event *head;

    protected:
        /**
         * @brief Get the Insertion Place Node to enter the new Node after
         * 
         * @param event - the event of the new node
         * @return Node_event* the insertion place
         */
        Node_event* getInsertionPlace(const BaseEvent& event);

        /**
         * @brief Inserting a new node with "event"
         * 
         * @param event the event to enter to the node
         */
        void Insert(const BaseEvent& event);

        /**
         * @brief checks if the Events queue contains the event
         * 
         * @param event the event
         * @return true if it contains it
         * @return false otherwise
         */
        bool contains(const BaseEvent& event);

    public:
        class EventIterator{
            Node_event* current_event;
        public:
            EventIterator(Node_event* pointer);
            EventIterator& operator++();
            BaseEvent& operator*() const;
            bool operator==(const EventIterator& iterator) const;
            bool operator!=(const EventIterator& iterator) const;
        protected:
        }; 

        EventContainer() {}
        virtual void add(const BaseEvent& event) = 0;
        EventIterator begin() const;
        EventIterator end() const;
        virtual ~EventContainer();
    };

}

#endif