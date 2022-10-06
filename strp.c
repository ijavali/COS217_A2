/*--------------------------------------------------------------------*/
/* strp.c                                                             */
/* Author: Ishaan Javali                                              */
/*--------------------------------------------------------------------*/

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

size_t Str_getLength(const char *pcSrc) {
    const char *pcEnd;
    assert(pcSrc != NULL);
    pcEnd = pcSrc;
    while (*pcEnd != '\0') pcEnd++;
    return (size_t)(pcEnd - pcSrc);
}

char *Str_copy(char *pcDest, const char *pcSrc) {
    char *dest;
    const char *src;
    assert(pcDest != NULL);
    assert(pcSrc != NULL);
    dest = pcDest;
    src = pcSrc;
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return pcDest;
}

char *Str_concat(char *pcDest, const char *pcSrc) {
    char *dest;
    const char *src;
    assert(pcDest != NULL);
    assert(pcSrc != NULL);
    dest = pcDest;
    src = pcSrc;
    while (*dest != '\0') dest++;
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return pcDest;
}

int Str_compare(const char *str1, const char *str2) {
    char *pointer1, *pointer2;
    assert(str1 != NULL);
    assert(str2 != NULL);
    pointer1 = str1;
    pointer2 = str2;

    while (*pointer1 != '\0' && *pointer2 != '\0') {
        if (*pointer1 != *pointer2) {
            if (*pointer1 > *pointer2)
                return 1;
            else
                return -1;
        }
        pointer1++;
        pointer2++;
    }
    if (*pointer1 == '\0' && *pointer2 == '\0')
        return 0;
    else if (*pointer1 == '\0')
        return -1;
    return 1;
}

const char *Str_search(const char *str1, const char *str2) {
    const char *pointer1;
    char *pointer2;
    assert(str1 != NULL);
    assert(str2 != NULL);
    pointer1 = str1;
    pointer2 = str2;
    while (*pointer1 != '\0') {
        char *currentI = pointer1;
        while (*currentI != '\0' && *pointer2 != '\0' &&
               *currentI == *pointer2) {
            currentI++;
            pointer2++;
        }
        if (*pointer2 == '\0') return pointer1;
        pointer1++;
        pointer2 = str2;
    }
    if (*pointer2 == '\0') return pointer1;
    return NULL;
}
