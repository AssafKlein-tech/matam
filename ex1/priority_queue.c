#include "priority_queue.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define PQ_SUCCESS 1
#define PQ_OUT_OF_MEMORY 0
#define PQ_NULL_ARGUMENT 0
#define PQ_ELEMENT_DOES_NOT_EXISTS 0
#define PQ_ITEM_DOES_NOT_EXIST 0
#define PQ_ERROR 0
#define INVALID_STATE -1

struct PriorityQueue_t
{
    struct Node_element_t
    {
    PQElementPriority priority;
    PQElement element;
    struct Node_element_t* next;
    } *node_element;
    int iterator;
    struct Node_element_t* current_node;
    CopyPQElement copy_element;
    FreePQElement free_element;
    EqualPQElements equal_elements;
    CopyPQElementPriority copy_priority;
    FreePQElementPriority free_priority;
    ComparePQElementPriorities compare_priorities;
} ;

PriorityQueue pqCreate(CopyPQElement copy_element,FreePQElement free_element,EqualPQElements equal_elements, CopyPQElementPriority copy_priority, FreePQElementPriority free_priority,ComparePQElementPriorities compare_priorities)
{
    if(!copy_element||!free_element||!equal_elements||!copy_priority||!free_priority||!compare_priorities)
        return PQ_NULL_ARGUMENT;
    PriorityQueue priority_queue = malloc(sizeof(*priority_queue));
    if (!priority_queue)
		return NULL;
    priority_queue->copy_element=copy_element;
    priority_queue->free_element=free_element;
    priority_queue->equal_elements=equal_elements;
    priority_queue->copy_priority=copy_priority;
    priority_queue->free_priority=free_priority;
    priority_queue->compare_priorities=compare_priorities;
    priority_queue->iterator = INVALID_STATE;
    priority_queue->current_node=NULL;
    return  priority_queue;
}

/**
* pqDestroy: Deallocates an existing priority queue. Clears all elements by using the
* free functions.
*
* @param queue - Target priority queue to be deallocated. If priority queue is NULL nothing will be
* 		done
*/
void pqDestroy(PriorityQueue queue);

PriorityQueue pqCopy(PriorityQueue queue)
{
    if (!queue)
    {
        return PQ_NULL_ARGUMENT;
    }
    PriorityQueue new_queue = pqCreate(queue->copy_element,queue->free_element,queue->equal_elements, queue->copy_priority, queue->free_priority, queue->compare_priorities);
    if(!new_queue)
    {
        return PQ_NULL_ARGUMENT;
    }
    PQElement element = pqGetFirst(queue);
    PQElementPriority priority = PqGetPriority(queue);
    while (element)
    {
        if(pqInsert(new_queue, element, priority) != PQ_SUCCESS)
        {
            pqDestroy(new_queue);
            return PQ_NULL_ARGUMENT;
        }
        element = copyElement(pqGetNext(queue));
        priority = copyPriority(queue->current_node->priority);
    }
    return new_queue;
    /**
    int size = pqGetSize(queue);
    for(int i=1;i<=size;i++)
    {

    }**/
}   

int pqGetSize(PriorityQueue queue)
{
    if (!queue)
    {
        return -1;
    }
    if(!pqGetFirst(queue))
    {
        return 0;
    }
    while(pqGetNext(queue))
    {
        
    }
    return queue->iterator;
}

/**
* pqContains: Checks if an element exists in the priority queue. The element will be
* considered in the priority queue if one of the elements in the priority queue it determined equal
* using the comparison function used to initialize the priority queue.
*
* @param queue - The priority queue to search in
* @param element - The element to look for. Will be compared using the
* 		comparison function.
* @return
* 	false - if one or more of the inputs is null, or if the key element was not found.
* 	true - if the key element was found in the priority queue.
*/
bool pqContains(PriorityQueue queue, PQElement element)
{
    struct Node_element_t* copy_of_current_node=malloc(sizeof(*copy_of_current_node));
    copy_of_current_node=queue->current_node;
    do
    {
        if(equal_elements(element,queue->current_node->element))
        {
            queue->current_node=copy_of_current_node;
            return true;
        }
    } 
    while (pqGetNext);
    queue->current_node=copy_of_current_node;
    return false;
}

/**
*   PqGetInsertionPlace: return a node to enter the new node after.
*
* @param queue - The priority queue for which to add the data element
* @param priority - The priority of the new element.
        the function find the place to enter the new node by the priority - the new node priority would be greater then all the next nodes in the queue
* @return
* 	a "struct Node_element_t*" node. the new node should be enter after this one
*/
static struct Node_element_t* pqGetInsertionPlace(PriorityQueue queue,PQElementPriority priority)
{
    queue->current_node = queue->node_element;
    if(!queue->current_node)
        return NULL;
    while (queue->current_node->next && queue->compare_priorities(priority, queue->current_node->next->priority) <= 0)
    {
        queue->current_node = queue->current_node->next;
    }
    return queue->current_node;
}

PriorityQueueResult pqInsert(PriorityQueue queue, PQElement element, PQElementPriority priority)
{
    if(!queue || !element || !priority)
        return PQ_NULL_ARGUMENT;
    struct Node_element_t *new_node = malloc(sizeof(*new_node));
    if (!new_node)
        return PQ_OUT_OF_MEMORY;
    new_node->element = copyElement(element);
    new_node->priority = copyPriority(priority);
    if (!queue->node_element)
    {
        queue->node_element = new_node;
    }
    else if (queue->compare_priorities(new_node->priority, queue->node_element->priority)> 0)
    {
        new_node->next = queue->node_element;
        queue->node_element = new_node;
    }
    else
    {
        queue->current_node = PqGetInsertionPlace(queue,priority);
        new_node->next = queue->current_node->next;
        queue->current_node->next = new_node;
    }
    queue->iterator = INVALID_STATE;
    return PQ_SUCCESS;
}

