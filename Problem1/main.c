/*
 * Solution for Problem #1
 * Mathematical expressions validation.
 * main.c: Entry Point to the program.
 * 
 * Author: D. M. Chandeepa Dissanayake
 * Student Number: PS/2017/035
 * Assignment Number: 1
 * Course Code: COSC 12513
 */

#include <stdio.h>
#include <string.h>
#include "matexval.h"

#define MAX_INPUT_LENGTH 20

void main()
{
    char str_expr[MAX_INPUT_LENGTH];
    printf("Enter the Expression: ");
    gets(str_expr);

    bool is_expr_valid = MatExValValidateExpr(str_expr, strlen(str_expr));

    if (is_expr_valid)
    {
        printf("Valid Expression\n");
    }
    else
    {
        printf("Invalid Expresion\n");
    }
}
