#include <gtest/gtest.h>
#include "dynamicArray.hpp"

 class DynamicArrayTest : public ::testing::Test
{
  protected:
    DynamicArray<int> testArr{1,2,3};
    DynamicArray<int> testArr2{1};

};

TEST_F(DynamicArrayTest ,ConstructingWithSize)
{
    EXPECT_EQ(testArr.size(),3);

    EXPECT_EQ(testArr2.size(),1);
}

TEST_F(DynamicArrayTest, Shrink)
{
    testArr.shrink(1);
}