#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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



/*function that will be used by the EM*/

/**
 * @brief a copy element method for the pq - coping  event using "eventCopy"
 * 
 * @param event - the element
 * @return PQElement copied event
 */
static PQElement emEventCopy(PQElement event)
{
    return eventCopy((Event) event);
}

/**
 * @brief a free element method for the pq - free event using "eventDestroy"
 * 
 * @param event - the element to free
 */
static void emEventDestroy(PQElement event)
{
    if(event)
    eventDestroy((Event) event);
}

/**
 * @brief a equal element method for the pq - compares events using "eventCompare"
 * 
 * @param event1 - the first element
 * @param event2  - the second element
 * @return true if the events have the same ID
 * @return false otherwise
 */
static bool emEventCompare(PQElement event1,PQElement event2)
{
    return eventCompare((Event) event1 ,(Event) event2);
}

/**
 * @brief a copy elementPriority for the pq - copy the date using "dateCopy"
 * 
 * @param date - the elementPriority
 * @return PQElementPriority a new Date
 */
static PQElementPriority emDateCopy(PQElementPriority date)
{
    return dateCopy((Date) date);
}

/**
 * @brief a free elementPriority mothod for the pq - free the date using "dateDestroy"
 * 
 * @param date  - the elementPriority
 */
static void emDateDestroy(PQElementPriority date)
{
    dateDestroy((Date) date);
}

/**
 * @brief a copy elementPriority method for the pq - compare dates using "dateCompare"
 * 
 * @param date1 - The target date
 * @param date2 the date to compare to
 * @return int 
 *  positive if date2 is greater than date1
 *  0 if they are equal
 *  negetive if date1 is greater thasn date2
 */
static int emDateCompare(PQElementPriority date1, PQElementPriority date2)
{
    return dateCompare((Date) date2 ,(Date) date1);
}



/*helping static function*/

/**
 * @brief adding a member to the new list sorted
 * 
 * @param sorted_list the sorted list
 * @param new_member_node a node to add
 */
static void emAddMemberSorted(struct Members_list* sorted_list,struct Members_list* new_member_node)
{
    if (memberIsGreater(new_member_node->member, sorted_list->member))
    {
        new_member_node->next = sorted_list;
        sorted_list = new_member_node;
    }
    else
    {
        struct Members_list* current_node = sorted_list;
        while(current_node->next || !memberIsGreater(new_member_node->member, current_node->next->member))
        {
            current_node = current_node->next;
        }
        new_member_node->next = current_node->next;
        current_node->next = new_member_node;
    }
}

/**
 * @brief sorting the members of the event manager by the number of events
 * 
 * @param em Target event manager
 */
static void emSortMembers(EventManager em)
{
    if(em)
    {
        struct Members_list *ordered_member_list = NULL, *member_node;
        while (em->members)
        {
            member_node = em->members;
            em->members = em->members->next;
            emAddMemberSorted(ordered_member_list, member_node);
        }
        em->members = ordered_member_list;
    }
}

/**
 * @brief - Search for an event by it's ID.
 * 
 * @param em Target event manager
 * @param event_id target event's ID
 * @return - returns the event in case it was found and NULL otherwise.
 */
static Event emfindEventByID(EventManager em, int event_id)
{
    PQ_FOREACH(Event, event, em->events)
    {
        if(eventGetId(event) == event_id)
            return event;
    }
    return NULL;
}

/**
 * @brief - Search for an event in a specific date.
 * 
 * @param em Target event manager
 * @param event_name target event's name
 * @param date target date 
 * @return - returns the event in case it was found and NULL otherwise.
 */
static Event emfindEventByNameInSpecificDate(EventManager em,char* event_name, Date date)
{
    PQ_FOREACH(Event,event,em->events)
    {
        if(strcmp(eventGetName(event),event_name) == 0 && dateCompare(eventGetDate(event),date) == 0)
            return event;
    }
    return NULL;
}

/**
 * @brief find a member with the given id
 * 
 * @param em - Target event manager
 * @param member_id - the id of the member to find
 * @return Member the member wuth the given id
 *          if member not found return NULL
 */
static Member emFindMemberByID(EventManager em, int member_id)
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
    if (emFindMemberByID(em,member_id))
        return true;
    return false;
}

