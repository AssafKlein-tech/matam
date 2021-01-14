#include "event_container.h"

namespace mtm{

    //Event_Node
    Node_event::~Node_event()
    {
        delete event_ptr;
    }

    //EventContainer protected
    Node_event* EventContainer::getInsertionPlace(const BaseEvent& event)
    {
        Node_event* tmp_ptr = head;
        if (!head)
        {
            return NULL;
        }
        while (tmp_ptr->next && event > *(tmp_ptr->next->event_ptr))
        {
            tmp_ptr = tmp_ptr->next;
        }
        return tmp_ptr;
    }
    bool EventContainer::contains(const BaseEvent& event)
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
    void EventContainer::Insert(const BaseEvent& event)
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
                Node_event* current = getInsertionPlace(event);
                new_node->next = current->next;
                current->next = new_node;
            }
        }
    }

   //EventContainer methods
    EventContainer::EventIterator EventContainer::begin()
    {
        return EventContainer::EventIterator(head);
    }

    EventContainer::EventIterator EventContainer::end()
    {
        Node_event* tmp_node = head;
        if (!tmp_node)
        {
            return EventContainer::EventIterator(head);
        }
        while (tmp_node->next)
        {
            tmp_node = tmp_node->next;
        }
        return EventContainer::EventIterator(tmp_node->next);
    }


    //EventIterator methods
    EventContainer::EventIterator::EventIterator(Node_event* pointer):
        current_event(pointer)
    {     
    }

    EventContainer::EventIterator& EventContainer::EventIterator::operator++()
    {
        current_event = current_event->next;
        return *this;
    }

    BaseEvent& EventContainer::EventIterator::operator*() const
    {
        return *(current_event->event_ptr);
    }

    bool EventContainer::EventIterator::operator==(const EventIterator& iterator) const
    {
        return current_event == iterator.current_event;
    }

    bool EventContainer::EventIterator::operator!=(const EventIterator& iterator) const
    {
        return current_event != iterator.current_event;
    }

}