/*
 * Solution for Problem #1
 * Mathematical expressions validation.
 * Expression Validation Module.
 * 
 * Author: D. M. Chandeepa Dissanayake
 * Student Number: PS/2017/035
 * Assignment Number: 1
 * Course Code: COSC 12513
 */

#include "matexval.h"
#include <stdbool.h>
#include "../klnstl/klncharstack.h"

#include <stdio.h>

// Definition of all brackets.
MatExBracket MatEx_Brackets[] = {
    {'(', ')'},
    {'[', ']'},
    {'{', '}'},
};

/*
 *  Implementation of _MatExValGetBracketsCount function.
 *  Documented in matexval.h
 */
int _MatExValGetBracketsCount()
{
    return sizeof(MatEx_Brackets) / sizeof(MatEx_Brackets[0]);
}

/*
 *  Implementation of _MatExValIsOpenerBracket function.
 *  Documented in matexval.h
 */
bool _MatExValIsOpenerBracket(char bracket)
{
    int brackets_count = _MatExValGetBracketsCount();
    for (int i = 0; i < brackets_count; i++)
    {
        if (MatEx_Brackets[i].opener == bracket)
        {
            return true;
        }
    }

    return false;
}

/*
 *  Implementation of _MatExValIsCloserBracket function.
 *  Documented in matexval.h
 */
bool _MatExValIsCloserBracket(char bracket)
{
    int brackets_count = _MatExValGetBracketsCount();
    for (int i = 0; i < brackets_count; i++)
    {
        if (MatEx_Brackets[i].closer == bracket)
        {
            return true;
        }
    }

    return false;
}

/*
 *  Implementation of _MatExValIsBracketPair function.
 *  Documented in matexval.h
 */
bool _MatExValIsBracketPair(char opener, char closer)
{
    int brackets_count = _MatExValGetBracketsCount();
    for (int i = 0; i < brackets_count; i++)
    {
        if (MatEx_Brackets[i].opener == opener && MatEx_Brackets[i].closer == closer)
        {
            return true;
        }
    }

    return false;
}

/*
 *  Implementation of MatExValValidateExpr function.
 *  Documented in matexval.h
 */
bool MatExValValidateExpr(char *str_expr, int length_expr)
{
    KLNCharStack stack_expr;
    KLNCharStackCreateStack(&stack_expr);

    for (int i = 0; i < length_expr; i++)
    {
        if (_MatExValIsOpenerBracket(str_expr[i]))
        {
            KLNCharStackPush(&stack_expr, str_expr[i]);
        }
        else if (_MatExValIsCloserBracket(str_expr[i]))
        {
            char last_opener_bracket;
            KLNCharStackPop(&stack_expr, &last_opener_bracket);

            if (!_MatExValIsBracketPair(last_opener_bracket, str_expr[i]))
            {
                return false;
            }
        }
    }

    bool retval = stack_expr.size == 0;
    KLNCharStackDestroy(&stack_expr);
    return retval;
}