static struct Node_element_t* pqFindElementWithPriority(PriorityQueue queue,PQElementPriority priority)
{
    struct Node_element_t* inner_iteration_node= queue->node_element;
    if(!inner_iteration_node)
        return NULL;
    while (queue->current_node->next && queue->compare_priorities(priority, queue->current_node->next->priority) <= 0)
    {
        queue->current_node = queue->current_node->next;
    }
    return queue->current_node;
}

static PriorityQueueResult pqRemoveElementWithPriority(PriorityQueue queue,PQElementPriority element,PQElementPriority highest_priority);

/**
*	pqChangePriority: Changes a priority of specific element with a specific priority in the priority queue.
*           If there are multiple same elements with same priority,
*           only the first element's priority needs to be changed.
*           Element that its value has changed is considered as reinserted element.
*			Iterator's value is undefined after this operation
*
* @param queue - The priority queue for which the element from.
* @param element - The element which need to be found and whos priority we want to change.
* @param old_priority - The old priority of the element which need to be changed.
* @param new_priority - The new priority of the element.
* @return
* 	PQ_NULL_ARGUMENT if a NULL was sent as one of the parameters
* 	PQ_OUT_OF_MEMORY if an allocation failed (Meaning the function for copying
* 	an element failed)
* 	PQ_ELEMENT_DOES_NOT_EXISTS if element with old_priority does not exists in the queue.
* 	PQ_SUCCESS the paired elements had been inserted successfully
*/
PriorityQueueResult pqChangePriority(PriorityQueue queue, PQElement element,PQElementPriority old_priority, PQElementPriority new_priority)
{
    if(!queue || !element || !old_priority || !new_priority)
        return PQ_NULL_ARGUMENT;    
    PriorityQueueResult result = pqRemoveElementWithPriority(queue, element, old_priority);
    if (result == PQ_SUCCESS)
        return pqInsert(queue,element,new_priority);
    return result;

}

/**
*   pqRemove: Removes the highest priority element from the priority queue.
*   If there are multiple elements with the same highest priority, the first inserted element should be removed first.
*   the elements are removed and deallocated using the free functions supplied at initialization.
*   Iterator's value is undefined after this operation.
*
* @param queue - The priority queue to remove the element from.
* @return
* 	PQ_NULL_ARGUMENT if a NULL was sent to the function.
* 	PQ_SUCCESS the most prioritized element had been removed successfully.
*/
PriorityQueueResult pqRemove(PriorityQueue queue);

/**
*   pqRemoveElement: Removes the highest priority element from the priority queue which have its value equal to element.
*   If there are multiple elements with the same highest priority, the first inserted element should be removed first.
*   the elements are removed and deallocated using the free functions supplied at initialization.
*   Iterator's value is undefined after this operation.
*
* @param queue - The priority queue to remove the elements from.
* @param element
* 	The element to find and remove from the priority queue. The element will be freed using the
* 	free function given at initialization. The priority associated with this element
*   will also be freed using the free function given at initialization.
* @return
* 	PQ_NULL_ARGUMENT if a NULL was sent to the function.
* 	PQ_ELEMENT_DOES_NOT_EXISTS if given element does not exists.
* 	PQ_SUCCESS the most prioritized element had been removed successfully.
*/
PriorityQueueResult pqRemoveElement(PriorityQueue queue, PQElement element)
{
    /**I need the same function like that one but recives also a priority and remove by both ( and not the highst priority) for the changePriority function
    So i thought the function should be implement like this**/
    PQElementPriority highest_priority = pqGetHighestPriorityOfElement(queue, element); // לא ממשתי
    return pqRemoveElementWithPriority(queue, element, highest_priority); // לא ממשתי
    // צריכים לעשות גם בדיקות של המשתנים
}


PQElement pqGetFirst(PriorityQueue queue)
{
    if(!queue || !queue->node_element)
    {
        return PQ_NULL_ARGUMENT;
    }
    queue->iterator = 1;
    queue->current_node = queue->node_element;
    return queue->node_element->element;
}

PQElement pqGetNext(PriorityQueue queue)
{
    if(!queue || queue->iterator == INVALID_STATE)
    {
        return PQ_NULL_ARGUMENT;
    }
    if (!queue->current_node->next)
    {
        return NULL;
    }
    queue->current_node = queue->current_node->next;
    queue->iterator++;
    return queue->current_node->element;
}

/**
* pqClear: Removes all elements and priorities from target priority queue.
* The elements are deallocated using the stored free functions.
* @param queue
* 	Target priority queue to remove all element from.
* @return
* 	MAP_NULL_ARGUMENT - if a NULL pointer was sent.
* 	MAP_SUCCESS - Otherwise.
*/
PriorityQueueResult pqClear(PriorityQueue queue);

/*!
* Macro for iterating over a priority queue.
* Declares a new iterator for the loop.
*/
#define PQ_FOREACH(type, iterator, queue) \
    for(type iterator = (type) pqGetFirst(queue) ; \
        iterator ;\
        iterator = pqGetNext(queue))
