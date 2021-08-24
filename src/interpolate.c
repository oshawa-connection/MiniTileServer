#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define NDEBUG






int main() {
    double scale_max = 255;
    double scale_min = 0;

    double bbox_max = 1;
    double bbox_min = 0;


    double your_value = 0.5;

    double halfValue = dinterpolate(scale_min,scale_max,bbox_min,bbox_max,your_value);

    printf("%f",halfValue);


    return 0;    
}