/**
 * @brief check if the arguments given are valid
 * 
 * @param em event manager argument
 * @param member_id member id argument
 * @param event_id event id argumnt
 * @return EventManagerResult 
 *          EM_NULL_ARGUMENT if one of the arguments is NULL;
 *          EM_INVALID_EVENT_ID if inserted invalid event_id;
 *          EM_INVALID_MEMBER_ID if inserted invalid member_id;
 *          EM_MEMBER_ID_NOT_EXISTS if there is no member with the id given in the event manger;
 *          EM_SUCCESS if the arguments fine;
 */
static EventManagerResult emCheckValidArguments(EventManager em, int member_id, int event_id)
{
    if(!em || !member_id || !event_id)
        return EM_NULL_ARGUMENT;
    if (event_id < 0)
        return EM_INVALID_EVENT_ID;
    if (member_id < 0)
        return EM_INVALID_MEMBER_ID;
    if(!emCheckMemberIDExist(em, member_id))
        return EM_MEMBER_ID_NOT_EXISTS;
    return EM_SUCCESS;
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
        if(emRemoveEvent(em, eventGetId(pqGetFirst(em->events))) != EM_SUCCESS)
            return EM_ERROR;
    }
    return EM_SUCCESS;
}

/**
 * @brief decreasing the number of events the member responsible for
 * 
 * @param em - Target event manager
 * @param member_id - the member id of the member to decrease
 */
static void emMemberEventDecrease(EventManager em, int member_id)
{
    Member member_to_decrease = emFindMemberByID(em, member_id);
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
    Member member_to_increase = emFindMemberByID(em, member_id);
    memberAddEvent(member_to_increase);
}


/*ADT methods*/

EventManager createEventManager(Date date)
{
    if (!date)
        return NULL;
    EventManager em = malloc(sizeof(*em));
    if (!em)
        return NULL;
    em->events = pqCreate(emEventCopy,emEventDestroy,emEventCompare,emDateCopy,emDateDestroy,emDateCompare);
    em->members = NULL;
    em->date = dateCopy(date);
    if (!em->events || !em->date)
    {
        pqDestroy(em->events);
        dateDestroy(em->date);
        free(em);
        return NULL;
    }
    return em;
}

void destroyEventManager(EventManager em)
{
    if (em)
    {
        pqDestroy(em->events);
        dateDestroy(em->date);
        struct Members_list* member_to_delete;
        while (em->members)
        {  
            member_to_delete = em->members;
            em->members=em->members->next;
            freeMember(member_to_delete->member);
            free(member_to_delete);
        }
        free(em);
    }
}

EventManagerResult emAddEventByDate(EventManager em, char* event_name, Date date, int event_id)
{

    if (!date || !em || !event_name )
        return EM_NULL_ARGUMENT;
    if(dateCompare(em->date, date) > 0)
        return EM_INVALID_DATE;
    if(event_id < 0)
        return EM_INVALID_EVENT_ID;
    if(emfindEventByNameInSpecificDate(em, event_name, date))
        return EM_EVENT_ALREADY_EXISTS;
    if(emfindEventByID(em, event_id))
        return EM_EVENT_ID_ALREADY_EXISTS;
    Event event = eventCreate(event_name, event_id, date);
    if(!event)
        return EM_OUT_OF_MEMORY;
    PriorityQueueResult result = pqInsert(em->events, event, date);
    if(result == PQ_OUT_OF_MEMORY)
    {
        eventDestroy(event);
        return EM_OUT_OF_MEMORY;
    }
    if(result == PQ_NULL_ARGUMENT)
    {
        eventDestroy(event);
        return EM_ERROR;
    }
    return EM_SUCCESS;
}

EventManagerResult emAddEventByDiff(EventManager em, char* event_name, int days, int event_id)
{
    Date date=dateCopy(em->date);
    if (!days||!em||!event_name||!event_id)
        return EM_NULL_ARGUMENT;
    if(days<0)
        return EM_INVALID_DATE;
    if(emfindEventByNameInSpecificDate(em,event_name,date))
    return EM_EVENT_ALREADY_EXISTS;
    if(emfindEventByID(em,event_id))
        return EM_EVENT_ID_ALREADY_EXISTS;
    for(int i=0; i<days; i++)
        dateTick(date);
    Event event= eventCreate(event_name,event_id,date);
    if(!event)
      return EM_OUT_OF_MEMORY;
    PriorityQueueResult result = pqInsert(em->events, event, date);
    if(result == PQ_OUT_OF_MEMORY)
        return EM_OUT_OF_MEMORY;
    if(result == PQ_NULL_ARGUMENT)
        return EM_ERROR;
     return EM_SUCCESS;
}

