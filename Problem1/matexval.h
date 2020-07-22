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
#pragma once

#include <stdbool.h>

// Struct for holding bracket pair.
typedef struct MatExBracket
{
    char opener;
    char closer;
} MatExBracket;

// Declaration of all brackets.
extern MatExBracket MatEx_Brackets[];

/*
 * Function:  _MatExValGetBracketsCount
 * ------------------------------------
 *  Get the total number of bracket pairs in MatEx_Brackets.
 *  Note: ONLY for local use within matexval.
 * 
 *  Returns: int (Number of elements in MatEx_Brackets)
 * 
 */
int _MatExValGetBracketsCount();

/*
 * Function:  _MatExValIsOpenerBracket
 * -----------------------------------
 *  Checks whether the given bracket is a opening bracket or not.
 *  Note: ONLY for local use within matexval.
 * 
 *  bracket: The bracket character to check.
 * 
 *  Returns: bool (True if the given bracket is a opening bracket, false otherwise.)
 * 
 */
bool _MatExValIsOpenerBracket(char bracket);

/*
 * Function:  _MatExValIsCloserBracket
 * -----------------------------------
 *  Checks whether the given bracket is a closing bracket or not.
 *  Note: ONLY for local use within matexval.
 * 
 *  bracket: The bracket character to check.
 * 
 *  Returns: bool (True if the given bracket is a closing bracket, false otherwise.)
 * 
 */
bool _MatExValIsCloserBracket(char bracket);

/*
 * Function:  _MatExValIsBracketPair
 * ---------------------------------
 *  Checks whether the given bracket pair is a opening and closing pair.
 *  Note: ONLY for local use within matexval.
 * 
 *  opener: The opener bracket character.
 *  closer: The closer bracket character.
 * 
 *  Returns: bool (True if the given bracket pair is a opening and closing pair, false otherwise.)
 * 
 */
bool _MatExValIsBracketPair(char opener, char closer);

/*
 * Function:  MatExValValidateExpr
 * -------------------------------
 *  Validates a given mathematical expression.
 * 
 *  str_expr: String, mathematical expression to check.
 * 
 *  Returns: bool (True if the given expression is a valid mathematical expression, false otherwise.)
 * 
 */
bool MatExValValidateExpr(char *str_expr, int length_expr);
