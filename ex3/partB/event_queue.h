#ifndef EVENT_QUEUE_H_
#define EVENT_QUEUE_H
#include "date_wrap.h"
#include "base_event.h"

namespace mtm{
    class EventQueue{
        class Node_event
        {
            DateWrap priority;
            BaseEvent event
        }
    }
}
#endif