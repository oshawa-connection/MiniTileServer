#include "../headers/bbox.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

double calculate_bbox_area(bbox * bboxPtr) {
    double delta_x = bboxPtr->max_x - bboxPtr->min_x;
    double delta_y = bboxPtr->max_y - bboxPtr->min_y;
    return delta_x * delta_y;
}

char * parse_double() {
    //do not forget to free
}


bbox * create_bbox_ptr_from_string(char * bboxString) {
    // -15028131.257091932%2C5009377.085697312%2C-12523442.714243276%2C7514065.628545968
    // strtod()
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


