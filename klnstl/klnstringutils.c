/*
 * Utility functions for strings.
 * Deployed under klnstl.
 * 
 * Author: D. M. Chandeepa Dissanayake
 * Student Number: PS/2017/035
 * Assignment Number: 1
 * Course Code: COSC 12513
 */

#include "klnstringutils.h"
#include <string.h>

/*
 *  Implementation of KLNStringReverse function.
 *  Documented in klnstringutils.h
 */
char *KLNStringReverse(char *str)
{
    char *p1, *p2;

    if (!str || !*str)
    {
        return str;
    }

    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
    {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }

    return str;
}

/*
 *  Implementation of KLNStringRemoveSpaces function.
 *  Documented in klnstringutils.h
 */
void KLNStringRemoveSpaces(char *s)
{
    const char *d = s;
    do
    {
        while (*d == ' ')
        {
            ++d;
        }
    } while (*s++ = *d++);
}
