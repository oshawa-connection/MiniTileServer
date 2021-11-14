#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(ByeTest, BasicAssertionstwo) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
} 



// Demonstrate some basic assertions.
TEST(ByeTest, SomeOtherAssertation) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "hello");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
} 