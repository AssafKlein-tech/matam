#ifndef EVENT_QUEUE_H_
#define EVENT_QUEUE_H
#include "date_wrap.h"
#include "base_event.h"

namespace mtm{

    class EventQueue{

        class Node_event
        {
            BaseEvent event;
            Node_event *next;
        };

        Node_event *head,*current,*tail;

    public:

        EventQueue() = default;
        ~EventQueue();
        bool contains(const BaseEvent& event) const;
        void Insert(const BaseEvent& event);
        BaseEvent& getFirst() const;
        BaseEvent& getnext() const;
        BaseEvent& getlast() const;
    };
}
#endif