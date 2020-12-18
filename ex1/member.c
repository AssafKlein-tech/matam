#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "member.h"

#define NULL_ARGUMENT -1

struct Member_t
{
    int id;
    char* name;
    int number_of_events;
};

Member memberCreate(char* name, int member_id)
{
    if (!name)
        return NULL;  
    Member member = malloc(sizeof(*member));
    if(!member)
        return NULL;
    member->name = malloc (strlen(name) + 1);
    if(!member->name)
        return NULL;
    strcpy(member->name, name);
    member->id = member_id;
    member->number_of_events = 0;
    return member;
}

void memberAddEvent(Member member)
{
    if(member)
        member->number_of_events++;
}

void memberRemoveEvent(Member member)
{
    if(member)
        member->number_of_events--;
}

char* memberGetName(Member member)
{
    if(!member)
        return NULL;
    return member->name;
}

int memberGetID(Member member)
{
    if(!member)
        return NULL_ARGUMENT;
    return member->id;
}

int memberGetNumberOfEvents(Member member)
{
    if(!member)
        return NULL_ARGUMENT;
    return member->number_of_events;
}

bool memberIsGreater(Member member1, Member member2)
{
    if (member1->number_of_events == member2->number_of_events)
        return member1->id < member2->id;
    return member1->number_of_events > member2->number_of_events;
}

void freeMember(Member member)
{
    if(member)
    {
        free(member->name);
        free(member);
    }
}
