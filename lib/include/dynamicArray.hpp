#ifndef DYNAMICARRAY_HPP
#define DYNAMICARRAY_HPP

template<typename T>
class DynamicArray
{
private:
    T* m_arr{ nullptr };
public:

    using type_name = T;

    DynamicArray() = delete;
    DynamicArray(int size)
    {
        m_arr = new type_name [size ? size:1];
    }

    ~DynamicArray()
    {
        delete[] m_arr;
    }

};

#endif