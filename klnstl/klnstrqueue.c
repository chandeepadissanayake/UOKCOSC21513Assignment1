/*
 * Linked Implementation of Queues for strings.
 * Deployed under klnstl.
 * 
 * Author: D. M. Chandeepa Dissanayake
 * Student Number: PS/2017/035
 * Assignment Number: 1
 * Course Code: COSC 12513
 */

#include "klnstrqueue.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*
 *  Implementation of KLNStringQueueCreateQueue function.
 *  Documented in klnstrqueue.h
 */
void KLNStringQueueCreateQueue(KLNStringQueue *queue)
{
    queue->front = queue->rear = NULL;
    queue->size = 0;
    queue->is_full = false;
}

/*
 *  Implementation of KLNStringQueueIsEmpty function.
 *  Documented in klnstrqueue.h
 */
bool KLNStringQueueIsEmpty(KLNStringQueue *queue)
{
    return queue->size == 0;
}

/*
 *  Implementation of KLNStringQueueIsFull function.
 *  Documented in klnstrqueue.h
 */
bool KLNStringQueueIsFull(KLNStringQueue *queue)
{
    return queue->is_full;
}

/*
 *  Implementation of KLNStringQueueServe function.
 *  Documented in klnstrqueue.h
 */
bool KLNStringQueueServe(KLNStringQueue *queue, char **element)
{
    if (KLNStringQueueIsEmpty(queue))
    {
        return false;
    }

    KLNStringQueueNode *node_front = queue->front;
    strcpy(*element, node_front->value);

    // Frees the allocated memory for the value
    free(node_front->value);

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
 *  Implementation of KLNStringQueueAppend function.
 *  Documented in klnstrqueue.h
 */
bool KLNStringQueueAppend(KLNStringQueue *queue, char *element, int size)
{
    if (KLNStringQueueIsFull(queue))
    {
        return false;
    }

    KLNStringQueueNode *node_element = (KLNStringQueueNode *)malloc(sizeof(KLNStringQueueNode));
    if (node_element == NULL)
    {
        queue->is_full = true;
        return false;
    }

    // Allocates memory for the value element and assigns the value.
    char *ptr_element = (char *)malloc(sizeof(char) * size);
    strcpy(ptr_element, element);

    node_element->value = ptr_element;
    node_element->next = NULL;

    // Adds to the end of the queue.
    if (KLNStringQueueIsEmpty(queue))
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
 *  Implementation of KLNStringQueueDestroy function.
 *  Documented in klnstrqueue.h
 */
void KLNStringQueueDestroy(KLNStringQueue *queue, int size)
{
    char *buf = (char *)malloc(sizeof(char) * size);
    while (KLNStringQueueServe(queue, &buf))
        ;

    free(buf);
}
