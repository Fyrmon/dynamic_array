#include <gtest/gtest.h>
#include "dynamicArray.hpp"

TEST(DynaicArrTest ,ConstructingWithSize)
{
    DynamicArray<int> test(3);
    EXPECT_EQ(test.size(),3);

    DynamicArray<int> test2(0);
    EXPECT_EQ(test2.size(),1);
}