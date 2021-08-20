#include "../headers/bbox.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

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