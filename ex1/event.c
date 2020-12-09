#include "event.h"
#include <stdbool.h>
#include <stdlib.h>
#include "member.h"

struct Event_t
{
    char* event_name;
    int event_id;
    Member* members;
};

Event eventCreate(char* event_name, int event_id){
Event event = malloc(sizeof(*event));
	if (!event) {
		return NULL;
	}
	event->event_id = event_id;
	event->event_name = event_name;
	return event;
}

void eventDestroy(Event event)
{  
      free(event);
}

Event eventCopy(Event event)
{
     if (!event)
        return NULL;
    return eventCreate(event->event_name,event->event_id);
}

bool eventCompare(Event event1, Event event2)
{
    return (getEventsId(event1)==getEventsId(event2));
}

int eventGetId(Event event)
{
    return event->event_id;
}

char* eventGetName(Event event)
{
    return event->event_name;
}