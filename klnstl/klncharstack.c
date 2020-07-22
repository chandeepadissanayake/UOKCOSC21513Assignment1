/*
 * Linked Implementation of Stacks for char data type.
 * Deployed under klnstl.
 * 
 * Author: D. M. Chandeepa Dissanayake
 * Student Number: PS/2017/035
 * Assignment Number: 1
 * Course Code: COSC 12513
 */

#include "klncharstack.h"
#include <stdlib.h>
#include <stdbool.h>

/*
 *  Implementation of KLNCharStackCreateStack function.
 *  Documented in klncharstack.h
 */
void KLNCharStackCreateStack(KLNCharStack *stack)
{
    stack->top = NULL;
    stack->size = 0;
    stack->is_full = false;
}

/*
 *  Implementation of KLNCharStackIsEmpty function.
 *  Documented in klncharstack.h
 */
bool KLNCharStackIsEmpty(KLNCharStack *stack)
{
    return stack->size == 0;
}

/*
 *  Implementation of KLNCharStackIsFull function.
 *  Documented in klncharstack.h
 */
bool KLNCharStackIsFull(KLNCharStack *stack)
{
    return stack->is_full;
}

/*
 *  Implementation of KLNCharStackTop function.
 *  Documented in klncharstack.h
 */
bool KLNCharStackTop(KLNCharStack *stack, char *element)
{
    if (KLNCharStackIsEmpty(stack))
    {
        return false;
    }

    *element = stack->top->value;

    return true;
}

/*
 *  Implementation of KLNCharStackPop function.
 *  Documented in klncharstack.h
 */
bool KLNCharStackPop(KLNCharStack *stack, char *element)
{
    if (!KLNCharStackTop(stack, element))
    {
        return false;
    }

    // Removes the top element from the stack.
    KLNCharStackNode *stack_old_top = stack->top;
    stack->top = stack_old_top->next;
    stack->size--;
    stack->is_full = false;

    // Releases the memory allocated for the top element.
    free(stack_old_top);

    return true;
}

/*
 *  Implementation of KLNCharStackPush function.
 *  Documented in klncharstack.h
 */
bool KLNCharStackPush(KLNCharStack *stack, char element)
{
    // Allocates memory from the heap (dynamic impl)
    KLNCharStackNode *node_element = malloc(sizeof(KLNCharStackNode));
    if (node_element == NULL)
    {
        stack->is_full = true;
        return false;
    }

    // Configures the new stack node.
    node_element->value = element;
    node_element->next = stack->top;

    // Sets the new top element for the stack.
    stack->top = node_element;
    stack->size++;

    return true;
}

/*
 *  Implementation of KLNCharStackDestroy function.
 *  Documented in klncharstack.h
 */
void KLNCharStackDestroy(KLNCharStack *stack)
{
    char element;
    while (KLNCharStackPop(stack, &element))
        ;
}
