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
    return pcDest;
}

char *Str_concat(char *pcDest, const char *pcSrc) {
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
    return pcDest;
}

size_t Str_compare(const char *str1, const char *str2) {
    char *p1, *p2;
    assert(str1 != NULL);
    assert(str2 != NULL);
    p1 = str1;
    p2 = str2;

    while (*p1 != '\0' && *p2 != '\0') {
        if (*p1 != *p2) {
            if (*p1 > *p2)
                return 1;
            else
                return -1;
        }
        p1++;
        p2++;
    }
    if (*p1 == '\0' && *p2 == '\0')
        return 0;
    else if (*p1 == '\0')
        return -1;
    return 1;
}

char *Str_search(const char *str1, const char *str2) {
    char *p1, *p2;
    assert(str1 != NULL);
    assert(str2 != NULL);
    p1 = str1;
    p2 = str2;
    while (*p1 != '\0') {
        char *currentI = p1;
        while (*currentI != '\0' && *p2 != '\0' && *currentI == *p2) {
            currentI++;
            p2++;
        }
        if (*p2 == '\0') return p1;
        p1++;
        p2 = str2;
    }
    if (*p2 == '\0') return p1;
    return NULL;
}
