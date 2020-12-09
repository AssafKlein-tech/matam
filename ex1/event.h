#ifndef EVENT_H_
#define EVENT_H_

#include "date.h"
#include "member.h"
#include <stdbool.h>

/** Type for defining the event */
typedef struct Event_t *Event;

typedef enum EventResult_t {
    EVENT_SUCCESS,
    EVENT_OUT_OF_MEMORY,
    EVENT_NULL_ARGUMENT,
    EVENT_MEMBER_ID_ALREADY_EXISTS
} EventManagerResult;

/**
* eventCreate: Allocates a new event.
*
* @param event_name - the name of the event.
* @param event_id - the ID of the event.
* @return
* 	NULL - if allocation failed or event is illegal.
* 	A new Event in case of success.
*/
Event eventCreate(char* event_name, int event_id, Date date);

/**
* eventDestroy: Deallocates an existing Event.
*
* @param event - Target event to be deallocated. If priority queue is NULL nothing will be done
*/
void eventDestroy(Event event);

/**
* eventCopy: Creates a copy of target Event.
*
* @param event - Target Event.
* @return
* 	NULL if a NULL was sent or a memory allocation failed.
* 	A Date containing the same elements as date otherwise.
*/
Event eventCopy(Event event);

/**
* eventCompare: compares two events and return if they are equal or not.
*@param event1 - first Event
*@param event2 - second Event

* @return
*   true - if they are equal.
*   false - if they are not equal.
*/
bool eventCompare(Event event1, Event event2);

/**
* getEventsId: returns the ID of Target Event.
*@param event -  Target Event
*/
int eventGetId(Event event);

/**
* getEventsId: returns the name of Target Event.
*@param event -  Target Event
*/
char* eventGetName(Event event);

/**
* getFirstMemberID: returns the ID of the first member in Target event.
*@param event -  Target Event
*/
int eventGetFirstMemberID(Event event);

/**
*  insertNewMember: inserts a new member by ID in target event.
*@param event -  Target Event
*@param member_id - the ID of the member
*/
bool eventInsertNewMember(Event event,int member_id);

/**
* removeMemberByID: removes from the IDs list of target event ID of a member. 
*@param event -  Target Event
*@param member_id - the ID of the member
*/
bool removeMemberByID(Event event,int member_id);

/**
* removeAllMembers: remove all members from target event
*@param event -  Target Event
*/
void removeAllMembers(Event event);

/**
* eventGetDate: returns date of Target event.
*@param event -  Target Event
*/
Date eventGetDate(Event event);

#endif //EVENT_H_