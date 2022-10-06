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
    char *dest, *src;
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
    return &pcDest[0];
}

char *Str_concat(char pcDest[], const char pcSrc[]) {
    char *dest, *src;
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
    return &pcDest[0];
}

size_t Str_compare(const char str1[], const char str2[]) {
    char *dest, *src;
    assert(str1 != NULL);
    assert(str2 != NULL);
    dest = str1;
    src = str2;

    while (*dest != '\0' && *src != '\0') {
        if (*dest != *src) {
            if (*dest > *src)
                return 1;
            else
                return -1;
        }
        dest++;
        src++;
    }
    if (*dest == '\0' && *src == '\0')
        return 0;
    else if (*dest == '\0')
        return -1;
    return 1;
}

char *Str_search(const char str1[], const char str2[]) {
    char *dest, *src;
    assert(str1 != NULL);
    assert(str2 != NULL);
    dest = str1;
    src = str2;
    while (*dest != '\0') {
        char *currentI = dest;
        while (*currentI != '\0' && *src != '\0' &&
               *currentI == *src) {
            currentI++;
            src++;
        }
        if (*src == '\0') return dest;
        dest++;
        src++;
    }
    if (*src == '\0') return dest;
    return NULL;
}
