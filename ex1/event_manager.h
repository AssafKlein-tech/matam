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
 * @brief Create a Event Manager 
 * 
 * @param date - the current date
 * @return EventManager pointer to the struct.
 *         return NULL if the date given is NULL or an error occurs.
 */
EventManager createEventManager(Date date);

/**
 * @brief 
 * 
 * @param em 
 */
void destroyEventManager(EventManager em);

/**
 * @brief 
 * 
 * @param em 
 * @param event_name 
 * @param date 
 * @param event_id 
 * @return EventManagerResult 
 */
EventManagerResult emAddEventByDate(EventManager em, char* event_name, Date date, int event_id);

/**
 * @brief 
 * 
 * @param em 
 * @param event_name 
 * @param days 
 * @param event_id 
 * @return EventManagerResult 
 */
EventManagerResult emAddEventByDiff(EventManager em, char* event_name, int days, int event_id);

/**
 * @brief 
 * 
 * @param em 
 * @param event_id 
 * @return EventManagerResult 
 */
EventManagerResult emRemoveEvent(EventManager em, int event_id);

/**
 * @brief 
 * 
 * @param em 
 * @param event_id 
 * @param new_date 
 * @return EventManagerResult 
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
 * @brief 
 * 
 * @param em 
 * @param member_id 
 * @param event_id 
 * @return EventManagerResult 
 */
EventManagerResult emAddMemberToEvent(EventManager em, int member_id, int event_id);

/**
 * @brief 
 * 
 * @param em 
 * @param member_id 
 * @param event_id 
 * @return EventManagerResult 
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
 * @brief 
 * 
 * @param em 
 * @return int 
 */
int emGetEventsAmount(EventManager em);

/**
 * @brief 
 * 
 * @param em 
 * @return char* 
 */
char* emGetNextEvent(EventManager em);

/**
 * @brief 
 * 
 * @param em 
 * @param file_name 
 */
void emPrintAllEvents(EventManager em, const char* file_name);

/**
 * @brief 
 * 
 * @param em 
 * @param file_name 
 */
void emPrintAllResponsibleMembers(EventManager em, const char* file_name);
#endif //EVENT_MANAGER_H
