#pragma once
#include "point.h"
#include <stdbool.h>

typedef struct bbox
{
    double min_x;
    double max_x;
    double min_y;
    double max_y;
} bbox;


bbox * create_bbox_ptr(double min_x, double max_x, double min_y, double max_y);

void destroy_bbox_ptr();


bool bbox_contains_point(bbox * bboxPtr, point * point);


void create_bbox_ptr_from_string_regex(char * bboxString);


bbox * create_bbox_ptr_from_string(char * bboxString);

double dinterpolateY(double scale_min, double scale_max, bbox * bboxPtr,point * pointPtr);

double dinterpolateX(double scale_min, double scale_max, bbox * bboxPtr,point * pointPtr);