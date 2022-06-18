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


color * createColor(int red, int green, int blue, float alpha) {
    color * newColor = (color *)malloc(sizeof(color));
    if (newColor == NULL) {
        return 0;
    }
    newColor->red=red;
    newColor->green=green;
    newColor->blue=blue;
    newColor->alpha=alpha;
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
    
    color * newColor = createColor(0,0,0,0.0);

    for (int groupIndex =1; groupIndex < numberOfGroups;groupIndex ++) {
        regmatch_t currentMatch = groupArray[groupIndex];
        int colorStringLength = currentMatch.rm_eo - currentMatch.rm_so;
        char * parsedColourString = (char *)malloc(currentMatch.rm_eo - currentMatch.rm_so);

        memset(parsedColourString,NULL_CHAR,colorStringLength);
        // this is not correct as it doesn't account for commas?
        strncpy( parsedColourString,  colorString + currentMatch.rm_so, currentMatch.rm_eo - currentMatch.rm_so );
        if (1 == groupIndex) {
            newColor->red = atoi(parsedColourString);
        } else if (2 == groupIndex) {
            newColor->green = atoi(parsedColourString);
        } else if (3 == groupIndex) {
            newColor->blue = atoi(parsedColourString);
        }
        // Needed because memory will be recycled
        memset(parsedColourString,NULL_CHAR,colorStringLength);
        free(parsedColourString);
        parsedColourString = NULL;
    }
    return newColor;
}

