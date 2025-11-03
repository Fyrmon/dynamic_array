#include <iostream>
#include "dynamicArray.hpp"
#include <vector>

int main()
{
    DynamicArray<int> arr{1,2,3,4,5,6,88,66};
    std::cout<<"Capacity: "<< arr.capacity()<<'\n';
    std::cout<<"Size: "<< arr.size()<<'\n';
    return 0;
}