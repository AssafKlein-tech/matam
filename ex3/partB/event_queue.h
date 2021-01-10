#ifndef EVENT_QUEUE_H_
#define EVENT_QUEUE_H
#include "date_wrap.h"
#include "base_event.h"

namespace mtm{
    class Node_event
    {
        BaseEvent event;
        Node_event *next;
    }

    class EventQueue{
        Node_event *head,*tail;

    public:
        
    }
}
#endif