#include "event_queue.h"

namespace mtm{

    EventQueue::~EventQueue(){}
    bool EventQueue::contains(const BaseEvent& event) const{}
    void EventQueue::Insert(const BaseEvent& event){}
    BaseEvent& EventQueue::getFirst() const{}
    BaseEvent& EventQueue::getnext() const{}
    BaseEvent& EventQueue::getlast() const{}
}
