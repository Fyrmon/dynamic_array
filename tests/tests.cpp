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

TEST_F(DynamicArrayTest, Front)
{
    EXPECT_EQ(testArr.front(),1);
    testArr[0] = 13;
    EXPECT_EQ(testArr.front(),13);

    EXPECT_EQ(testArr2.front(),1);
}

TEST_F(DynamicArrayTest, Back)
{
    EXPECT_EQ(testArr.back(),3);
    testArr.back() = 64;
    EXPECT_EQ(testArr.back(),64);
    EXPECT_EQ(testArr2.back(),1);
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

TEST_F(DynamicArrayTest, EqualityOperator)
{
    EXPECT_TRUE((testArr == std::initializer_list{1,2,3}));
    EXPECT_TRUE((testArr2 == std::initializer_list{1}));

    EXPECT_FALSE((testArr == std::initializer_list{1,2,3,4,5}));
    EXPECT_FALSE((testArr2 == std::initializer_list{1,2,3}));

}

TEST_F(DynamicArrayTest, Empty)
{
    EXPECT_FALSE(testArr.empty());
    EXPECT_FALSE(testArr2.empty());

    testArr.shrink(0);
    EXPECT_TRUE(testArr.empty());

}

TEST_F(DynamicArrayTest, Reserve)
{
    testArr.reserve(10);
    EXPECT_EQ(testArr.size(),3);
    EXPECT_EQ(testArr.capacity(),10);
    EXPECT_TRUE((testArr == std::initializer_list{1,2,3}));

    testArr2.reserve(5);
    EXPECT_EQ(testArr2.size(),1);
    EXPECT_EQ(testArr2.capacity(),5);
    EXPECT_TRUE((testArr2 == std::initializer_list{1}));
}

TEST_F(DynamicArrayTest, ReserveWithSmallerCap)
{
    testArr.reserve(2);
    EXPECT_EQ(testArr.size(),3);
    EXPECT_EQ(testArr.capacity(),3);
    EXPECT_TRUE((testArr == std::initializer_list{1,2,3}));
}

TEST_F(DynamicArrayTest, Begin)
{
    EXPECT_EQ(*testArr.begin(),1);
    EXPECT_NE(*testArr.begin(),2);

    EXPECT_EQ(*testArr2.begin(), 1);

    EXPECT_EQ(*testArr.cbegin(),1);
    EXPECT_NE(*testArr.cbegin(),2);

    EXPECT_EQ(*testArr2.cbegin(), 1);
}

TEST_F(DynamicArrayTest, End)
{
    EXPECT_EQ(*(testArr.end()-1),3);
    EXPECT_EQ(*(testArr.cend()-1),3);

    testArr.shrink(2);

    EXPECT_EQ(*(testArr.end()-1),2);
    EXPECT_EQ(*(testArr.cend()-1),2);

    EXPECT_NE(*(testArr.end()-1),3);
    EXPECT_NE(*(testArr.cend()-1),3);

    EXPECT_EQ(*(testArr2.end()-1), 1);
    EXPECT_EQ(*(testArr2.cend()-1), 1);
}

TEST_F(DynamicArrayTest, Rbegin)
{
    EXPECT_EQ(*(testArr.rbegin()), *(testArr.end()-1));
    EXPECT_EQ(*(testArr.rbegin()), 3);
    EXPECT_EQ(*(testArr.rbegin()+1), 2);

    EXPECT_EQ(*(testArr2.rbegin()), *(testArr2.end()-1));
    EXPECT_EQ(*(testArr2.rbegin()), 1);
}

TEST_F(DynamicArrayTest, Crbegin)
{
    EXPECT_EQ(*(testArr.crbegin()), *(testArr.end()-1));
    EXPECT_EQ(*(testArr.crbegin()), 3);

    EXPECT_EQ(*(testArr2.crbegin()), *(testArr2.end()-1));
    EXPECT_EQ(*(testArr2.crbegin()), 1);
}

TEST_F(DynamicArrayTest, Rend)
{
    EXPECT_EQ(*(testArr.rend()-1), *testArr.begin());
    EXPECT_EQ(*(testArr.rend()-1),1);
    EXPECT_EQ(*(testArr.rend()-2),2);

    EXPECT_EQ(*(testArr2.rend()-1), *testArr2.begin());
    EXPECT_EQ(*(testArr2.rend()-1),1);
}

TEST_F(DynamicArrayTest, Crend)
{
    EXPECT_EQ(*(testArr.crend()-1),*(testArr.begin()));
    EXPECT_EQ(*(testArr.crend()-1), 1);

    EXPECT_EQ(*(testArr2.crend()-1),*(testArr2.begin()));
    EXPECT_EQ(*(testArr2.crend()-1), 1);
}