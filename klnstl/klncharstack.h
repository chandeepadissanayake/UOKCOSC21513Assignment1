/*
 * Linked Implementation of Stacks for char data type.
 * Deployed under klnstl.
 * 
 * Author: D. M. Chandeepa Dissanayake
 * Student Number: PS/2017/035
 * Assignment Number: 1
 * Course Code: COSC 12513
 */

#pragma once

#include <stdbool.h>

// Struct for a Stack Node
typedef struct KLNCharStackNode
{
    char value;
    struct KLNCharStackNode *next;
} KLNCharStackNode;

// Struct for Stack
typedef struct KLNCharStack
{
    KLNCharStackNode *top;
    int size;
    bool is_full;
} KLNCharStack;

/*
 * Function:  KLNCharStackCreateStack
 * ----------------------------------
 *  Create and initializes the stack.
 *  Corresponds to CreateStack operation in stack specification.
 * 
 *  stack: Pointer to a declared KLNCharStack type variable.
 * 
 *  Returns: Nothing
 * 
 */
void KLNCharStackCreateStack(KLNCharStack *stack);

/*
 * Function:  KLNCharStackIsEmpty
 * ------------------------------
 *  Checks whether the given stack is empty or not.
 *  Corresponds to IsStackEmpty operation in stack specification.
 * 
 *  stack: Pointer to a declared KLNCharStack type variable.
 * 
 *  Returns: bool (True if stack is empty, false otherwise)
 * 
 */
bool KLNCharStackIsEmpty(KLNCharStack *stack);

/*
 * Function:  KLNCharStackIsFull
 * -----------------------------
 *  Checks whether the given stack is full or not.
 *  Corresponds to IsStackFull operation in stack specification.
 * 
 *  stack: Pointer to a declared KLNCharStack type variable.
 * 
 *  Returns: bool (True if stack is full, false otherwise)
 * 
 */
bool KLNCharStackIsFull(KLNCharStack *stack);

/*
 * Function:  KLNCharStackTop
 * --------------------------
 *  Points the element (char) at the top of the stack to the given parameter.
 *  Note: This DOES NOT REMOVE the top element from the stack.
 *  Corresponds to Top operation in stack specification.
 * 
 *  stack: Pointer to a declared KLNCharStack type variable.
 *  element: Pointer to the variable that the top element should be set.
 * 
 *  Returns: bool (True if the stack is not empty, false otherwise)
 * 
 */
bool KLNCharStackTop(KLNCharStack *stack, char *element);

/*
 * Function:  KLNCharStackPop
 * --------------------------
 *  Points the element (char) at the top of the stack to the given parameter.
 *  Note: This REMOVES the top element from the stack.
 *  Corresponds to Pop operation in stack specification.
 * 
 *  stack: Pointer to a declared KLNCharStack type variable.
 *  element: Pointer to the variable that the top element should be set.
 * 
 *  Returns: bool (True if the stack is not empty, false otherwise)
 * 
 */
bool KLNCharStackPop(KLNCharStack *stack, char *element);

/*
 * Function:  KLNCharStackPush
 * ---------------------------
 *  Pushes an element on to the top of the stack.
 *  Note: This makes the pushed element the new top of the stack.
 *  Corresponds to Push operation in stack specification.
 * 
 *  stack: Pointer to a declared KLNCharStack type variable.
 *  element: The variable with the value that should be pushed on to the stack.
 * 
 *  Returns: bool (True if the stack is not full, false otherwise)
 * 
 */
bool KLNCharStackPush(KLNCharStack *stack, char element);

/*
 * Function:  KLNCharStackDestroy
 * ------------------------------
 *  Deletes the given stack from memory, releasing all of the memory allocated.
 *  Note: The stack wont be usable after invoking this function.
 *  Corresponds to DestroyStack operation in stack specification.
 * 
 *  stack: Pointer to a declared KLNCharStack type variable.
 * 
 */
void KLNCharStackDestroy(KLNCharStack *stack);
