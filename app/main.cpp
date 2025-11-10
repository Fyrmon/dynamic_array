#include <iostream>
#include "dynamicArray.hpp"

int main()
{
    DynamicArray<int> arr{1,2,3,4,5,6};
    DynamicArray<int> arr2{7,8,9};

    
    arr.swap(arr2);
    std::cout<<"Arr:"<<arr<<"\nWith cap: "<<arr.capacity()<<" and size: "<<arr.size()<<'\n';
    std::cout<<"Arr2:"<<arr2<<"\nWith cap: "<<arr2.capacity()<<" and size: "<<arr2.size()<<'\n';
    return 0;
}