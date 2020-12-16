#ifndef EVENT_H_
#define EVENT_H_

#include <stdio.h>
#include <stdbool.h>
#include "date.h"
#define INVALIDID -1

/** Type for defining the event */
typedef struct Event_t *Event;

typedef enum EventResult_t {
    EVENT_SUCCESS,
    EVENT_OUT_OF_MEMORY,
    EVENT_NULL_ARGUMENT,
    EVENT_MEMBER_ID_ALREADY_EXISTS,
    EVENT_MEMBER_ID_NOT_EXISTS,
    EVENT_ERROR
} EventResult;

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
* getFirstMemberID: returns the ID of the first member in Target event. after this function the iterator will be linked to the first node
*@param event -  Target Event
*/
int eventGetFirstMemberID(Event event);

/**
 * @brief return the id of the next member
 * 
 * @param event - Target event
 * @return int the ID of the member
 */
int  eventGetNextMemberID(Event event);

/**
 * @brief enter a new member to the event. if the member already in the event, the function does nothing and return EVENT_MEMBER_ID_ALREADY_EXISTS
 * 
 * @param event Target event
 * @param member_id The Id of the new member
 * @return EventResult 
 *         EVENT_SUCCESS - the member added successfully
 *         EVENT_OUT_OF_MEMORY the allocation failed
 *         EVENT_NULL_ARGUMENT - one of the arguments given is NULL
 *         EVENT_MEMBER_ID_ALREADY_EXISTS there is already a member with the same id in the event
 */
EventResult eventInsertNewMember(Event event,int member_id);

/**
 * removeMemberByID: removes from the IDs list of target event ID of a member.
 * 
 * @param event -  Target Event
 * @param member_id - the ID of the member
 * @return EventResult 
 *         EVENT_SUCCESS The member removed successfully
 *         EVENT_OUT_OF_MEMORY the allocation failed
 *         EVENT_NULL_ARGUMENT - one of the arguments given is NULL
 *         EVENT_MEMBER_ID_NOT_EXISTS there isn't a member with the id in the event
 */
EventResult eventRemoveMemberByID(Event event,int member_id);

/**
* removeAllMembers: remove all members from target event
*@param event -  Target Event
*/
void eventRemoveAllMembers(Event event);

/**
* eventGetDate: returns date of Target event.
*@param event -  Target Event
*/
Date eventGetDate(Event event);

/**
 * @brief prints the the event to the given file
 * 
 * @param event The event to print
 * @param output_file The file to print to 
 */
void eventPrintEventAndDate(Event event, FILE* output_file);

#define EVENT_FOREACH_MEMBER(iterator, queue) \
    for(int iterator = eventGetFirstMemberID(queue) ; \
        iterator ;\
        iterator = eventGetNextMemberID(queue))
#endif //EVENT_H_