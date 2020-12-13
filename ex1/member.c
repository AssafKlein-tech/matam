#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "member.h"

struct Member_t
{
    int id;
    char* name;
    int number_of_events;
};

Member memberCreate(char* name, int member_id)
{
    if (!name || !member_id)
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

MemberResult memberAddEvent(Member member)
{
    if(!member)
        return MEMBER_NULL_ARGUMENT;
    member->number_of_events++;
    return MEMBER_SUCCESS;
}

MemberResult memberRemoveEvent(Member member)
{
    if(!member)
        return MEMBER_NULL_ARGUMENT;
    member->number_of_events--;
    return MEMBER_SUCCESS;
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
        return -1;
    return member->id;
}

int memberGetNumberOfEvents(Member member)
{
    if(!member)
        return NULL;
    return member->number_of_events;
}

bool memberIsGreater(Member member1, Member member2)
{
    return member1->number_of_events > member2->number_of_events;
}

bool memberEqualIDs(Member member1,Member member2)
{
    if(!member1 || !member2)
        return false;
    return member1->id == member2->id;
}

MemberResult freeMember(Member member)
{
    if(!member)
        return MEMBER_NULL_ARGUMENT;
    free(member->name);
    free(member);
    return MEMBER_SUCCESS;
}
