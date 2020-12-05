#ifndef EVENT_H_
#define EVENT_H_

#include<member.h>
#include <stdbool.h>

/** Type for defining the event */
typedef struct Event_t *Event;

/**
* eventCreate: Allocates a new event.
*
* @param event_name - the name of the event.
* @param event_id - the ID of the event.
* @return
* 	NULL - if allocation failed or event is illegal.
* 	A new Event in case of success.
*/

Event eventCreate(char* event_name, int event_id);

/**
* eventDestroy: Deallocates an existing Event.
*
* @param event - Target event to be deallocated. If priority queue is NULL nothing will be done
*/

void eventDestroy(Event event);


/**
* dateCopy: Creates a copy of target Event.
*
* @param event - Target Event.
* @return
* 	NULL if a NULL was sent or a memory allocation failed.
* 	A Date containing the same elements as date otherwise.
*/

Event eventCopy(Event event);



bool eventCompare(Event event1, Event event2);

int getEventsId(Event event);


char* getEventsId(Event event)
#endif //EVENT_H_