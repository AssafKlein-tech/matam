#include "event.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "date.h"
struct Event_t
{
    Date *event_date;
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
    if (!event_name || !event_id || !date)
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
    event->event_date=date;
	return event;
}

void eventDestroy(Event event)
{  
    removeAllMembers(event);
      free(event);
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
    return (getEventsId(event1)==getEventsId(event2));
}

int eventGetId(Event event)
{
    if(!event)
        return NULL;
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
        return NULL;
    event->current_member=event->first_member;
    if (!event->first_member)
        return NULL;
    return event->first_member->member_id;
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
    if (member_id = event->current_member->next_member->member_id)
    {
        free(new_member);
        return EVENT_MEMBER_ID_ALREADY_EXISTS;
    }
    new_member->next_member = event->current_member->next_member;
    event->current_member->next_member = new_member;
    return EVENT_SUCCESS;
}

bool removeMemberByID(Event event,int member_id)
{
    if(!event || !member_id)
        return NULL;
    int id = eventGetFirstMemberID(event);
    if(!id)
        return false;
    if(id == member_id)
    {
        event->first_member = event->first_member->next_member;
        free(event->current_member);
        return true;
    }
    while (event->current_member->next_member)
    {
        id = event->current_member->next_member->member_id;
        if(!id)
            return false;
        if(id == member_id)
        {
            struct member* member_copy=event->current_member->next_member;
            event->current_member->next_member=event->current_member->next_member->next_member;
            free(member_copy);
            return true;
        }
       event->current_member=event->current_member->next_member;
    }
    return false;
}

void removeAllMembers(Event event)
{
    if(event)
    {
        while (event->first_member->next_member)
        {
        Member *member_to_delete=event->first_member;
            dateDestroy(event->event_date);
        event->first_member=event->first_member->next_member;
        free(member_to_delete);
        }
    }
}

Date eventGetDate(Event event)
{
    if(!event)
        return NULL;
    return event->event_date;
}