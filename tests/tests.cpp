#include <gtest/gtest.h>
#include <vector>
#include <list>
#include "dynamicArray.hpp"

 class DynamicArrayTest : public ::testing::Test
{
  protected:
    DynamicArray<int> testArr{1,2,3};
    DynamicArray<int> testArr2{1};

};

TEST_F(DynamicArrayTest, RangeConstructor)
{
    DynamicArray<int> range_arr{ testArr.begin(), testArr.end()};
    EXPECT_TRUE(range_arr==testArr);
    EXPECT_EQ(range_arr.size(),testArr.size());
    EXPECT_EQ(range_arr.capacity(),testArr.capacity());
}

TEST_F(DynamicArrayTest, MoveConstructor)
{
    DynamicArray<int> mv_arr{ std::move(testArr) };
    EXPECT_TRUE(mv_arr==(std::initializer_list{1,2,3}));
    EXPECT_TRUE(testArr.empty());

    DynamicArray<int> mv_arr2{ std::move(testArr2)};
    EXPECT_TRUE(mv_arr2==(std::initializer_list{1}));
    EXPECT_TRUE(testArr2.empty());
}

TEST_F(DynamicArrayTest, SizeValueConstructor)
{
    DynamicArray<int> arr_with_size_val(5,1);
    EXPECT_TRUE(arr_with_size_val==(std::initializer_list{1,1,1,1,1}));
}

TEST_F(DynamicArrayTest, SizeConstructor)
{
    DynamicArray<int> arr_with_size(5);
    EXPECT_EQ(arr_with_size.size(), 5);
    EXPECT_TRUE(arr_with_size==(std::initializer_list{0,0,0,0,0}));
    EXPECT_FALSE(arr_with_size==(std::initializer_list{0,0,0}));
}

TEST_F(DynamicArrayTest, CopyConstructor)
{
    DynamicArray<int> copy_arr{ testArr };
    EXPECT_TRUE(copy_arr==testArr);
    EXPECT_EQ(copy_arr.size(), testArr.size());
}

TEST_F(DynamicArrayTest, Assign)
{
    testArr.assign(5,6);
    EXPECT_TRUE(testArr==(std::initializer_list{6,6,6,6,6}));

    testArr.assign(3,3);
    EXPECT_TRUE(testArr==(std::initializer_list{3,3,3}));
}

TEST_F(DynamicArrayTest, AssignRange)
{
    std::vector<int> vec{ 99,98,97,96 };
    testArr.assign_range(vec);
    // untill there is a comparison function for std::containers
    EXPECT_TRUE(testArr == (std::initializer_list{99,98,97,96}));
    EXPECT_EQ( testArr.size(), vec.size() );

    std::list<int> list{ 1,2,18 };
    testArr2.assign_range(list);
    EXPECT_TRUE(testArr2 == (std::initializer_list{1,2,18}));
    EXPECT_EQ( testArr2.size(), list.size() );
}

TEST_F(DynamicArrayTest, AssignRangeIt)
{
    std::vector<int> vec{ 99,98,97,96 };
    testArr.assign_range(vec.begin(), vec.end());
    
    EXPECT_TRUE(testArr == (std::initializer_list{99,98,97,96}));
    EXPECT_EQ( testArr.size(), vec.size() );

    std::list<int> list{ 1,2,18 };
    testArr2.assign_range(list.begin(), list.end());
    EXPECT_TRUE(testArr2 == (std::initializer_list{1,2,18}));
    EXPECT_EQ( testArr2.size(), list.size() );
}

TEST_F(DynamicArrayTest, IteratorAssign)
{
    DynamicArray<int> it_assign{0,0};
    it_assign.assign(testArr.begin(), testArr.end());
    EXPECT_TRUE(it_assign==testArr);

    it_assign.assign(testArr2.begin(), testArr2.end());
    EXPECT_TRUE(it_assign==testArr2);
}

