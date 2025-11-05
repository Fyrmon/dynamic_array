#include <iostream>
#include "dynamicArray.hpp"
#include <vector>

int main()
{
    DynamicArray<int> arr{1,2,3,4,5};
    arr.assign(15,3);
    std::cout<<arr<<'\n';
    return 0;
}