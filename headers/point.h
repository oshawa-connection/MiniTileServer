#pragma once

typedef struct point {
    double x;
    double y;
} point;


typedef struct pointCollection {
    point * points;
    long numberOfPoints;
} pointCollection; 


void test() {
    point something = {2,3};
    point  points[] = {something};
    pointCollection myCollection = {points,2};
    // myCollection.points.
    
}