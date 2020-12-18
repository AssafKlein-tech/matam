#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H
#include "date.h"

typedef struct EventManager_t* EventManager;


typedef enum EventManagerResult_t {
    EM_SUCCESS,
    EM_OUT_OF_MEMORY,
    EM_NULL_ARGUMENT,
    EM_INVALID_DATE,
    EM_INVALID_EVENT_ID,
    EM_EVENT_ALREADY_EXISTS,
    EM_EVENT_ID_ALREADY_EXISTS,
    EM_EVENT_NOT_EXISTS,
    EM_EVENT_ID_NOT_EXISTS,
    EM_INVALID_MEMBER_ID,
    EM_MEMBER_ID_ALREADY_EXISTS,
    EM_MEMBER_ID_NOT_EXISTS,
    EM_EVENT_AND_MEMBER_ALREADY_LINKED,
    EM_EVENT_AND_MEMBER_NOT_LINKED,
    EM_ERROR
} EventManagerResult;

/**
 * @brief Creates an Event Manager 
 * 
 * @param date - the current date
 * @return EventManager pointer to the struct.
 *         return NULL if the date given is NULL or an error occurs.
 */
EventManager createEventManager(Date date);

/**
 * @brief Destroys an Event Manager
 * 
 * @param em - The target Event Manager 
 */
void destroyEventManager(EventManager em);

/**
 * @brief 
 * 
 * @param em - The target Event Manager
 * @param event_name - The event's name to add.
 * @param date - The event's date to add.
 * @param event_id - The event's ID to add.
 * @return  EventManagerResult: \n
 *          EM_NULL_ARGUMENT if one of the arguments is NULL;
 *          EM_INVALID_DATE - if the date is before the Event Manager's current date.
 *          EM_INVALID_EVENT_ID - if the date's ID is negative;
 *          EM_OUT_OF_MEMORY - if the llocation fails;
 *          EM_EVENT_ALREADY_EXISTS - if there is already an event with the same ID;
 *          EM_SUCCESS - The member has been added safely. 
 */
EventManagerResult emAddEventByDate(EventManager em, char* event_name, Date date, int event_id);

/**
 * @brief 
 * 
 * @param em - The target Event Manager
 * @param event_name - The event's name to add.
 * @param days - The number of days from the current date to add the event. 
 * @param event_id - The event's ID to add.
 * @return EventManagerResult: \n
 *          EM_NULL_ARGUMENT if one of the arguments is NULL;
 *          EM_INVALID_DATE - if the date is before the Event Manager's current date.
 *          EM_INVALID_EVENT_ID - if the event's ID is negative;
 *          EM_OUT_OF_MEMORY - if the llocation fails;
 *          EM_EVENT_ALREADY_EXISTS - if there is already an event with the same ID;
 *          EM_SUCCESS - The event has been added safely. 
 */
EventManagerResult emAddEventByDiff(EventManager em, char* event_name, int days, int event_id);

/**
 * @brief removes event from Event Manager
 * 
 * @param em  - The target Event Manager
 * @param event_id - The event's ID to remove.
 * @return EventManagerResult: \n
 *          EM_NULL_ARGUMENT if one of the arguments is NULL;
 *          EM_INVALID_EVENT_ID - if the event's ID is negative;
 *          EM_EVENT_ID_NOT_EXISTS - if the event's ID is not exists in the Event Manager.
 *          EM_OUT_OF_MEMORY - if the llocation fails; 
 *          EM_SUCCESS - The event has been removed safely. 
 */
EventManagerResult emRemoveEvent(EventManager em, int event_id);

/**
 * @brief changes event's date.
 * 
 * @param em  - The target Event Manager
 * @param event_id - The event's ID to change.
 * @param new_date - the new date of the event.
 * @return EventManagerResult: \n
 *          EM_NULL_ARGUMENT if one of the arguments is NULL;
 *          EM_INVALID_EVENT_ID - if the event's ID is negative;
 *          EM_EVENT_ID_NOT_EXISTS - if the event's ID is not exists in the Event Manager.
 *          EM_INVALID_DATE - if the date is before the Event Manager's current date.
 *          EM_EVENT_ALREADY_EXISTS - if an event named event_name already exists in the target date
 *          EM_OUT_OF_MEMORY - if the llocation fails; 
 *          EM_SUCCESS - The event has been removed safely. 
 */

