#include "event_queue.h"

namespace mtm{

    //Event_Node
    Node_event::~Node_event()
    {
        delete event_ptr;
    }
/*
    Node_event& Node_event::operator=(const Node_event& node)
    {
        if (this == &node)
            return *this;
        delete event_ptr;
        event_ptr = node.event_ptr.clone();
        next = node.next;
        return *this;
    }

    Node_event::Node_event(const Node_event& node)
    {

    }
*/

    //EventQueue Private
    Node_event* EventQueue::getInsertionPlace(const BaseEvent& event)
    {
        current = head;
        if (!head)
        {
            return NULL;
        }
        while (current->next && event > *(current->next->event_ptr))
        {
            current = current->next;
        }
        return current;
    }

    //EventQueue methodes
    EventQueue::~EventQueue()
    {
        current = head;
        Node_event *next_to_delete;
        while(current)
        {
            next_to_delete = current->next;
            delete current;
            current = next_to_delete;
        }
    }

    bool EventQueue::contains(const BaseEvent& event)
    {
        Node_event *tmp = head;
        while(tmp)
        {
            if(*(tmp->event_ptr) == event)
            {
                return true;
            }
            tmp = tmp->next;
        }
        return false;
    }

    void EventQueue::Insert(const BaseEvent& event)
    {
        if (!contains(event))
        {
            Node_event* new_node = new Node_event(event);
            if (!head)
            {
                head = new_node;
            }
            else if (event < *(head->event_ptr))
                {
                    new_node->next = head;
                    head = new_node;
                }
            else
            {
                current = getInsertionPlace(event);
                new_node->next = current->next;
                current->next = new_node;
            }
            current = NULL;
        }
    }

    BaseEvent* EventQueue::getFirst() 
    {
        if(head)
        {
            current = head;
            return head->event_ptr;
        }
        return NULL;
    }

    BaseEvent* EventQueue::getNext() 
    {
        if(!current)
        {
            return NULL;
        }
        if(!current->next)
        {
            return NULL;
        }
        current = current->next;
        return current->event_ptr;
    }

    BaseEvent* EventQueue::getLast() 
    {
        
        return NULL;
    }
}
