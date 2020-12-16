#include "event.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "date.h"
struct Event_t
{
    Date event_date;
    char* event_name;
    int event_id;
    struct member {
	int member_id;
	struct member* next_member ;
    } *first_member;
    struct member *current_member;
};

Event eventCreate(char* event_name, int event_id, Date date)
{
    if (!event_name || !date)
        return NULL;
    Event event = malloc(sizeof(*event));
	if (!event) 
		return NULL;
    event->event_name = malloc(strlen(event_name) + 1);
    if(!event->event_name)
    {
        free(event);
        return NULL;
    }
    strcpy(event->event_name, event_name);
	event->event_id = event_id;
    event->event_date = dateCopy(date);
	return event;
}

void eventDestroy(Event event)
{  
    if(event){
    eventRemoveAllMembers(event);
    free(event);
    }
}

Event eventCopy(Event event)
{
     if (!event)
        return NULL;
    return eventCreate(event->event_name,event->event_id,event->event_date);
}

bool eventCompare(Event event1, Event event2)
{
    if(!event1 || !event2)
        return false;
    return (event1->event_id == event2->event_id);
}

int eventGetId(Event event)
{
    if(!event)
        return INVALIDID;
    return event->event_id;
}

char* eventGetName(Event event)
{
    if(!event)
        return NULL;
    return event->event_name;
}

int eventGetFirstMemberID(Event event)
{
    if(!event)
        return INVALIDID;
    event->current_member=event->first_member;
    if (!event->first_member)
        return INVALIDID;
    return event->first_member->member_id;
}

int  eventGetNextMemberID(Event event)
{
    if(!event)
        return INVALIDID;
    event->current_member = event->current_member->next_member;
    if (!event->current_member)
        return INVALIDID;
    return event->current_member->member_id;
}

EventResult eventInsertNewMember(Event event,int member_id)
{
    if(!event || !member_id)
        return EVENT_NULL_ARGUMENT;
    struct member* new_member = malloc(sizeof(new_member));
    if(!new_member)
        return EVENT_OUT_OF_MEMORY;
    new_member->member_id = member_id;
    if (!event->first_member)
    {
        event->first_member=new_member;
        return EVENT_SUCCESS;
    }
    if(member_id < event->first_member->member_id)
    {
        new_member->next_member = event->first_member;
        event->first_member->next_member = new_member;
        return EVENT_SUCCESS;
    }
    event->current_member = event->first_member;
    while(event->current_member->next_member && member_id > event->current_member->next_member->member_id)
    {
        event->current_member = event->current_member->next_member;
    }
    if (!event->current_member->next_member)
    {
        event->current_member->next_member = new_member;
        return EVENT_SUCCESS;
    }
    if (member_id == event->current_member->next_member->member_id)
    {
        free(new_member);
        return EVENT_MEMBER_ID_ALREADY_EXISTS;
    }
    new_member->next_member = event->current_member->next_member;
    event->current_member->next_member = new_member;
    return EVENT_SUCCESS;
}

EventResult eventRemoveMemberByID(Event event,int member_id)
{
    if(!event || !member_id)
        return EVENT_NULL_ARGUMENT;
    int id = eventGetFirstMemberID(event);
    if(!id)
        return EVENT_MEMBER_ID_NOT_EXISTS;
    if(id == member_id)
    {
        event->first_member = event->first_member->next_member;
        free(event->current_member);
        return EVENT_SUCCESS;
    }
    while (event->current_member->next_member)
    {
        id = event->current_member->next_member->member_id;
        if(!id)
            return EVENT_ERROR;
        if(id == member_id)
        {
            struct member* member_copy=event->current_member->next_member;
            event->current_member->next_member=event->current_member->next_member->next_member;
            free(member_copy);
            return EVENT_SUCCESS;
        }
       event->current_member=event->current_member->next_member;
    }
    return EVENT_MEMBER_ID_NOT_EXISTS;
}

void eventRemoveAllMembers(Event event)
{
    if(event)
    {
        if(event->first_member)
        {
            while (event->first_member)
            {
                struct member *member_to_delete=event->first_member;
                event->first_member=event->first_member->next_member;
                free(member_to_delete);
            }
        }
    }
}

Date eventGetDate(Event event)
{
    if(!event)
        return NULL;
    return event->event_date;
}

void eventPrintEventAndDate(Event event,FILE* output_file)
{
    if(event && output_file)
    {
        int *day = NULL, *month = NULL, *year = NULL;
        if (dateGet(event->event_date, day, month, year))
        {
            fprintf(output_file,"%s, %d.%d.%d", event->event_name,*day,*month,*year);
        }
    }
}

void eventChangeDate(Event event,Date new_date)
{
    if (event && new_date)
        event->event_date = dateCopy(new_date);
}