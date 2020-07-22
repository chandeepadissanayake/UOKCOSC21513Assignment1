/*
 * Linked Implementation of Queues for char data type.
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
typedef struct KLNCharQueueNode
{
    char value;
    struct KLNCharQueueNode *next;
} KLNCharQueueNode;

// Struct for Queue
typedef struct KLNCharQueue
{
    KLNCharQueueNode *front;
    KLNCharQueueNode *rear;
    int size;
    bool is_full;
} KLNCharQueue;

/*
 * Function:  KLNCharQueueCreateQueue
 * ----------------------------------
 *  Create and initializes the queue.
 *  Corresponds to CreateQueue operation in queue specification.
 * 
 *  queue: Pointer to a declared KLNCharQueue type variable.
 * 
 *  Returns: Nothing
 * 
 */
void KLNCharQueueCreateQueue(KLNCharQueue *queue);

/*
 * Function:  KLNCharQueueIsEmpty
 * ------------------------------
 *  Checks whether the given queue is empty or not.
 *  Corresponds to IsQueueEmpty operation in queue specification.
 * 
 *  queue: Pointer to a declared KLNCharQueue type variable.
 * 
 *  Returns: bool (True if queue is empty, false otherwise)
 * 
 */
bool KLNCharQueueIsEmpty(KLNCharQueue *queue);

/*
 * Function:  KLNCharQueueIsFull
 * -----------------------------
 *  Checks whether the given queue is full or not.
 *  Corresponds to IsQueueFull operation in queue specification.
 * 
 *  queue: Pointer to a declared KLNCharQueue type variable.
 * 
 *  Returns: bool (True if queue is full, false otherwise)
 * 
 */
bool KLNCharQueueIsFull(KLNCharQueue *queue);

/*
 * Function:  KLNCharQueueServe
 * ----------------------------
 *  Points the element (char) at the front of the queue to the given parameter.
 *  Note: This REMOVES the front element from the queue.
 *  Corresponds to Serve/Remove operation in queue specification.
 * 
 *  queue: Pointer to a declared KLNCharQueue type variable.
 *  element: Pointer to the variable that the front element should be set.
 * 
 *  Returns: bool (True if the queue is not empty, false otherwise)
 * 
 */
bool KLNCharQueueServe(KLNCharQueue *queue, char *element);

/*
 * Function:  KLNCharQueueAppend
 * ---------------------------
 *  Appends/Inserts an element on to the end of the queue (rear).
 *  Note: This makes the appended element the new 'rear' of the queue.
 *  Corresponds to Append/Insert operation in queue specification.
 * 
 *  queue: Pointer to a declared KLNCharQueue type variable.
 *  element: The variable with the value that should be appended on to the queue.
 * 
 *  Returns: bool (True if the queue is not full, false otherwise)
 * 
 */
bool KLNCharQueueAppend(KLNCharQueue *queue, char element);

/*
 * Function:  KLNCharQueueDestroy
 * ------------------------------
 *  Deletes the given queue from memory, releasing all of the memory allocated.
 *  Note: The queue wont be usable after invoking this function.
 *  Corresponds to DestroyQueue operation in queue specification.
 * 
 *  queue: Pointer to a declared KLNCharQueue type variable.
 * 
 */
void KLNCharQueueDestroy(KLNCharQueue *queue);
