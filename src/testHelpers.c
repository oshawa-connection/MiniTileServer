#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

void iAssertEqual(int expected, int actual, char * message) {
    if (!(expected == actual)) {
        printf("Assertation failed: %s; Expected %d to equal %d.\n",message,expected, actual);
    }
}

void fAssertEqual(float expected, float actual, float tolerance, char * message) {
    float difference = fabsf(expected - actual);
    
    if (!(difference < tolerance)) {
        printf("Assertation failed: %s; Expected %f to equal %f.\n",message,expected, actual);
    }
}


void dAssertEqual(double expected, double actual, double tolerance, char * message) {
    double difference = fabs(expected - actual);
    if (!(difference < tolerance)) {
        printf("Assertation failed: %s; Expected %f to equal %f \n",message,expected,actual);
    }
}

void AssertTrue(bool value) {
    if (!value) {
        printf("Assertation failed. Expected true but got false\n");
    }
}