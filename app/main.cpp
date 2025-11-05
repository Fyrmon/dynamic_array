#include <iostream>
#include "dynamicArray.hpp"
#include <vector>
#include <list>

int main()
{
    std::list<int> a{1,2,3,4};
    std::vector<int> b{234,234234,4234,555};
    DynamicArray<int> arr2{1,2};
    arr2.assign_range(a);
    std::cout<<arr2<<'\n';

    arr2.assign_range(b.begin(), b.end());
    std::cout<<arr2<<'\n';    
    return 0;
}