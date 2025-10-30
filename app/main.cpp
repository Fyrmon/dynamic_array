#include <iostream>
#include "dynamicArray.hpp"
#include <vector>

int main()
{
    DynamicArray<int> arr{1,2,3,4,5,6};
    // DynamicArray<int> a(5,3);
    // std::cout<< a<< '\n';
    std::cout<<arr<<'\n';
    arr.shrink(3);
    std::cout<<arr<<'\n';
    std::cout<<arr.capacity()<<'\n';
    
    return 0;
}