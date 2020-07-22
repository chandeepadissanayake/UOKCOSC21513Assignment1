/*
 * Linked Implementation of Queues for char data type.
 * Deployed under klnstl.
 * 
 * Author: D. M. Chandeepa Dissanayake
 * Student Number: PS/2017/035
 * Assignment Number: 1
 * Course Code: COSC 12513
 */

#include "klncharqueue.h"
#include <stdlib.h>
#include <stdbool.h>

/*
 *  Implementation of KLNCharQueueCreateQueue function.
 *  Documented in klncharqueue.h
 */
void KLNCharQueueCreateQueue(KLNCharQueue *queue)
{
    queue->front = queue->rear = NULL;
    queue->size = 0;
    queue->is_full = false;
}

/*
 *  Implementation of KLNCharQueueIsEmpty function.
 *  Documented in klncharqueue.h
 */
bool KLNCharQueueIsEmpty(KLNCharQueue *queue)
{
    return queue->size == 0;
}

/*
 *  Implementation of KLNCharQueueIsFull function.
 *  Documented in klncharqueue.h
 */
bool KLNCharQueueIsFull(KLNCharQueue *queue)
{
    return queue->is_full;
}

/*
 *  Implementation of KLNCharQueueServe function.
 *  Documented in klncharqueue.h
 */
bool KLNCharQueueServe(KLNCharQueue *queue, char *element)
{
    if (KLNCharQueueIsEmpty(queue))
    {
        return false;
    }

    KLNCharQueueNode *node_front = queue->front;
    *element = node_front->value;

    queue->front = node_front->next;
    queue->size--;
    queue->is_full = false;

    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }

    free(node_front);

    return true;
}

/*
 *  Implementation of KLNCharQueueAppend function.
 *  Documented in klncharqueue.h
 */
bool KLNCharQueueAppend(KLNCharQueue *queue, char element)
{
    if (KLNCharQueueIsFull(queue))
    {
        return false;
    }

    KLNCharQueueNode *node_element = (KLNCharQueueNode *)malloc(sizeof(KLNCharQueueNode));
    if (node_element == NULL)
    {
        queue->is_full = true;
        return false;
    }

    node_element->value = element;
    node_element->next = NULL;

    // Adds to the end of the queue.
    if (KLNCharQueueIsEmpty(queue))
    {
        queue->front = queue->rear = node_element;
    }
    else
    {
        queue->rear->next = node_element;
        queue->rear = node_element;
    }

    queue->size++;

    return true;
}

/*
 *  Implementation of KLNCharQueueDestroy function.
 *  Documented in klncharqueue.h
 */
void KLNCharQueueDestroy(KLNCharQueue *queue)
{
    char buf;
    while (KLNCharQueueServe(queue, &buf))
        ;
}
