#include <gtest/gtest.h>
#include "dynamicArray.hpp"

 class DynamicArrayTest : public ::testing::Test
{
  protected:
    DynamicArray<int> testArr{1,2,3};
    DynamicArray<int> testArr2{1};

};

TEST_F(DynamicArrayTest, Indexing)
{
    EXPECT_EQ(testArr[1],2);
    EXPECT_EQ(testArr2[0],1);
}

TEST_F(DynamicArrayTest, At)
{
    EXPECT_EQ(testArr.at(1),2);
    EXPECT_EQ(testArr2.at(0),1);
}

TEST_F(DynamicArrayTest ,Size)
{
    EXPECT_EQ(testArr.size(),3);
    EXPECT_EQ(testArr2.size(),1);
}


TEST_F(DynamicArrayTest, Capacity)
{
    EXPECT_EQ(testArr.capacity(), 3);
    EXPECT_EQ(testArr2.capacity(),1);
    testArr.shrink(2);
    EXPECT_EQ(testArr.capacity(), 3);
}

TEST_F(DynamicArrayTest, Shrink)
{
    EXPECT_EQ(testArr.capacity(), 3);
    testArr.shrink(1);
    EXPECT_EQ(testArr.size(),1);
    EXPECT_EQ(testArr.capacity(),3);
}