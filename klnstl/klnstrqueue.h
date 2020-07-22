/*
 * Linked Implementation of Queues for strings.
 * Deployed under klnstl.
 * 
 * Author: D. M. Chandeepa Dissanayake
 * Student Number: PS/2017/035
 * Assignment Number: 1
 * Course Code: COSC 12513
 */

#pragma once

#include <stdbool.h>

// Struct for Queue Node
typedef struct KLNStringQueueNode
{
    char *value;
    struct KLNStringQueueNode *next;
} KLNStringQueueNode;

// Struct for Queue
typedef struct KLNStringQueue
{
    KLNStringQueueNode *front;
    KLNStringQueueNode *rear;
    int size;
    bool is_full;
} KLNStringQueue;

/*
 * Function:  KLNStringQueueCreateQueue
 * ----------------------------------
 *  Create and initializes the queue.
 *  Corresponds to CreateQueue operation in queue specification.
 * 
 *  queue: Pointer to a declared KLNStringQueue type variable.
 * 
 *  Returns: Nothing
 * 
 */
void KLNStringQueueCreateQueue(KLNStringQueue *queue);

/*
 * Function:  KLNStringQueueIsEmpty
 * ------------------------------
 *  Checks whether the given queue is empty or not.
 *  Corresponds to IsQueueEmpty operation in queue specification.
 * 
 *  queue: Pointer to a declared KLNStringQueue type variable.
 * 
 *  Returns: bool (True if queue is empty, false otherwise)
 * 
 */
bool KLNStringQueueIsEmpty(KLNStringQueue *queue);

/*
 * Function:  KLNStringQueueIsFull
 * -----------------------------
 *  Checks whether the given queue is full or not.
 *  Corresponds to IsQueueFull operation in queue specification.
 * 
 *  queue: Pointer to a declared KLNStringQueue type variable.
 * 
 *  Returns: bool (True if queue is full, false otherwise)
 * 
 */
bool KLNStringQueueIsFull(KLNStringQueue *queue);

/*
 * Function:  KLNStringQueueServe
 * ----------------------------
 *  Points the element (string) at the front of the queue to the given parameter.
 *  Note: This REMOVES the front element from the queue.
 *  Corresponds to Serve/Remove operation in queue specification.
 * 
 *  queue: Pointer to a declared KLNStringQueue type variable.
 *  element: Pointer to the variable that the front element should be set.
 * 
 *  Returns: bool (True if the queue is not empty, false otherwise)
 * 
 */
bool KLNStringQueueServe(KLNStringQueue *queue, char **element);

/*
 * Function:  KLNStringQueueAppend
 * ---------------------------
 *  Appends/Inserts an element on to the end of the queue (rear).
 *  Note: This makes the appended element the new 'rear' of the queue.
 *  Corresponds to Append/Insert operation in queue specification.
 * 
 *  queue: Pointer to a declared KLNStringQueue type variable.
 *  element: The variable with the value that should be appended on to the queue.
 *  size : Size of the string in parameter 'element'.
 * 
 *  Returns: bool (True if the queue is not full, false otherwise)
 * 
 */
bool KLNStringQueueAppend(KLNStringQueue *queue, char *element, int size);

/*
 * Function:  KLNStringQueueDestroy
 * ------------------------------
 *  Deletes the given queue from memory, releasing all of the memory allocated.
 *  Note: The queue wont be usable after invoking this function.
 *  Corresponds to DestroyQueue operation in queue specification.
 * 
 *  queue: Pointer to a declared KLNStringQueue type variable.
 *  size : Maximum size of a value of an element in the queue.
 * 
 */
void KLNStringQueueDestroy(KLNStringQueue *queue, int size);
