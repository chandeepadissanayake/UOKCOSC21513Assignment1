/*
 * Solution for Problem #2
 * Mathematical expressions util functions
 * Support functions for mathematical expressions manipulation.
 * 
 * Author: D. M. Chandeepa Dissanayake
 * Student Number: PS/2017/035
 * Assignment Number: 1
 * Course Code: COSC 12513
 */

#include "matex.h"
#include <stdbool.h>
#include <string.h>
#include "../klnstl/klncharstack.h"
#include "../klnstl/klnstringutils.h"

// Definition of all mathematical operators.
char MatEx_Operators[] = {
    _MATEX_OPERATOR_ADDITION,
    _MATEX_OPERATOR_SUBTRACTION,
    _MATEX_OPERATOR_MULTIPLICATION,
    _MATEX_OPERATOR_DIVISION,
    _MATEX_OPERATOR_EXPONENTIAL,
};

/*
 *  Implementation of _MatExGetOperatorsCount function.
 *  Documented in matex.h
 */
int _MatExGetOperatorsCount()
{
    return sizeof(MatEx_Operators) / sizeof(MatEx_Operators[0]);
}

/*
 *  Implementation of _MatExIsOperator function.
 *  Documented in matex.h
 */
bool _MatExIsOperator(char ch)
{
    int operators_count = _MatExGetOperatorsCount();
    for (int i = 0; i < operators_count; i++)
    {
        if (ch == MatEx_Operators[i])
        {
            return true;
        }
    }

    return false;
}

/*
 *  Implementation of _MatExGetOperatorPrecedenceLevel function.
 *  Documented in matex.h
 */
int _MatExGetOperatorPrecedenceLevel(char operator)
{
    switch (operator)
    {
    case _MATEX_OPERATOR_ADDITION:
    case _MATEX_OPERATOR_SUBTRACTION:
        return _MATEX_OPERATOR_OP_LEVEL_1;
    case _MATEX_OPERATOR_MULTIPLICATION:
    case _MATEX_OPERATOR_DIVISION:
        return _MATEX_OPERATOR_OP_LEVEL_2;
    case _MATEX_OPERATOR_EXPONENTIAL:
        return _MATEX_OPERATOR_OP_LEVEL_3;
    default:
        return -1;
    }
}

/*
 *  Implementation of _MatExGetOperatorAssociativity function.
 *  Documented in matex.h
 */
int _MatExGetOperatorAssociativity(char operator)
{
    switch (operator)
    {
    case _MATEX_OPERATOR_EXPONENTIAL:
    case _MATEX_OPERATOR_SUBTRACTION:
    case _MATEX_OPERATOR_DIVISION:
        return _MATEX_OPERATOR_ASSOCIATIVE_RIGHT;
    default:
        return _MATEX_OPERATOR_ASSOCIATIVE_LEFT;
    }
}

/*
 *  Implementation of _MatExIsLeftOperatorHighPrecedence function.
 *  Documented in matex.h
 */
bool _MatExIsLeftOperatorHighPrecedence(char left_operator, char right_operator)
{
    // Obtain precedence levels for both operators.
    int pl_lo = _MatExGetOperatorPrecedenceLevel(left_operator);
    int pl_ro = _MatExGetOperatorPrecedenceLevel(right_operator);

    // If precedence levels are equal, then
    if (pl_lo == pl_ro)
    {
        // If left_operator is left associative, that should then it should be prioritized.
        return _MatExGetOperatorAssociativity(left_operator) == _MATEX_OPERATOR_ASSOCIATIVE_LEFT;
    }
    else
    {
        return pl_lo > pl_ro;
    }
}

/*
 *  Implementation of _MatExIsOpeningParenthesis function.
 *  Documented in matex.h
 */
bool _MatExIsOpeningParenthesis(char ch)
{
    return ch == _MATEX_OPENING_PARENTHESIS;
}

/*
 *  Implementation of _MatExIsClosingParenthesis function.
 *  Documented in matex.h
 */
bool _MatExIsClosingParenthesis(char ch)
{
    return ch == _MATEX_CLOSING_PARENTHESIS;
}

/*
 *  Implementation of MatExGetExprLength function.
 *  Documented in matex.h
 */
int MatExGetExprLength(char *expr)
{
    return strlen(expr);
}

/*
 *  Implementation of MatExInfixToPostfix function.
 *  Documented in matex.h
 */
void MatExInfixToPostfix(char *in_infix_expr, char *out_postfix_expr)
{
    KLNCharStack stack_opr;
    KLNCharStackCreateStack(&stack_opr);

    int len_expr = MatExGetExprLength(in_infix_expr);
    int index_postfix = 0;
    char stack_top;
    for (int i = 0; i < len_expr; i++)
    {
        char curr_char = in_infix_expr[i];

        if (_MatExIsOperator(curr_char))
        {
            // If the current operator is of lower priority than stack top, Append all the operands in the stack until end is reached or opening paranthesis is found.
            KLNCharStackTop(&stack_opr, &stack_top);
            if (_MatExIsLeftOperatorHighPrecedence(stack_top, curr_char)) // This returns false for paranthesis too (because -1 will be given as the precedence level for paranthesis).
            {
                while (KLNCharStackPop(&stack_opr, &stack_top) && stack_top != _MATEX_OPENING_PARENTHESIS)
                {
                    out_postfix_expr[index_postfix++] = stack_top;
                }
            }

            // Add the operator to the stack after removing all of the higher priority ones above which affects only the operands currently in the output string.
            KLNCharStackPush(&stack_opr, curr_char);
        }
        else if (_MatExIsOpeningParenthesis(curr_char))
        {
            KLNCharStackPush(&stack_opr, curr_char);
        }
        else if (_MatExIsClosingParenthesis(curr_char))
        {
            // Since a closing parantheis means an end of a certain block of operations, append all opeartors in the stack (popping them out) until a opening bracket is reached.
            while (KLNCharStackPop(&stack_opr, &stack_top) && stack_top != _MATEX_OPENING_PARENTHESIS)
            {
                out_postfix_expr[index_postfix++] = stack_top;
            }
        }
        else
        {
            // Just append to the output if it is a operand.
            out_postfix_expr[index_postfix++] = curr_char;
        }
    }

    while (KLNCharStackPop(&stack_opr, &stack_top))
    {
        out_postfix_expr[index_postfix++] = stack_top;
    }
}

/*
 *  Implementation of MatExInfixToPrefix function.
 *  Documented in matex.h
 */
void MatExInfixToPrefix(char *in_infix_expr, char *out_prefix_expr)
{
    // Reverse the expression
    char *rev_in_infix_expr = KLNStringReverse(in_infix_expr);

    // Convert the brackets to the opposite one in the reversed expression.
    int len_rev_infix_expr = MatExGetExprLength(rev_in_infix_expr);
    for (int i = 0; i < len_rev_infix_expr; i++)
    {
        switch (rev_in_infix_expr[i])
        {
        case _MATEX_OPENING_PARENTHESIS:
            rev_in_infix_expr[i] = _MATEX_CLOSING_PARENTHESIS;
            break;
        case _MATEX_CLOSING_PARENTHESIS:
            rev_in_infix_expr[i] = _MATEX_OPENING_PARENTHESIS;
            break;
        default:
            break;
        }
    }

    // Obtaining the postfix of the reversed infix expression
    MatExInfixToPostfix(rev_in_infix_expr, out_prefix_expr);
    // Reverse the output string.
    out_prefix_expr = KLNStringReverse(out_prefix_expr);
}
