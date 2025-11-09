#include <iostream>
#include "dynamicArray.hpp"

int main()
{
    DynamicArray<int> arr{1,2,3,4,5,6};
    
    arr.pop_back();
    std::cout<<arr<<'\n';
    return 0;
}