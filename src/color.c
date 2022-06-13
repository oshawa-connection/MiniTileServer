#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "../headers/color.h"
#include "../headers/constants.h"

static regex_t regex;
static bool isInitialised = false;


color * createColor() {
    color * newColor = (color *)malloc(sizeof(color));
    return newColor;
}

void destroyColor(color * colorPtr) {
    free(colorPtr);
    colorPtr = NULL;
}

bool colorIsValid() {
    if (isInitialised == true) {
        fputs("WARNING: colorCheckingRegex was initialised more than once.",stderr);
    }
    return true;   
}

color * parseColorString(char * colorString) {
    const char * colorMatcher = "^\\s*([0-9]{1,3})\\,\\s*([0-9]{1,3})\\,\\s*([0-9]{1,3})\\s*$";
    regex_t regex;
    int reti = regcomp(&regex, colorMatcher, REG_EXTENDED);
    
    if (reti) {
        fprintf(stderr, "Could not compile regex: %s\n",colorMatcher);
        exit(EXIT_FAILURE);
    }
    
    // Number of matches = 1 (for the whole match) + 3 for R,G and B.
    const size_t numberOfGroups = 4;

    regmatch_t groupArray[numberOfGroups];
    int status = regexec(&regex,colorString,numberOfGroups,groupArray,0);
    if (status) {
        fprintf(stderr,"Invalid style color: %s",colorString);
        exit(EXIT_FAILURE);
    }
    
    color * newColor = createColor();

    for (int groupIndex =0; groupIndex < numberOfGroups;groupIndex ++) {
        regmatch_t currentMatch = groupArray[groupIndex];
        int colorStringLength = currentMatch.rm_eo - currentMatch.rm_so;
        char * parsedColourString = (char *)malloc(currentMatch.rm_eo - currentMatch.rm_so);
        memset(parsedColourString,NULL_CHAR,colorStringLength);
        strncpy( parsedColourString,  colorString + currentMatch.rm_so, currentMatch.rm_eo - currentMatch.rm_so );

        if (0 == groupIndex) {
            newColor->red = atoi(parsedColourString);
        } else if (1 == groupIndex) {
            newColor->green = atoi(parsedColourString);
        } else if (2 == groupIndex) {
            newColor->blue = atoi(parsedColourString);
        }
        free(parsedColourString);
        parsedColourString = NULL;
    }
    return newColor;
}

