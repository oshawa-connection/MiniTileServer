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

pointCollection * create_point_collection();

void destroy_point_collection();

void add_point_to_collection(pointCollection * pointCollection, point * point);


point * get_point_from_collection(pointCollection * collection, int index);