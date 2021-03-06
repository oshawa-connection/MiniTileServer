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
    const char * bbox_matcher = "[0-9]{0,10}\\.[0-9]{0,9}";
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


bbox * create_bbox_ptr_from_string(char * bboxString) {
    // Doesn't need to be heap allocated. Could make a regular array
    char * current_string = (char * ) malloc(sizeof(char) * 100);
    memset(current_string,'\0',100);
    char current_char = '\0';
    size_t current_index = 0; 
    short current_count_match = 0;
    size_t max_len = strlen(bboxString);
    size_t current_string_index = 0;
    double myDouble;
    bbox * new_bbox = (bbox *) malloc(sizeof(bbox));
    
    while (current_index < max_len) {
        current_char = bboxString[current_index];
        if (current_char == '%' || current_index == max_len -1 ) {
            myDouble = atof(current_string);
            switch (current_count_match) {
                case 0:
                    new_bbox->min_x = myDouble;
                    break;
                case 1:
                    new_bbox->min_y = myDouble;
                    break;
                case 2:
                    new_bbox->max_x = myDouble;
                    break;
                case 3:
                    new_bbox->max_y = myDouble;
                    break;
                default:
                    fprintf(stderr, "Invalid BBOX string %s",bboxString);
                    exit(1);
                    break;
            }
            current_count_match += 1;
            current_string_index = 0;
            current_index += 2;
            memset(current_string,'\0',100);
        } else {
            
            current_string[current_string_index] = current_char;
            current_string_index += 1;            
        }
        current_index += 1;
    }
    free(current_string);
    current_string = NULL;
    return new_bbox;
}



double dinterpolateY(double scale_min, double scale_max, bbox * bboxPtr,point * pointPtr) {
    return (scale_max - scale_min) /(bboxPtr->max_y - bboxPtr->min_y) * (pointPtr->y);
}

double dinterpolateX(double scale_min, double scale_max, bbox * bboxPtr,point * pointPtr) {
    return (scale_max - scale_min) /(bboxPtr->max_x - bboxPtr->min_x) * (pointPtr->x);
}