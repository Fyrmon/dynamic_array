#include <iostream>
#include "dynamicArray.hpp"
#include <vector>

int main()
{
    DynamicArray<int> arr{1,2,3,8,12};
    DynamicArray<int> arr2{1,2};
    arr2.assign(arr.begin(), arr.end());
    std::cout<<arr2<<'\n';
    
    return 0;
}