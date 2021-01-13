#include "event_queue.h"

namespace mtm{

    //Event_Node
    Node_event::Node_event(BaseEvent event)
    {
        this->event = event;
        next = NULL;
    }

    //EventQueue
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
            if(tmp->event == event)
            {
                return true;
            }
            tmp = tmp->next;
        }
        return false;
    }

    void EventQueue::Insert(const BaseEvent& event)
    {
        Node_event *tmp = head;
        while(tmp)
        {
            if(tmp->event == event)
            {
                return true;
            }
            tmp = tmp->next;
        }
        return false;
    }

    BaseEvent& EventQueue::getFirst() const{}
    BaseEvent& EventQueue::getnext() const{}
    BaseEvent& EventQueue::getlast() const{}
}
