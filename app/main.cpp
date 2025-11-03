#include <iostream>
#include "dynamicArray.hpp"
#include <vector>

int main()
{
    DynamicArray<int> arr{1,2,3,4,5,6,88,66};
    std::cout<<"Capacity: "<< arr.capacity()<<'\n';
    std::cout<<"Size: "<< arr.size()<<'\n';

    for(auto it{ arr.rbegin()}; it != arr.rend(); it++)
        std::cout<<*it<<" ";
    std::cout<<'\n';

    std::cout<< "Shrink to fit()\n";
    arr.shrink(5);

    std::cout<<"Capacity: "<< arr.capacity()<<'\n';
    std::cout<<"Size: "<< arr.size()<<'\n';

    for(auto it{ arr.rbegin()}; it != arr.rend(); it++)
        std::cout<<*it<<" ";
    std::cout<<'\n';

    std::cout<< "Shrink to fit()\n";
    arr.shrink_to_fit();

    std::cout<<"Capacity: "<< arr.capacity()<<'\n';
    std::cout<<"Size: "<< arr.size()<<'\n';

    for(auto it{ arr.rbegin()}; it != arr.rend(); it++)
        std::cout<<*it<<" ";
    std::cout<<'\n';
    return 0;
}