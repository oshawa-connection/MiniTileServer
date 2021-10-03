#include <stdbool.h>

void iAssertEqual(int expected, int actual, char * message);

void fAssertEqual(float expected, float actual, float tolerance, char * message);


void dAssertEqual(double expected, double actual, double tolerance, char * message);

void AssertTrue(bool value);