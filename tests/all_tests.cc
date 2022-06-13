
#include <gtest/gtest.h>
#include "./hello_test.cc"
#include "./second_test.cc"
#include "./bbox_tests.cc"
#include "./color_tests.cc"

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
}