/*
 * Utility functions for strings.
 * Deployed under klnstl.
 * 
 * Author: D. M. Chandeepa Dissanayake
 * Student Number: PS/2017/035
 * Assignment Number: 1
 * Course Code: COSC 12513
 */

#pragma once

/*
 * Function:  KLNStringReverse
 * ---------------------------
 *  Reverses the given string and returns.
 * 
 *  str: The string to be reversed.
 * 
 *  Returns: char* (The reversed string.)
 * 
 */
char *KLNStringReverse(char *str);

/*
 * Function:  KLNStringRemoveSpaces
 * --------------------------------
 *  Removes spaces in the given string, inplace.
 * 
 *  str: The string in which the spaces are to be removed.
 * 
 *  Returns: Nothing
 * 
 */
void KLNStringRemoveSpaces(char *s);
