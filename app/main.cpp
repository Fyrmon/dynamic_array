#include <iostream>
#include "dynamicArray.hpp"
#include <vector>

int main()
{
    DynamicArray<int> arr(5,1);
    std::cout<<arr<<'\n';
    return 0;
}