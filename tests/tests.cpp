#include <gtest/gtest.h>
#include "dynamicArray.hpp"

TEST(DynaicArrTest ,ConstructingWithSize)
{
    DynamicArray<int> d{3};
    EXPECT_EQ(d.size(),3);
}