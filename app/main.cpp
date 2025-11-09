#include <iostream>
#include "dynamicArray.hpp"

int main()
{
    DynamicArray<int> arr{1,2,3,4,5,6};
    
    arr.push_back(12);
    arr.reserve(8);
    arr.push_back(33);
    std::cout<<arr<<'\n';
    return 0;
}