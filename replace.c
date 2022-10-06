/*--------------------------------------------------------------------*/
/* replace.c                                                          */
/* Author: Ishaan Javali                                              */
/*--------------------------------------------------------------------*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "str.h"

/*--------------------------------------------------------------------*/

/* If pcFrom is the empty string, then write string pcLine to stdout
   and return 0.  Otherwise write string pcLine to stdout with each
   distinct occurrence of string pcFrom replaced with string pcTo,
   and return a count of how many replacements were made.  Make no
   assumptions about the maximum number of replacements or the
   maximum number of characters in strings pcLine, pcFrom, or pcTo. */

static size_t replaceAndWrite(const char *pcLine, const char *pcFrom,
                              const char *pcTo) {
    /* ptr is the pointer for string pcLine. location is the pointer for where
     * the leftmost pcFrom is found in pcLine. count keeps track of the number
     * of replacements. i is used to advance ptr the length of pcFrom (to skip
     * it , when needed)*/
    const char *ptr;
    char *location;
    size_t pcFromLength;
    size_t count = 0;
    size_t i;

    assert(pcLine != NULL);
    assert(pcFrom != NULL);
    assert(pcTo != NULL);
    if (pcFrom[0] == '\0') {
        printf("%s", pcLine);
        return 0;
    }
    ptr = pcLine;
    pcFromLength = Str_getLength(pcFrom);
    /* Iterate while we have not reached the end of the line and there are more
     * occurences of pcFrom in ptr. */
    while (*ptr != '\0' && (location = Str_search(ptr, pcFrom)) != NULL) {
        count++;
        /* Get the pointer to the leftmost occurence of pcFrom in our current
        position, ptr, to the end of pcLine. Then advance ptr and print out all
        the characters in pcLine until the occurence of pcFrom. */
        while (ptr != location) {
            printf("%c", *ptr);
            ptr++;
        }
        /* "Replace" pcFrom with pcTo by advancing the ptr for pcLine and
        thereby not printing out the occurence of pcFrom. Then, print out the
        characters in pcTo */
        // for (i = 0; i < pcFromLength; i++) ptr++;
        ptr += pcFromLength;
        i = 0;
        while (pcTo[i] != '\0') {
            printf("%c", pcTo[i]);
            i++;
        }
    }
    /* Print the remaining characters */
    while (*ptr != '\0') {
        printf("%c", *ptr);
        ptr++;
    }
    return count;
}

/*--------------------------------------------------------------------*/

/* If argc is unequal to 3, then write an error message to stderr and
   return EXIT_FAILURE.  Otherwise...
   If argv[1] is the empty string, then write each line of stdin to
   stdout, write a message to stderr indicating that 0 replacements
   were made, and return 0.  Otherwise...
   Write each line of stdin to stdout with each distinct occurrence of
   argv[1] replaced with argv[2], write a message to stderr indicating
   how many replacements were made, and return 0.
   Assume that no line of stdin consists of more than MAX_LINE_SIZE-1
   characters. */

int main(int argc, char *argv[]) {
    enum { MAX_LINE_SIZE = 4096 };
    enum { PROPER_ARG_COUNT = 3 };

    char acLine[MAX_LINE_SIZE];
    char *pcFrom;
    char *pcTo;
    size_t uReplaceCount = 0;

    if (argc != PROPER_ARG_COUNT) {
        fprintf(stderr, "usage: %s fromstring tostring\n", argv[0]);
        return EXIT_FAILURE;
    }

    pcFrom = argv[1];
    pcTo = argv[2];

    while (fgets(acLine, MAX_LINE_SIZE, stdin) != NULL) {
        if (Str_getLength(pcFrom) == 0) {
            printf("%s", acLine);
        } else {
            uReplaceCount += replaceAndWrite(acLine, pcFrom, pcTo);
        }
    }

    fprintf(stderr, "%lu replacements\n", (unsigned long)uReplaceCount);
    return 0;
}
