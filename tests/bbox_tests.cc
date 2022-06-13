#include <gtest/gtest.h>
#include "../src/bbox.c"

// Demonstrate some basic assertions.
TEST(BBoxTest, Creates) {
    const char * myString ="-15028131.257091932%2C5009377.085697312%2C-12523442.714243276%2C7514065.628545968";
    bbox * testBBox = create_bbox_ptr_from_string((char *)myString);
    
    EXPECT_EQ(testBBox->min_x,-15028131.2570);
    EXPECT_FLOAT_EQ(testBBox->min_x,-15028131.257091932);
}