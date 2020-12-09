#include <stdbool.h>
#include <stdlib.h>
#include "event_manager.h"
#include "date.h"
#include "priority_queue.h"
#include "member.h"
#include "event.h"

struct EventManager_t
{
    PriorityQueue events;
    struct Members_list
    {
        Member member;
        struct Members_list *next;
    } *members;
    Date date;  
};

/**
 * @brief Construct a new Date Compare object
 * 
 * @param date1 - The target date
 * @param date2 the date to compare to
 */
static newDateCompare(Date date1, Date date2)
{
    return dateCompare(date2 ,date1);
}

/**
 * @brief find a member with the given id
 * 
 * @param em - Target event manager
 * @param member_id - the id of the member to find
 * @return Member the member wuth the given id
 *          if member not found return NULL
 */
static Member emFindMemberById(EventManager em, int member_id)
{
    struct Members_list *member_iterator = em->members;
    while (member_iterator)
    {
        if (memberGetID(member_iterator->member) == member_id)
            return member_iterator->member;
        member_iterator = member_iterator->next;
    }
    return NULL;
}

/**
 * @brief checks if the member_id already in the members list
 * 
 * @param em the Target event_element
 * @param member_id the id to check if exist
 * @return true if there is a member with the same id
 * @return false otherwise
 */
static bool emCheckMemberIDExist(EventManager em, int member_id)
{
    if (emFindMemberById(em,member_id))
        return true;
    return false;
}

/**
 * @brief Removes all the events that are earlier then the current date
 * 
 * @param em Target eventManager
 * @return EventManagerResult
 *         EM_SUCCESS if the action succeeded
 *         EM_ERROR if any error occurs 
 */
static EventManagerResult emRemoveEarlyEvents(EventManager em)
{
    if(!em)
        return EM_ERROR;
    while(dateCompare(em->date, eventGetDate(pqGetFirst(em->events))) > 0)
    {
        if(emRemoveFirstEvent(em) == EM_ERROR)
            return EM_ERROR;
    }
    return EM_SUCCESS;
}

/**
 * @brief Dellocate and remove the first event. Decreasing number of events of the members of the first event
 * 
 * @param em - Target eventManager
 * @return EventManagerResult 
 *          EM_ERROR for any ERROR
 *          EM_SUCCESS if the action succeeded 
 */
static EventManagerResult emRemoveFirstEvent(EventManager em)
{
    if(!em)
        return EM_ERROR;
    
}

/**
 * @brief decreasing the number of events the member responsible for
 * 
 * @param em - Target event manager
 * @param member_id - the member id of the member to decrease
 */
static void emMemberEventDecrease(EventManager em, int member_id)
{
    Member member_to_decrease = emFindMemberById(em, member_id);
    memberRemoveEvent(member_to_decrease);
}

/**
 * @brief increasing the number of events the member responsible for
 * 
 * @param em - Target event manager
 * @param member_id - the member id of the member to increase
 */
static void emMemberEventIncrease(EventManager em, int member_id)
{
    Member member_to_increase = emFindMemberById(em, member_id);
    memberAddEvent(member_to_increase);
}

EventManager createEventManager(Date date)
{
    if (!date)
        return NULL;
    EventManager em = malloc(sizeof(*em));
    if (!em)
        return NULL;
    em->events = pqCreate(eventCopy,eventDestroy,eventCompare,dateCopy,dateDestroy,newDateCompare);
    em->members = NULL;
    em->date = dateCopy(date);
    if (!em->events || !em->date)
        return NULL;
    return em;
}

void destroyEventManager(EventManager em);

EventManagerResult emAddEventByDate(EventManager em, char* event_name, Date date, int event_id)
{
    if (!date)
        return NULL;
    if (!em)
        return NULL;
    Event event= eventCreate(event_name,event_id);
    if(!event)
    return NULL;
    em->events=pqInsert(em,event,date);
}

EventManagerResult emAddEventByDiff(EventManager em, char* event_name, int days, int event_id)
{
    if (!em)
        return NULL;
    Event event= eventCreate(event_name,event_id);
    if(!event)
        return NULL;
    Date date=dateCopy(em->date);
    for(int i=0; i<days; i++)
        dateTick(date);
        em->events=pqInsert(em,event,date);
}

EventManagerResult emRemoveEvent(EventManager em, int event_id);

EventManagerResult emChangeEventDate(EventManager em, int event_id, Date new_date)
{
    
    pqChangePriority(em,


}

static Event emfindEventByID(EventManager em, int event_id)
{
    event
    PQ_FOREACH(Event,event)


}

EventManagerResult emAddMember(EventManager em, char* member_name, int member_id) //האם צריך לשחרר זכרון במקרה של שגיאה?
{
    if(!em || !member_name || !member_id)
        return EM_NULL_ARGUMENT;
    if (member_id < 0)
        return EM_INVALID_MEMBER_ID;
    if (emCheckMemberIDExist(member_id))
        return EM_MEMBER_ID_ALREADY_EXISTS;
    struct Members_list *new_member = malloc(sizeof(*new_member));
    if(!new_member)
        return EM_OUT_OF_MEMORY;
    new_member->member = memberCreate(member_name, member_id);
    if(!new_member->member)
        return EM_OUT_OF_MEMORY;
    new_member->next = em->members;
    em->members = new_member;
    return EM_SUCCESS;
}

EventManagerResult emAddMemberToEvent(EventManager em, int member_id, int event_id)
{
    if(!em || !member_id || !event_id)
        return EM_NULL_ARGUMENT;
    if (event_id < 0)
        return EM_INVALID_EVENT_ID;
    if (member_id < 0)
        return EM_INVALID_MEMBER_ID;
    if(!emCheckMemberIDExist(member_id))
        return EM_MEMBER_ID_NOT_EXISTS;
    Event target_event = emFindEventById(em, event_id);
    if (!target_event)
        return EM_EVENT_ID_NOT_EXISTS;
    EventResult  result = eventInsertNewMember(target_event,member_id);
    if (result == EVENT_OUT_OF_MEMORY)
        return EM_OUT_OF_MEMORY;
    if (result == EVENT_MEMBER_ID_ALREADY_EXISTS)
        return EM_EVENT_AND_MEMBER_ALREADY_LINKED;
    emMemberEventIncrease(em, member_id);
    return EM_SUCCESS;
}

EventManagerResult emRemoveMemberFromEvent(EventManager em, int member_id, int event_id);

EventManagerResult emTick(EventManager em, int days)
{
    if(!em || days)
        return EM_NULL_ARGUMENT;
    if(days <= 0)
        return EM_INVALID_DATE;
    for(int i = 1; i <= days; i++)
    {
        dateTick(em->date);
    }
    return emRemoveEarlyEvents(em);
}

int emGetEventsAmount(EventManager em)
{
    if(!em)
        return -1;
    return pqGetSize(em->events);
}

char* emGetNextEvent(EventManager em);

void emPrintAllEvents(EventManager em, const char* file_name);

void emPrintAllResponsibleMembers(EventManager em, const char* file_name);
