#include "priority_queue.h"
#include <stdbool.h>
#include <stdlib.h>

struct PriorityQueue_t
{
    struct Node_element_t
    {
        PQElementPriority priority;
        PQElement element;
        struct Node_element_t *next;
    } * first_node;
    struct Node_element_t *current_node;
    CopyPQElement copy_element;
    FreePQElement free_element;
    EqualPQElements equal_elements;
    CopyPQElementPriority copy_priority;
    FreePQElementPriority free_priority;
    ComparePQElementPriorities compare_priorities;
};

PriorityQueue pqCreate(CopyPQElement copy_element, FreePQElement free_element, EqualPQElements equal_elements, CopyPQElementPriority copy_priority, FreePQElementPriority free_priority, ComparePQElementPriorities compare_priorities)
{
    if (!copy_element || !free_element || !equal_elements || !copy_priority || !free_priority || !compare_priorities)
        return NULL;
    PriorityQueue priority_queue = malloc(sizeof(*priority_queue));
    if (!priority_queue)
        return NULL;
    priority_queue->copy_element = copy_element;
    priority_queue->free_element = free_element;
    priority_queue->equal_elements = equal_elements;
    priority_queue->copy_priority = copy_priority;
    priority_queue->free_priority = free_priority;
    priority_queue->compare_priorities = compare_priorities;
    priority_queue->current_node = NULL;
    priority_queue->first_node = NULL;
    return priority_queue;
}

void pqDestroy(PriorityQueue queue)
{
    if(queue)
    {
        pqClear(queue);
        free(queue);
    }
}

PriorityQueue pqCopy(PriorityQueue queue)
{
    if (!queue)
    {
        return NULL;
    }
    PriorityQueue new_queue = pqCreate(queue->copy_element, queue->free_element, queue->equal_elements, queue->copy_priority, queue->free_priority, queue->compare_priorities);
    if (!new_queue)
    {
        queue->current_node = NULL;
        return NULL;
    }
    PQElement element = pqGetFirst(queue);
    PQElementPriority priority = queue->current_node->priority;
    while (element)
    {
        if (pqInsert(new_queue, element, priority) != PQ_SUCCESS)
        {
            queue->free_priority(priority);
            queue->free_element(element);
            pqDestroy(new_queue);
            queue->current_node = NULL;
            return NULL;
        }
        element = pqGetNext(queue);
        priority = queue->current_node->priority;
    }
    queue->current_node = NULL;
    new_queue->current_node = NULL;
    return new_queue;
}

int pqGetSize(PriorityQueue queue)
{
    if (!queue)
        return -1;
    struct Node_element_t *copy_of_current_node = queue->current_node;
    if (!pqGetFirst(queue))
        return 0;
    int counter = 1;
    while (pqGetNext(queue))
        counter++;
    queue->current_node = copy_of_current_node;
    return counter;
}

bool pqContains(PriorityQueue queue, PQElement element)
{


    if(!queue||!element||queue->first_node==NULL)
        return NULL;
    struct Node_element_t *copy_of_current_node = queue->current_node;
    queue->current_node = queue->first_node;
    do
    {
        if (queue->equal_elements(element, queue->current_node->element))
        {
            queue->current_node = copy_of_current_node;
            return true;
        }
    } while (pqGetNext(queue));
    queue->current_node = copy_of_current_node;
    return false;
}

/**
* PqGetInsertionPlace: return a node pointer. the new node will be insert after this node
*
* @param queue - The priority queue for which to add the data element
* @param priority - The priority of the new element.
        the function find the place to enter the new node by the priority - the new node priority would be greater then all the next nodes in the queue
* @return
* 	a "struct Node_element_t*" node. the new node should be enter after this one
*/
static struct Node_element_t *pqGetInsertionPlace(PriorityQueue queue, PQElementPriority priority)
{
    queue->current_node = queue->first_node;
    if (!queue->current_node)
        return NULL;
    while (queue->current_node->next && queue->compare_priorities(priority, queue->current_node->next->priority) <= 0)
    {
        queue->current_node = queue->current_node->next;
    }
    return queue->current_node;
}

PriorityQueueResult pqInsert(PriorityQueue queue, PQElement element, PQElementPriority priority)
{
    if (!queue || !element || !priority)
    {
        queue->current_node = NULL;
        return PQ_NULL_ARGUMENT;
    }
    struct Node_element_t *new_node = malloc(sizeof(*new_node));
    if (!new_node)
    {
        queue->current_node = NULL;
        return PQ_OUT_OF_MEMORY;
    }

    new_node->element = queue->copy_element(element);
    new_node->priority = queue->copy_priority(priority);
    if (!queue->first_node)
    {
        queue->first_node = new_node;
        new_node->next = NULL;
    }
    else if (queue->compare_priorities(new_node->priority, queue->first_node->priority) > 0)
    {
        new_node->next = queue->first_node;
        queue->first_node = new_node;
    }
    else
    {
        queue->current_node = pqGetInsertionPlace(queue, priority);
        new_node->next = queue->current_node->next;
        queue->current_node->next = new_node;
    }
    queue->current_node = NULL;
    return PQ_SUCCESS;
}

