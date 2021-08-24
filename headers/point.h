#pragma once

typedef struct point {
    double x;
    double y;
} point;


typedef struct pointCollection {
    point * points;
    long numberOfPoints;
} pointCollection; 