EventManagerResult emChangeEventDate(EventManager em, int event_id, Date new_date);

/**
 * @brief Creates and adds a new member to the manger. the member have a name and an id.
 * 
 * @param em the em to add the member to
 * @param member_name the name of the member
 * @param member_id the ID of the member 
 * @return EventManagerResult: \n
 *          EM_NULL_ARGUMENT if one of the arguments is NULL;
 *          EM_INVALID_MEMBER_ID if the member ID is negative;
 *          EM_MEMBER_ID_ALREADY_EXISTS if there is already a member with the same ID;
 *          EM_OUT_OF_MEMORY - if the llocation fails;
 *          EM_SUCCESS - The member has been added safely.
 */
EventManagerResult emAddMember(EventManager em, char* member_name, int member_id);

/**
 * @brief  add a member to the event members. And increasing the number of events the member responsible of by 1.
 * 
 * @param em Target event manger
 * @param member_id - the Id of the member to add
 * @param event_id - the target event to add the member to/
 * @return EventManagerResult 
 *          EM_NULL_ARGUMENT if one of the arguments is NULL;
            EM_INVALID_EVENT_ID if inserted invalid event_id;
            EM_INVALID_MEMBER_ID if inserted invalid member_id;
            EM_EVENT_ID_NOT_EXISTS if there is no event with the id given in the event manger;
            EM_MEMBER_ID_NOT_EXISTS if there is no member with the id given in the event manger;
            EM_EVENT_AND_MEMBER_ALREADY_LINKED if the member is already responsible for the event;
            EM_OUT_OF_MEMORY if an allocation has failed;
 *          EM_SUCCESS if the action succeeded;
 */
EventManagerResult emAddMemberToEvent(EventManager em, int member_id, int event_id);

/**
 * @brief remove the member from the event members. And decreasing the number of events the member responsible of by 1.
 *
 * @param em Target event manager
 * @param member_id the id of the member to remove
 * @param event_id the id of the event to remove the member from
 * @return EventManagerResult 
 *          EM_NULL_ARGUMENT if one of the arguments is NULL;
 *          EM_INVALID_EVENT_ID if inserted invalid event_id;
 *          EM_INVALID_MEMBER_ID if inserted invalid member_id;
 *          EM_EVENT_ID_NOT_EXISTS if there is no event with the id given in the event manger;
 *          EM_MEMBER_ID_NOT_EXISTS if there is no member with the id given in the event manger;
 *          EM_EVENT_AND_MEMBER_NOT_LINKED if the member is not responsible for the event;
 *          EM_OUT_OF_MEMORY if an allocation has failed;
 *          EM_SUCCESS if the action succeeded;
 */
EventManagerResult emRemoveMemberFromEvent (EventManager em, int member_id, int event_id);

/**
 * @brief advance the time of the manger by 'days'
 * 
 * @param em Target eventManager
 * @param days - the number of day to advance
 * @return EventManagerResult: 
            EM_NULL_ARGUMENT if one of the arguments is NULL;
            EM_INVALID_DATE if the number of days given is not positive
            EM_OUT_OF_MEMORY if allocation has failed
 *          EM_SUCCESS if the action succeeded
 */
EventManagerResult emTick(EventManager em, int days);

/**
 * @brief returns number of events saved in the Manger
 * 
 * @param em Target eventManager
 * @return int number of events (-1 if the arrgument given is NULL)
 */
int emGetEventsAmount(EventManager em);

/**
 * @brief get the name of the next event
 * 
 * @param em - Target event manager
 * @return char*
 *          the name of the next event
 */
char* emGetNextEvent(EventManager em);

/**
 * @brief Prints all the event in the given file (file_name). 
 *        Every line will be printed an event. it will print its date and the members of the event
 * 
 * @param em Target event manager
 * @param file_name The file to print the events to
 */
void emPrintAllEvents(EventManager em, const char* file_name);

/**
 * @brief Prints all the members and amount of events they respinsible for in decreasing order.
 * 
 * @param em -Target event manager
 * @param file_name The file to print the events to
 */
void emPrintAllResponsibleMembers(EventManager em, const char* file_name);

#endif //EVENT_MANAGER_H
