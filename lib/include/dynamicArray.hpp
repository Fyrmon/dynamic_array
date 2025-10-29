#ifndef DYNAMICARRAY_HPP
#define DYNAMICARRAY_HPP

template<typename T>
class DynamicArray
{
public:
    using type_name = T;
    using size_type = std::size_t;
private:
    T* m_arr{ nullptr };
    size_type m_size{};
public:

    DynamicArray() = delete;
    DynamicArray(int size)
    {
        m_size = size ? size : 1;
        m_arr = new type_name [m_size];
    }

    size_type size(){ return m_size; }

    ~DynamicArray()
    {
        delete[] m_arr;
    }

};

#endif