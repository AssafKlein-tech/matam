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
    
    CopyPQElement copyElement;
    FreePQElement freeElement;
    EqualPQElements equalElements;
    CopyPQElementPriority copyPriority;
    FreePQElementPriority freePriority;
    ComparePQElementPriorities comparePriorities;


} ;


PriorityQueue pqCreate(CopyPQElement CopyFunction,FreePQElement FreeFunction,EqualPQElements EqualFunction,CopyPQElementPriority CopyPriorityFunction, FreePQElementPriority FreePriorityFunction,ComparePQElementPriorities comparePrioritiesFunction)
{
    if(!CopyFunction||!FreeFunction||!EqualFunction||!CopyPriorityFunction||!FreePriorityFunction||!comparePrioritiesFunction)
        return PQ_NULL_ARGUMENT;

    PriorityQueue priority_queue = malloc(sizeof(*priority_queue));
    if (!priority_queue)
		return NULL;

    priority_queue->copyElement=CopyFunction;
    priority_queue->freeElement=FreeFunction;
    priority_queue->equalElements=EqualFunction;
    priority_queue->copyPriority=CopyPriorityFunction;
    priority_queue->freePriority=FreePriorityFunction;
    priority_queue->comparePriorities=comparePrioritiesFunction;

    priority_queue->iterator = INVALID_STATE;
    priority_queue->node_element=malloc(sizeof(* priority_queue->node_element));
    priority_queue->current_node=malloc(sizeof(* priority_queue->node_element));
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
        element = pqGetNext(queue);
        priority = queue->current_node->priority;
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
bool pqContains(PriorityQueue queue, PQElement element);

/**
*   pqInsert: add a specified element with a specific priority.
*   Iterator's value is undefined after this operation.
*
* @param queue - The priority queue for which to add the data element
* @param element - The element which need to be added.
* @param priority - The new priority to associate with the given element.
*      A copy of the element will be inserted as supplied by the copying function
*      which is given at initialization.
* @return
* 	PQ_NULL_ARGUMENT if a NULL was sent as one of the parameters
* 	PQ_OUT_OF_MEMORY if an allocation failed (Meaning the function for copying
* 	an element failed)
* 	PQ_SUCCESS the paired elements had been inserted successfully
*/
PriorityQueueResult pqInsert(PriorityQueue queue, PQElement element, PQElementPriority priority);

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
PriorityQueueResult pqChangePriority(PriorityQueue queue, PQElement element,
                                     PQElementPriority old_priority, PQElementPriority new_priority);

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
PriorityQueueResult pqRemoveElement(PriorityQueue queue, PQElement element);


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

#endif /* PRIORITY_QUEUE_H_ *
