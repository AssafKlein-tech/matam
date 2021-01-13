#ifndef EVENT_QUEUE_H_
#define EVENT_QUEUE_H
#include "date_wrap.h"
#include "base_event.h"
using mtm::BaseEvent;

namespace mtm{

    class Node_event
    {
        friend class EventQueue;
        BaseEvent* event_ptr;
        Node_event *next;
        
    public:
        /**
         * @brief Construct a new Node_event object 
         * @param base_event - BaseEvent object the for the bew node
         */
        Node_event(const BaseEvent& base_event): 
            event_ptr(new BaseEvent(base_event)){}

        /**
         * @brief Destroy the Node_event object 
         */
        ~Node_event();
        /*
        Node_event& operator=(const Node_event& node);
        Node_event(const Node_event& node);
        */
    };

    
    class EventQueue{

        Node_event *head,*current;

    private:

        /**
         * @brief Get the Insertion Place Node to enter the new Node after
         * 
         * @param event - the event of the new node
         * @return Node_event* the insertion place
         */
        Node_event* getInsertionPlace(const BaseEvent& event);

    public:

        /**
         * @brief Construct a new Event Queue object
         */
        EventQueue() = default;
        
        /**
         * @brief Destroy the Event Queue object
         */
        ~EventQueue();

        /**
         * @brief checks if the Events queue contains the event
         * 
         * @param event the event
         * @return true if it contains it
         * @return false otherwise
         */
        bool contains(const BaseEvent& event);

        /**
         * @brief Inserting a new node with "event"
         * 
         * @param event the event to enter to the node
         */
        void Insert(const BaseEvent& event);

        /**
         * @brief Get the First object event. set the current pointer to head
         * 
         * @return BaseEvent* the event of the first node
         */
        BaseEvent* getFirst();

        /**
         * @brief forwarding the current by 1 node and returning it's event
         * 
         * @return BaseEvent* the event of the  current pointer
         */
        BaseEvent* getNext();

        /**
         * @brief returning the last event - NULL
         * 
         * @return BaseEvent* NULL
         */
        BaseEvent* getLast();
    };
}
#endif