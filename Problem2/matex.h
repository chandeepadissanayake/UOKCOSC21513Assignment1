/*
 * Solution for Problem #2
 * Mathematical expressions util functions
 * Support functions for mathematical expressions manupulation.
 * 
 * Author: D. M. Chandeepa Dissanayake
 * Student Number: PS/2017/035
 * Assignment Number: 1
 * Course Code: COSC 12513
 */
#pragma once

#include <stdbool.h>

// All Operators
#define _MATEX_OPERATOR_ADDITION '+'
#define _MATEX_OPERATOR_SUBTRACTION '-'
#define _MATEX_OPERATOR_MULTIPLICATION '*'
#define _MATEX_OPERATOR_DIVISION '/'
#define _MATEX_OPERATOR_EXPONENTIAL '^'

// Declaration of all mathematical operators.
extern char MatEx_Operators[];

// Operator Precendence Levels
#define _MATEX_OPERATOR_OP_LEVEL_1 1
#define _MATEX_OPERATOR_OP_LEVEL_2 2
#define _MATEX_OPERATOR_OP_LEVEL_3 3

// Operator Associativity Flags
#define _MATEX_OPERATOR_ASSOCIATIVE_LEFT -1
#define _MATEX_OPERATOR_ASSOCIATIVE_RIGHT 1

// Opening parentheis
#define _MATEX_OPENING_PARENTHESIS '('
#define _MATEX_CLOSING_PARENTHESIS ')'

/*
 * Function:  _MatExGetOperatorsCount
 * ----------------------------------
 *  Gets the number of valid mathematical operators defined specifically for this problem.
 * 
 * 
 *  Returns: int (The number of valid mathematical operators.)
 * 
 */
int _MatExGetOperatorsCount();

/*
 * Function:  _MatExIsOperator
 * ---------------------------
 *  Checks whether the given character is a valid mathematical operator.
 * 
 *  ch: The character to be checked.
 * 
 *  Returns: bool (True if the given character is a valid mathematical operator, false otherwise.)
 * 
 */
bool _MatExIsOperator(char ch);

/*
 * Function:  _MatExGetOperatorPrecedenceLevel
 * -------------------------------------------
 *  Returns the Precedence level for the given operator.
 * 
 *  ch: The operator to be checked.
 * 
 *  Returns: int (_MATEX_OPERATOR_OP_LEVEL_1/_MATEX_OPERATOR_OP_LEVEL_2/_MATEX_OPERATOR_OP_LEVEL_3)
 * 
 */
int _MatExGetOperatorPrecedenceLevel(char operator);

/*
 * Function:  _MatExGetOperatorAssociativity
 * -----------------------------------------
 *  Returns the Left Associativity of the given operator in precedence.
 * 
 *  ch: The operator to be checked.
 * 
 *  Returns: int (_MATEX_OPERATOR_ASSOCIATIVE_LEFT/_MATEX_OPERATOR_ASSOCIATIVE_RIGHT)
 * 
 */
int _MatExGetOperatorAssociativity(char operator);

/*
 * Function:  _MatExIsLeftOperatorHighPrecedence
 * ---------------------------------------------
 *  Checks whether left_operator is of higher precedence (and priority with respect to assocativity) compared to right operator.
 * 
 *  left_operator : Operator character 1
 *  right_operator: Operator character 2.
 * 
 *  Returns: bool (True if left_operator has a higher precedence, false otherwise.)
 * 
 */
bool _MatExIsLeftOperatorHighPrecedence(char left_operator, char right_operator);

/*
 * Function:  _MatExIsOpeningParenthesis
 * -------------------------------------
 *  Checks whether the given character is an opening parenthesis character specified by _MATEX_OPENING_PARENTHESIS
 * 
 *  ch: The character to be checked.
 * 
 *  Returns: bool (True if the given character is an opening parenthesis, false otherwise.)
 * 
 */
bool _MatExIsOpeningParenthesis(char ch);

/*
 * Function:  _MatExIsClosingParenthesis
 * -------------------------------------
 *  Checks whether the given character is an closing parenthesis character specified by _MATEX_CLOSING_PARENTHESIS
 * 
 *  ch: The character to be checked.
 * 
 *  Returns: bool (True if the given character is an closing parenthesis, false otherwise.)
 * 
 */
bool _MatExIsClosingParenthesis(char ch);

/*
 * Function:  MatExGetExprLength
 * -----------------------------
 *  Returns the length of the mathematical expression given.
 * 
 *  Returns: int (The number of characters in the given expression.)
 * 
 */
int MatExGetExprLength(char *expr);

/*
 * Function:  MatExInfixToPostfix
 * ------------------------------
 *  Converts a given infix mathematical expression to postfix mathematical expression.
 * 
 *  in_infix_expr    : Input mathematical expression formatted in infix standards.
 *  out_postfix_expr : Pointer to the allocated memory for output postfix expression. Note: This variable must be allocated memory AND INITIALIZED before passing in with a size of sizeof(char) * MatExGetExprLength
 * 
 *  Returns: Nothing.
 * 
 */
void MatExInfixToPostfix(char *in_infix_expr, char *out_postfix_expr);

/*
 * Function:  MatExInfixToPrefix
 * -----------------------------
 *  Converts a given infix mathematical expression to prefix mathematical expression.
 * 
 *  in_infix_expr   : Input mathematical expression formatted in infix standards.
 *  out_prefix_expr : Pointer to the allocated memory for output prefix expression. Note: This variable must be allocated memory AND INITIALIZED before passing in with a size of sizeof(char) * MatExGetExprLength
 * 
 *  Returns: Nothing.
 * 
 */
void MatExInfixToPrefix(char *in_infix_expr, char *out_prefix_expr);
