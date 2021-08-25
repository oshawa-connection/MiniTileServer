#include "../headers/bbox.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <regex.h>

const int BBOX_MATCH_COUNT = 4;

double calculate_bbox_area(bbox * bboxPtr) {
    double delta_x = bboxPtr->max_x - bboxPtr->min_x;
    double delta_y = bboxPtr->max_y - bboxPtr->min_y;
    return delta_x * delta_y;
}



bbox * create_bbox_ptr(double min_x, double max_x, double min_y, double max_y) {
    // bbox new_bbox = {min_x,,2,2};
    bbox * new_bbox = (bbox *)malloc(sizeof(bbox));
    new_bbox->min_x = min_x;
    new_bbox->max_x = max_x;
    new_bbox->min_y = min_y;
    new_bbox->max_y = max_y;
    return new_bbox;
}



void destroy_bbox_ptr(bbox * bbox_ptr) {
    free(bbox_ptr);
    bbox_ptr = NULL;
}


bool bbox_contains_point(bbox * bbox, point * point) {
    if (bbox->min_x > point->x) return false;
    if (bbox->min_y > point->y) return false;
    if (bbox->max_x < point->x) return false;
    if (bbox->max_y < point->y) return false;
        
    return true;
}



double parse_bbox_match(regmatch_t currentMatch,char * bboxString) {
    char parse_holder[100];
    
    int numchars = (int)currentMatch.rm_eo - (int)currentMatch.rm_so;
    strncpy(parse_holder,bboxString+currentMatch.rm_so,numchars);
    return atof(parse_holder);
}


void create_bbox_ptr_from_string_regex(char * bboxString) {
    char * bbox_matcher = "[0-9]{0,10}\\.[0-9]{0,9}";
    regex_t regex;
    int reti = regcomp(&regex, bbox_matcher, 0);
    if (reti) {
        fprintf(stderr, "Could not compile regex: %s\n",bbox_matcher);
        exit(1);
    }
    regmatch_t matches[4];
    int status = regexec(&regex,bboxString,BBOX_MATCH_COUNT,matches,0);
    if (status) {
        fprintf(stderr, "Error while running regex: %s\n",bbox_matcher);
        exit(1);
    }
    char *myString = (char*)malloc(sizeof(char) * 100);
    
    for (int matchCount = 0;matchCount < BBOX_MATCH_COUNT; matchCount ++) {
        regmatch_t currentMatch = matches[0];

        if (currentMatch.rm_so < 0) {
            fprintf(stderr,"ERROR WHILE PARSING BBOX STRING: %s index: %d",bboxString,matchCount);
            exit(1);
        }

        double myDouble = parse_bbox_match(currentMatch,bboxString);
        printf("Parsed double is: %f",myDouble);
    }
}