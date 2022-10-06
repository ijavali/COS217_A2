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
    assert(pcDest != NULL);
    assert(pcSrc != NULL);
    size_t uLength = 0;
    while (pcSrc[uLength] != '\0') {
        pcDest[uLength] = pcSrc[uLength];
        uLength++;
    }
    pcDest[uLength] = '\0';
    return &pcDest[0];
}

char *Str_concat(char *pcDest, const char *pcSrc) {
    assert(pcDest != NULL);
    assert(pcSrc != NULL);
    size_t i = 0, j = 0;
    while (pcDest[i] != '\0') i++;
    while (pcSrc[j] != '\0') {
        pcDest[i] = pcSrc[j];
        i++;
        j++;
    }
    pcDest[i] = '\0';
    return &pcDest[0];
}

size_t Str_compare(char *str1, const char *str2) {
    assert(str1 != NULL);
    assert(str2 != NULL);
    size_t i = 0, j = 0;
    while (str1[i] != '\0' && str2[j] != '\0') {
        if (str1[i] != str2[j]) {
            if (str1[i] > str2[j])
                return 1;
            else
                return -1;
        }
        i++;
        j++;
    }
    if (str1[i] == '\0' && str2[j] == '\0')
        return 0;
    else if (str1[i] == '\0')
        return -1;
    return 1;
}

char *Str_search(const char *str1[], const char *str2) {
    assert(str1 != NULL);
    assert(str2 != NULL);
    size_t i = 0, j = 0;
    while (str1[i] != '\0') {
        size_t currentI = i;
        while (str1[currentI] != '\0' && str2[j] != '\0' &&
               str1[currentI] == str2[j]) {
            currentI++;
            j++;
        }
        if (str2[j] == '\0') return &str1[i];
        i++;
        j = 0;
    }
    if (str2[j] == '\0') return &str1[i];
    return NULL;
}
