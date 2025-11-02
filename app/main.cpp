#include <iostream>
#include "dynamicArray.hpp"
#include <vector>

int main()
{
    DynamicArray<int> arr{1,2,3,4,5,6,88,66};
    for(auto it{ arr.rbegin()}; it != arr.rend(); it++)
        std::cout<<*it<<" ";
    
    return 0;
}