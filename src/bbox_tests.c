#include "../headers/bbox.h"
#include "../headers/testHelpers.h"
#include "assert.h"

void myTestFunction() {
    char * myString ="-15028131.257091932%2C5009377.085697312%2C-12523442.714243276%2C7514065.628545968";
    bbox * testBBox = create_bbox_ptr_from_string(myString);
    // assert(("something",2 + 2 ==4));    
}

