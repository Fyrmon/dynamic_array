#include <iostream>
#include "dynamicArray.hpp"

int main()
{
    DynamicArray<int> arr{1,2,3,4,5,6};
    const DynamicArray<int> new_arr{1,22,3};
    std::cout<<arr<<'\n';
    std::cout<<std::boolalpha;
    std::cout<< (arr==std::initializer_list{1,2,3,4,5,6}) <<'\n';
    return 0;
}