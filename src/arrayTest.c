#include <stdio.h>

typedef struct point {
    double x;
    double y;
} point;

typedef struct pointCollection {
    point * thePoints;
} pointCollection;

int main() {
    point myPoint = {2,3};
    point myOtherPoint = {5,6};
    point myPoints[] = {myPoint,myOtherPoint};
    pointCollection myCollection = {myPoints};
    
    // int myarray[] = {2,3,4,5};
    // printf("%d\n",myarray[1]);
    printf("%f\n",myCollection.thePoints[0].x);
    return 0;
}