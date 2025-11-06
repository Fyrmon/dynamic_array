#include <iostream>
#include "dynamicArray.hpp"
#include <string>
int main()
{
    DynamicArray<int> arr{1,2};
    DynamicArray<std::string> strings{ "1,23,4", "abc"};
    std::cout<<strings<<'\n';
    strings.clear();
    std::cout<<"Size: "<<strings.size()<<"\tCapacity"
            <<strings.capacity()<<'\n';
    return 0;
}