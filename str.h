/*--------------------------------------------------------------------*/
/* stra.h                                                             */
/* Author: Ishaan Javali                                              */
/*--------------------------------------------------------------------*/

#ifndef STR_H
#define STR_H

#include <stddef.h>

/* Return the length of string pcSrc. */
size_t Str_getLength(const char pcSrc[]);

/* Copy the content of string pcSrc into string pcDest and return pointer to
 * pcDest string */
char *Str_copy(char pcDest[], const char pcSrc[]);

/* Concatenate the content of string pcSrc to the end of string pcDest and
 * return pointer to pcDest string */
char *Str_concat(char pcDest[], const char pcSrc[]);

/* Return 0 if strings str1 and str2 are equal, 1 if  str1 comes after
 * str2 lexicographically, or -1 if str1 comes before str2 lexicographically*/
int Str_compare(const char str1[], const char str2[]);

/* Copy the content of string str2 into string str1 and return pointer to
 * str1 string  */
char *Str_search(const char str1[], const char str2[]);

#endif
