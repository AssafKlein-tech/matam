#ifndef MEMBER_H
#define MEMBER_H

#include <stdbool.h>

/** Type for defining the priority queue */
typedef struct Member_t *Member;

/**
 * @brief  memberCreate: create a new member instance
 * 
 * @param name - The name of the member
 * @param member_id - The id of the memeber
 * @return Member - a pointer to member object
 */
Member memberCreate(char* name, int member_id);

/**
 * @brief memberAddEvent: increasing the number of events the member responsible to
 * 
 * @param member - The member to add a event to.
 */
void memberAddEvent(Member member);

/**
 * @brief memberRemoveEvent: decreasing the number of events the member responsible to
 * 
 * @param member - The member to remove a event from.
 */
void memberRemoveEvent(Member member);

/**
 * @brief memberGetName: Get the name of the member
 * 
 * @param member - Taget member
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
 * @brief memberGetNumberOfEvents: Get the number of events the member responsible to
 * 
 * @param member - Target member
 * @return int  - The number of events
 */
int memberGetNumberOfEvents(Member member);

/**
 * @brief memberEqualIDs: Checks if the id's are equals 
 * 
 * @param member1 - First member
 * @param member2 - Second member
 * @return true - if the id's are equal 
 * @return false - otherwise
 */
bool memberEqualIDs(Member member1,Member member2);

/**
 * @brief freeMember - dealocating the instance
 * 
 * @param member - The member to dealocate
 */
void freeMember(Member member);

#endif /* MEMBER_H_ */