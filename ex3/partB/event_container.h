#ifndef EVENT_CONTAINER_H_
#define EVENT_CONTAINER_H_
#include <iostream>
using std::ostream;
#include <stdbool.h>
#include "base_event.h"
#include "event_queue.h"
#include "exceptions.h"

namespace mtm{
    class EventContainer
    {
    
    public:

    private:
        EventQueue events;
    protected:
        void primitiveAdd(BaseEvent& event);

    public:
        class EventIterator{};

        EventContainer() {}
        virtual void add(BaseEvent& event) = 0;
        EventIterator begin();
        EventIterator end();
        virtual ~EventContainer() {}

        class NotSupported: public Exception {};

        class EventIterator{
                BaseEvent* current_event;
                EventContainer& container;
        public:
            EventIterator(EventContainer& container);
            EventIterator& operator++();
            BaseEvent& operator*() const;
            bool operator==(const EventIterator& iterator) const;
            bool operator!=(const EventIterator& iterator) const;
        protected:
        };  
    };

}

#endif