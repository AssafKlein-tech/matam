#ifndef EVENT_CONTAINER_H_
#define EVENT_CONTAINER_H_
#include <iostream>
using std::ostream;
#include <stdbool.h>
#include "base_event.h"
#include "event_queue.h"

namespace mtm{
    class EventContainer{
        // base event in a priority queue
        EventIterator itrator;
    public:

    EventContainer() {}
    virtual add(BaseEvent& event) = 0;
    virtual EventIterator begin() const;
    virtual EventIterator end() const;
    virtual ~EventContainer() {}

    class NotSupported: public Exception {};

    class EventIterator:{
        BaseEvent* event; 

    public:
        EventIterator();
        EventIterator& operator++();
        BaseEvent& operator*() const;
        bool operator==(const EventIterator& iterator) const;
        bool operator!=(const EventIterator& iterator) const;
    }
    protected:    

    };

}

#endif