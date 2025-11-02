#include <iostream>
#include "dynamicArray.hpp"
#include <vector>

int main()
{
    DynamicArray<int> arr{1,2,3,4,5,6};
    for(auto it{ arr.begin()}; it != arr.end(); ++it)
        std::cout<<*it<<'\n';
    
    return 0;
}