#include <iostream>
#include "dynamicArray.hpp"
#include <vector>

int main()
{
    DynamicArray<int> arr{1,2,3,4,5};
    DynamicArray<int> arr2{ arr.begin(), arr.end()};
    std::cout<<arr<<'\n'<<arr2<<'\n';
    return 0;
}