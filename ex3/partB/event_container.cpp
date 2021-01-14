#include "event_container.h"

namespace mtm{

    //EventIterator methods
    EventContainer::EventIterator::EventIterator(EventContainer& container):
        container(container),
        current_event(container.events.getFirst())
    {     
    }

    EventContainer::EventIterator& EventContainer::EventIterator::operator++()
    {
        current_event = container.events.getNext();
        return *this;
    }

    BaseEvent& EventContainer::EventIterator::operator*() const
    {
        return *current_event;
    }

    bool EventContainer::EventIterator::operator==(const EventIterator& iterator) const
    {

    }

    bool EventContainer::EventIterator::operator!=(const EventIterator& iterator) const
    {
        
    }


    //EventContainer protected
    void EventContainer::primitiveAdd(BaseEvent& event)
    {
        events.Insert(event);
    }

    //EventContainer methods
    EventContainer::EventIterator EventContainer::W()
    {
        return EventIterator(*this);
    }

    EventContainer::EventIterator EventContainer::end()
    {

    }


}