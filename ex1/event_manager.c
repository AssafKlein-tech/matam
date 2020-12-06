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
 * @brief checks if the member_id already in the members list
 * 
 * @param em the Target event_element
 * @param member_id the id to check if exist
 * @return true if there is a member with the same id
 * @return false otherwise
 */
static bool emCheckMemberIDExist(EventManager em, int member_id)
{
    struct Members_list *member_iterator = em->members;
    while (member_iterator)
    {
        if (memberGetID(member_iterator->member) == member_id)
            return true;
        member_iterator = member_iterator->next;
    }
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
 * @brief 
 * 
 * @param em 
 * @return EventManagerResult 
 */
static EventManagerResult emRemoveFirstEvent(EventManager em)
{
    if(!em)
        return EM_ERROR;
    
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

EventManagerResult emAddEventByDate(EventManager em, char* event_name, Date date, int event_id);

EventManagerResult emAddEventByDiff(EventManager em, char* event_name, int days, int event_id);

EventManagerResult emRemoveEvent(EventManager em, int event_id);

EventManagerResult emChangeEventDate(EventManager em, int event_id, Date new_date);

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

EventManagerResult emAddMemberToEvent(EventManager em, int member_id, int event_id);

EventManagerResult emRemoveMemberFromEvent (EventManager em, int member_id, int event_id);

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

int emGetEventsAmount(EventManager em);

char* emGetNextEvent(EventManager em);

void emPrintAllEvents(EventManager em, const char* file_name);

void emPrintAllResponsibleMembers(EventManager em, const char* file_name);
