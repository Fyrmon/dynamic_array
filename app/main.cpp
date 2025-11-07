#include <iostream>
#include "dynamicArray.hpp"

int main()
{
    DynamicArray<int> arr{1,2,3,4,5,6};
    std::cout<<"Initial arr: \t Size: "<<arr.size() 
        <<"\t Cap: "<<arr.capacity()<<'\n' << arr <<'\n';

    DynamicArray<int> arr2{10,11,12,13};
    arr.insert(1, arr2.begin(), std::prev(arr2.end(),2) );
    std::cout<<"After insert: \t Size: "<<arr.size() 
        <<"\t Cap: "<<arr.capacity()<<'\n'<< arr <<'\n';

    return 0;
}