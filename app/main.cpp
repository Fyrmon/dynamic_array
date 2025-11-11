#include <iostream>
#include "dynamicArray.hpp"
#include <vector>

int main()
{
    DynamicArray<int> arr{1,2,3,4,5,6};
    arr.reserve(28);
    std::vector<int> arr2{7,8,9};

    
    std::cout<<"Arr:"<<arr<<"\nWith cap: "<<arr.capacity()<<" and size: "<<arr.size()<<'\n';
    arr.append_range(arr2);
    std::cout<<"Arr after append:\t"<<arr<<"\nWith cap: "<<arr.capacity()
            <<" and size: "<<arr.size()<<'\n';
    return 0;
}