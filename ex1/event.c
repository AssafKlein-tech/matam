#include "event.h"
#include <stdbool.h>
#include <stdlib.h>
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

Event eventCreate(char* event_name, int event_id, Date date){
Event event = malloc(sizeof(*event));
	if (!event) {
		return NULL;
	}
    event->event_name = malloc(strlen(event_name) + 1);
    if(!event->event_name)
        return NULL;
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
    return (getEventsId(event1)==getEventsId(event2));
}

int eventGetId(Event event)
{
    return event->event_id;
}

char* eventGetName(Event event)
{
    return event->event_name;
}

int getFirstMemberID(Event event)
{
    event->current_member=event->first_member;
    return event->first_member->member_id;
}

int getNextMemberID(Event event)
{
    if (!event->current_member)
        return NULL;
    if (!event->current_member->next_member)
        return NULL;
    event->current_member = event->current_member->next_member;
    return event->current_member->member_id;
}

void insertNewMember(Event event,int member_id)
{
    if (!event->current_member)
       { event->current_member=malloc(sizeof(event->current_member));
        if(!event->current_member)
            return NULL;

            event->current_member->member_id=member_id;
       }
    else event->current_member->next_member=malloc(sizeof(event->current_member->next_member));
    {
        if(!event->current_member->next_member)
            return NULL;
        event->current_member->next_member->member_id=member_id;
    }

}

bool removeMemberByID(Event event,int member_id)
{
    int id=getFirstMemberID(event);
    while (id != member_id)
    {
         id=event->current_member->next_member->member_id;
        if(id==NULL)
        return false;
        if(id==member_id)
        break;
       event->current_member=event->current_member->next_member;
    }
    Member *member_copy=event->current_member->next_member;
    dateDestroy(event->event_date);
    event->current_member->next_member=event->current_member->next_member->next_member;
    free(member_copy);
    return true;
}

void removeAllMembers(Event event)
{
    while (event->first_member->next_member)
    {
       Member *member_to_delete=event->first_member;
        dateDestroy(event->event_date);
       event->first_member=event->first_member->next_member;
       free(member_to_delete);
    }
}

Date eventGetDate(Event event)
{
    return event->event_date;
}