/**
* pqGetHighestPriorityOfElement: find the first appearence of the element given in the queue
*
* @param queue - The priority queue to search in
* @param element - The eklement we search in the queue
        
* @return
* 	the priority of the element to remove
*/
static PQElementPriority pqGetHighestPriorityOfElement(PriorityQueue queue, PQElement element)
{
    queue->current_node = queue->first_node;
    while (queue->current_node)
    {
        if (queue->equal_elements(queue->current_node->element, element))
            return queue->current_node->priority;
        queue->current_node = queue->current_node->next;
    }
    return NULL;
}

/**
 * @brief pqRemoveElementWithPriority: removes the node with the element and priority given 
 * 
 * @param queue a PQ to remove the element from
 * @param element the element to remove
 * @param highest_priority the priority of the element to remove
 * @return PriorityQueueResult 
 * 	PQ_ELEMENT_DOES_NOT_EXISTS if given element does not exists.
 * 	PQ_SUCCESS the most prioritized element had been removed successfully.
 */
static PriorityQueueResult pqRemoveElementWithPriority(PriorityQueue queue, PQElementPriority element, PQElementPriority highest_priority)
{
    queue->current_node = queue->first_node;
    if (queue->compare_priorities(queue->current_node->priority, highest_priority) == 0 && queue->equal_elements(queue->current_node->element, element))
    {
        return pqRemove(queue);
    }
    while (queue->current_node->next)
    {
        if (queue->compare_priorities(queue->current_node->next->priority, highest_priority) == 0 && queue->equal_elements(queue->current_node->next->element, element))
        {
            struct Node_element_t * node_to_delete = queue->current_node->next;
            queue->free_element(node_to_delete->element);
            queue->free_priority(node_to_delete->priority); 
            queue->current_node->next  = node_to_delete->next;
            free(node_to_delete);
            queue->current_node = NULL;
            return PQ_SUCCESS;
        }
        queue->current_node = queue->current_node->next;
    }
    queue->current_node = NULL;
    return PQ_ELEMENT_DOES_NOT_EXISTS;
}


PriorityQueueResult pqChangePriority(PriorityQueue queue, PQElement element, PQElementPriority old_priority, PQElementPriority new_priority)
{
    if (!queue || !element || !old_priority || !new_priority)
        return PQ_NULL_ARGUMENT;
    PriorityQueueResult result = pqRemoveElementWithPriority(queue, element, old_priority);
    if (result == PQ_SUCCESS)
        return pqInsert(queue, element, new_priority);
    return result;
}

PriorityQueueResult pqRemove(PriorityQueue queue)
{
    if(!queue)
        return PQ_NULL_ARGUMENT;
    if(queue->first_node==NULL)
        return PQ_SUCCESS;
    queue->free_element(queue->first_node->element);
    queue->free_priority(queue->first_node->priority);
    queue->current_node = queue->first_node;
    queue->first_node  = queue->first_node->next;
    free(queue->current_node);
    queue->current_node = NULL;
    return PQ_SUCCESS;
}

PriorityQueueResult pqRemoveElement(PriorityQueue queue, PQElement element)
{
    if (!queue)
        return PQ_NULL_ARGUMENT;
    if (!element)
    {
        queue->current_node = NULL;
        return PQ_NULL_ARGUMENT;
    }
    PQElementPriority highest_priority = pqGetHighestPriorityOfElement(queue, element);
    if (!highest_priority)
    {
        queue->current_node = NULL;
        return PQ_ELEMENT_DOES_NOT_EXISTS;
    }
    return pqRemoveElementWithPriority(queue, element, highest_priority);
}

PQElement pqGetFirst(PriorityQueue queue)
{
    if (!queue || !queue->first_node)
    {
        return NULL;
    }
    queue->current_node = queue->first_node;
    return queue->first_node->element;
}

PQElement pqGetNext(PriorityQueue queue)
{
    if (!queue || !queue->current_node)
        return NULL;
    if (!queue->current_node->next)
        return NULL;
    queue->current_node = queue->current_node->next;
    return queue->current_node->element;
}

PriorityQueueResult pqClear(PriorityQueue queue)
{
    if(!queue)
        return PQ_NULL_ARGUMENT;
    while(queue->first_node)
    {
        pqRemove(queue);
    }
    return PQ_SUCCESS;
}
