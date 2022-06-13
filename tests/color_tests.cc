#include <gtest/gtest.h>
#include "../src/color.c"

// Demonstrate some basic assertions.
TEST(ColorTest, AssertBasicParses) {
    const char * black = "0,0,0";
    color * result = parseColorString((char * )black);
    EXPECT_EQ(result->red,0);
    EXPECT_EQ(result->green,0);
    EXPECT_EQ(result->blue,0);
}


// Demonstrate some basic assertions.
TEST(ColorTest, AssertMoreBasicParses) {
    const char * black = "255,255,0";
    color * result = parseColorString((char * )black);
    EXPECT_EQ(result->red,255);
    EXPECT_EQ(result->green,255);
    EXPECT_EQ(result->blue,0);
}