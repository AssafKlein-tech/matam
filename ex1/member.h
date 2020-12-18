#ifndef MEMBER_H
#define MEMBER_H

#include <stdbool.h>

/** Type for defining the member */
typedef struct Member_t *Member;

/**
 * @brief  memberCreate: Allocating a new member. 
 * 
 * @param name - The name of the member
 * @param member_id - The id of the member
 * @return Member - a pointer to member object
 */
Member memberCreate(char* name, int member_id);

/**
 * @brief memberAddEvent: increasing the number of events the member responsible for
 * 
 * @param member - The member to add a event to.
 */
void memberAddEvent(Member member);

/**
 * @brief memberRemoveEvent: decreasing the number of events the member responsible for
 * 
 * @param member - The member to remove a event from.
 */
void memberRemoveEvent(Member member);

/**
 * @brief memberGetName: Get the name of the member
 * 
 * @param member - Target member
 * @return char* - The name of the member
 */
char* memberGetName(Member member);

/**
 * @brief memberGetID: Get the the ID of the member
 * 
 * @param member - Target member 
 * @return int - The ID of the member
 */
int memberGetID(Member member);

/**
 * @brief memberGetNumberOfEvents: Get the number of events the member responsible for
 * 
 * @param member - Target member
 * @return int  - The number of events
 */
int memberGetNumberOfEvents(Member member);

/**
 * @brief returns true if member1 is greater than member2.
 * 
 * @param member1 a member
 * @param member2 member to compare
 * @return true member1 has more events than member2. if number of events 
 *              equal return true if the id of member1 is lower.
 * @return false otherwise
 */
bool memberIsGreater(Member member1, Member member2);

/**
 * @brief freeMember - Deallocating the member.
 * 
 * @param member - The member to dealocate
 */
void freeMember(Member member);

#endif /* MEMBER_H_ */