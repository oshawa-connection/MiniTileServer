#include "../headers/point.h"
#include <stdlib.h>
#include <stdio.h>

point * create_new_point(double x, double y) {
    point * my_point = (point *) malloc(sizeof(point));
    my_point->x=x;
    my_point->y=y;
    return my_point;
}

void destroy_point(point * pointToDestroy) {

}

pointCollection * create_point_collection() {
    pointCollection * new_point_collection = (pointCollection *) malloc(sizeof(pointCollection));
    point ** points = (point **) malloc(sizeof(point) * 100);
    new_point_collection->points = points;
    new_point_collection->numberOfPoints=0;
    return new_point_collection;
}

void destroy_point_collection() {

}

void add_point_to_collection(pointCollection * collection, point * point) {
    if (collection->numberOfPoints == 100) {
        fprintf(stderr,"Exceeded test data size limits of 100");
        exit(1);
    }
    collection->points[collection->numberOfPoints] = point;
    collection->numberOfPoints +=1;
}


point * get_point_from_collection(pointCollection * collection, int index) {
    if (index > collection->numberOfPoints-1) {
        fprintf(stderr,"You went over (%d) the size of the collection (%ld)",index,collection->numberOfPoints);
        exit(1);
    }
    return collection->points[index];
}