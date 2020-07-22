/*
 * Solution for Problem #2
 * Infix -> Prefix
 * main.c: Entry Point to the program.
 * 
 * Note: This solutuon would work for the expressions ONLY with addition and subtraction (+ & -) operators.
 * 
 * Author: D. M. Chandeepa Dissanayake
 * Student Number: PS/2017/035
 * Assignment Number: 1
 * Course Code: COSC 12513
 */

#include <stdio.h>
#include <stdlib.h>
#include "matex.h"
#include <string.h>
#include "../klnstl/klnstringutils.h"

#define MAX_INPUT_LENGTH 20

void main()
{
    char in_infix_expr[MAX_INPUT_LENGTH];
    printf("Enter the Expression (Infix): ");
    fgets(in_infix_expr, MAX_INPUT_LENGTH, stdin);

    // Removes spaces in the input expression.
    KLNStringRemoveSpaces(in_infix_expr);

    // Allocates memory for a output variable to be used in the infix to prefix transformation function and invokes the function.
    int ch_count_in_infix_expr = MatExGetExprLength(in_infix_expr) + 1;
    char *out_outfix_expr = (char *)malloc(sizeof(char) * ch_count_in_infix_expr);
    out_outfix_expr[ch_count_in_infix_expr - 1] = '\0';

    MatExInfixToPrefix(in_infix_expr, out_outfix_expr);
    printf("Output Expression (Prefix): %s\n", out_outfix_expr);

    // Deallocates the memory for above variable.
    free(out_outfix_expr);
}
