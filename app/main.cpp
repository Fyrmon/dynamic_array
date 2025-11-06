#include <iostream>
#include "dynamicArray.hpp"

int main()
{
    DynamicArray<int> arr{1,2,3,4,5,6};
    std::cout<<"Initial arr: \t Size: "<<arr.size() 
        <<"\t Cap: "<<arr.capacity()<<'\n' << arr <<'\n';

    arr.insert((arr.end()),5,99);
    std::cout<<"After insert: \t Size: "<<arr.size() 
        <<"\t Cap: "<<arr.capacity()<<'\n'<< arr <<'\n';

    return 0;
}