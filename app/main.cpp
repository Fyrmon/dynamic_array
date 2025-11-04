#include <iostream>
#include "dynamicArray.hpp"
#include <vector>

int main()
{
    DynamicArray<int> arr{1,2,3,4,5,6,88,66};
    DynamicArray<int> second{arr};
    std::cout<<second<<'\n';
    return 0;
}