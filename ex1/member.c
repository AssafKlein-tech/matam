#include <stdbool.h>
#include <stdlib.h>
#include "member.h"


struct Member_t
{
    int member_id;
    char* name;
    int number_of_events;
};

Member memberCreate(char* name, int member_id)
{
    Member 
}

void memberAddEvent(Member member);

void memberRemoveEvent(Member member);

char* memberGetName(Member member);

int memberGetID(Member member);

int memberGetNumberOfEvents(Member member);

bool memberEqualIDs(Member member1,Member member2);

void freeMember(Member member);