TEST_F(DynamicArrayTest, InitListAssign)
{
    DynamicArray<int> arr{0,0};
    arr.assign({1,2,3,4,5,6,6});
    EXPECT_TRUE(arr==(std::initializer_list{1,2,3,4,5,6,6}));
    EXPECT_EQ(arr.size(),7);
    EXPECT_EQ(arr.capacity(),7);
}

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

TEST_F(DynamicArrayTest, Data)
{
    EXPECT_EQ(testArr.data()[0], testArr.front());
    EXPECT_EQ(testArr.data()[testArr.size()-1], testArr.back());
    
    EXPECT_EQ(testArr2.data()[0], testArr.front());
}

TEST_F(DynamicArrayTest, Empty)
{
    EXPECT_FALSE(testArr.empty());
    EXPECT_FALSE(testArr2.empty());

    testArr.shrink(0);
    EXPECT_TRUE(testArr.empty());

}

TEST_F(DynamicArrayTest ,Size)
{
    EXPECT_EQ(testArr.size(),3);
    EXPECT_EQ(testArr2.size(),1);
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

TEST_F(DynamicArrayTest, ShrinkToFit)
{
    testArr.shrink(2);
    EXPECT_EQ(testArr.size(),2);
    EXPECT_EQ(testArr.capacity(),3);

    testArr.shrink_to_fit();
    EXPECT_EQ(testArr.size(),2);
    EXPECT_EQ(testArr.capacity(),2);
    EXPECT_TRUE((testArr == std::initializer_list{1,2}));
}

TEST_F(DynamicArrayTest, Clear)
{
    testArr.clear();
    EXPECT_EQ(testArr.size(), 0);
    EXPECT_EQ(testArr.capacity(), 3);

    DynamicArray<std::string> str{"Abc","defg"};
    EXPECT_EQ(str.size(), 2);
    str.clear();
    EXPECT_EQ(str.size(),0);
}

TEST_F(DynamicArrayTest, Insert)
{
    testArr.insert(testArr.begin(), 99);
    EXPECT_EQ(*testArr.begin(), 99);

    testArr.insert(testArr.end(), 88);
    EXPECT_EQ(*(testArr.end()-1), 88);

    testArr.insert(testArr.begin()+2,66);
    EXPECT_EQ(testArr[2], 66);

    EXPECT_EQ(testArr.size(), 6);
    EXPECT_EQ(testArr.size(), testArr.capacity());
}

TEST_F(DynamicArrayTest, InsertWithCount)
{
    testArr.insert(testArr.end(),3,99);
    EXPECT_EQ(testArr,(std::initializer_list{1,2,3,99,99,99}));

    testArr.insert(testArr.begin(),2,11);
    EXPECT_EQ(testArr,(std::initializer_list{11,11,1,2,3,99,99,99}));

    testArr.insert((std::next(testArr.begin(),2)) ,2,0);
    EXPECT_EQ(testArr,(std::initializer_list{11,11,0,0,1,2,3,99,99,99}));

    EXPECT_EQ(testArr.size(),10);
    EXPECT_EQ(testArr.size(), testArr.capacity());
}

TEST_F(DynamicArrayTest, InsertWithInitList)
{
    testArr.insert(testArr.begin(),{99,88,77});
    EXPECT_EQ(testArr,(std::initializer_list{99,88,77,1,2,3}));

    EXPECT_EQ(testArr.size(),6);
    EXPECT_EQ(testArr.size(), testArr.capacity());

    testArr2.insert(testArr2.end(),{2,3,4});
    EXPECT_EQ(testArr2,(std::initializer_list{1,2,3,4}));

    EXPECT_EQ(testArr2.size(),4);
    EXPECT_EQ(testArr2.size(), testArr2.capacity());
}

TEST_F(DynamicArrayTest, InsertWithPosBeginEnd)
{
    DynamicArray<int> arr{10,12,14,16};
    testArr.insert(2,arr.begin(),arr.end());
    EXPECT_TRUE((testArr == std::initializer_list{1,2,10,12,14,16,3}));

    testArr2.insert(1,arr.begin(),arr.end());
    EXPECT_TRUE((testArr2 == std::initializer_list{1,10,12,14,16}));
}

TEST_F(DynamicArrayTest, PushBack)
{
    size_t old_size{ testArr.size()};
    size_t old_capacity{testArr.capacity()};

    testArr.push_back(55);
    EXPECT_TRUE((testArr == std::initializer_list{1,2,3,55}));
    EXPECT_NE(old_size, testArr.size());
    EXPECT_NE(old_capacity, testArr.capacity());
    EXPECT_EQ(testArr.size(),4);
    EXPECT_EQ(testArr.capacity(),4);

}

TEST_F(DynamicArrayTest, PopBack)
{
    testArr.pop_back();
    EXPECT_TRUE((testArr == std::initializer_list{1,2}));
    EXPECT_EQ(testArr.size(), 2);

    testArr2.pop_back();
    EXPECT_EQ(testArr2.size(), 0);
    testArr2.pop_back();
    EXPECT_EQ(testArr2.size(), 0);
}

TEST_F(DynamicArrayTest, Swap)
{
    testArr.swap(testArr2);
    EXPECT_TRUE((testArr == std::initializer_list{1}));
    EXPECT_EQ(testArr.size(), 1);
    EXPECT_EQ(testArr.capacity(), 1);

    EXPECT_TRUE((testArr2 == std::initializer_list{1,2,3}));
    EXPECT_EQ(testArr2.size(), 3);
    EXPECT_EQ(testArr2.capacity(), 3);
}

TEST_F(DynamicArrayTest, AppendRange)
{
    std::vector<int> vec{4,5,6};
    testArr.append_range(vec);
    EXPECT_TRUE((testArr == std::initializer_list{1,2,3,4,5,6}));
    EXPECT_EQ(testArr.size(), 6);
    EXPECT_EQ(testArr.capacity(), 6);
}

TEST_F(DynamicArrayTest, EqualityOperator)
{
    EXPECT_TRUE((testArr == std::initializer_list{1,2,3}));
    EXPECT_TRUE((testArr2 == std::initializer_list{1}));

    EXPECT_FALSE((testArr == std::initializer_list{1,2,3,4,5}));
    EXPECT_FALSE((testArr2 == std::initializer_list{1,2,3}));

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
    EXPECT_EQ(*(testArr.rbegin()), (*std::prev(testArr.end(),1)));
    EXPECT_EQ(*(testArr.rbegin()), 3);
    EXPECT_EQ(*(std::next(testArr.rbegin(),1)), 2);

    EXPECT_EQ(*(testArr2.rbegin()), (*std::prev(testArr2.end(),1)));
    EXPECT_EQ(*(testArr2.rbegin()), 1);
}

TEST_F(DynamicArrayTest, Crbegin)
{
    EXPECT_EQ(*(testArr.crbegin()), *std::prev(testArr.end(),1));
    EXPECT_EQ(*(testArr.crbegin()), 3);

    EXPECT_EQ(*(testArr2.crbegin()), *std::prev(testArr2.end(),1));
    EXPECT_EQ(*(testArr2.crbegin()), 1);
}

TEST_F(DynamicArrayTest, Rend)
{
    EXPECT_EQ(*std::prev(testArr.rend(),1), *testArr.begin());
    EXPECT_EQ(*std::prev(testArr.rend(),1),1);
    EXPECT_EQ(*std::prev(testArr.rend(),2),2);

    EXPECT_EQ(*std::prev(testArr2.rend(),1), *testArr2.begin());
    EXPECT_EQ(*std::prev(testArr2.rend(),1),1);
}

TEST_F(DynamicArrayTest, Crend)
{
    EXPECT_EQ(*(testArr.crend()-1),*(testArr.begin()));
    EXPECT_EQ(*(testArr.crend()-1), 1);

    EXPECT_EQ(*(testArr2.crend()-1),*(testArr2.begin()));
    EXPECT_EQ(*(testArr2.crend()-1), 1);
}