EventManagerResult emRemoveEvent(EventManager em, int event_id)
{
    if (!em||!event_id)
        return EM_NULL_ARGUMENT;
    if(event_id<0)
        return EM_INVALID_EVENT_ID;
    Event target_event = emfindEventByID(em,event_id);
    if(!target_event)
        return EM_EVENT_NOT_EXISTS;
    int member_id = eventGetFirstMemberID(target_event);
    while (member_id != INVALIDID) 
    {
        emRemoveMemberFromEvent(em,member_id,event_id);
        member_id=eventGetFirstMemberID(target_event);
    }
    pqRemoveElement(em->events,target_event);
    return EM_SUCCESS;
}

EventManagerResult emChangeEventDate(EventManager em, int event_id, Date new_date)
{
    if(!em || !event_id || !new_date)
        return EM_NULL_ARGUMENT;
    if(dateCompare(em->date,new_date) > 0)
        return EM_INVALID_DATE;
    Event target_event = emfindEventByID(em,event_id);
    if(!target_event)
        return EM_EVENT_ID_NOT_EXISTS;
    if(emfindEventByNameInSpecificDate(em,eventGetName(target_event),new_date))
        return EM_EVENT_ALREADY_EXISTS;
    Date old_date = eventGetDate(target_event);
    eventChangeDate(target_event, new_date);
    PriorityQueueResult result = pqChangePriority(em->events, target_event, old_date, new_date);
    if (result == PQ_OUT_OF_MEMORY)
        return EM_OUT_OF_MEMORY;
    return EM_SUCCESS;
}

EventManagerResult emAddMember(EventManager em, char* member_name, int member_id) 
{
    if(!em || !member_name || !member_id)
        return EM_NULL_ARGUMENT;
    if (member_id < 0)
        return EM_INVALID_MEMBER_ID;
    if (emCheckMemberIDExist(em, member_id))
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
    EventManagerResult em_result = emCheckValidArguments(em, member_id, event_id);
    if(em_result != EM_SUCCESS)
        return em_result;
    Event target_event = emfindEventByID(em, event_id);
    if (!target_event)
        return EM_EVENT_ID_NOT_EXISTS;
    EventResult  event_result = eventInsertNewMember(target_event,member_id);
    if (event_result == EVENT_OUT_OF_MEMORY)
        return EM_OUT_OF_MEMORY;
    if (event_result == EVENT_MEMBER_ID_ALREADY_EXISTS)
        return EM_EVENT_AND_MEMBER_ALREADY_LINKED;
    emMemberEventIncrease(em, member_id);
    return EM_SUCCESS;
}

EventManagerResult emRemoveMemberFromEvent(EventManager em, int member_id, int event_id)
{
    EventManagerResult em_result = emCheckValidArguments(em, member_id, event_id);
    if(em_result != EM_SUCCESS)
        return em_result;
    Event target_event = emfindEventByID(em, event_id);
    if (!target_event)
        return EM_EVENT_ID_NOT_EXISTS;
    EventResult  event_result = eventRemoveMemberByID(target_event,member_id); 
    if (event_result == EVENT_MEMBER_ID_NOT_EXISTS)
        return EM_EVENT_AND_MEMBER_NOT_LINKED;
    if (event_result == EVENT_ERROR)
        return EM_ERROR;
    emMemberEventDecrease(em,member_id);       
    return EM_SUCCESS;
}

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

char* emGetNextEvent(EventManager em)
{
    if(!em)
        return NULL;
    return eventGetName(pqGetFirst(em->events));
}

void emPrintAllEvents(EventManager em, const char* file_name)
{
    if (em && file_name)
    {
        FILE* output_file = fopen(file_name,"w");
        if (output_file)
        {
            PQ_FOREACH(Event,event,em->events)
            {
                eventPrintEventAndDate(event, output_file);
                EVENT_FOREACH_MEMBER(member_id,event)
                {
                    fprintf(output_file,",%s",memberGetName(emFindMemberByID(em, member_id)));
                }
                fprintf(output_file,"\n");
            }
            fclose (output_file);
        }
    }
}

void emPrintAllResponsibleMembers(EventManager em, const char* file_name)
{
    if(em && file_name)
    {
        FILE* output_file = fopen(file_name,"w");
        if (output_file)
        {
            emSortMembers(em);
            struct Members_list* member_iterator = em->members;
            while (member_iterator)
            {
                fprintf(output_file,"%s, %d\n", memberGetName(member_iterator->member), memberGetNumberOfEvents(member_iterator->member));
                member_iterator = member_iterator->next;
            }
            fclose(output_file);
        }       
    }
}
