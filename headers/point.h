#pragma once
#include<stdio.h>


typedef struct point {
    double x;
    double y;
} point;


typedef struct pointCollection {
    point ** points;
    long numberOfPoints;
} pointCollection; 

point * create_new_point(double x, double y);

void destroy_point(point * pointToDestroy);
