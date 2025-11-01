#ifndef DYNAMICARRAY_HPP
#define DYNAMICARRAY_HPP
#include <initializer_list>

template<typename T>
class DynamicArray
{
public:
    using type_name = T;
    using size_type = std::size_t;
private:
    T* m_arr{ nullptr };
    size_type m_size{};
    size_type m_capacity{};
public:

    DynamicArray() = delete;
    // to do: Add others constructor...move,copy...
    DynamicArray(int size)
    : m_size{ (size > 0) ? size_type(size) : 1ul}
    , m_capacity{ m_size }
    {
        m_arr = new type_name [m_size];
    }

    DynamicArray(std::initializer_list<T> list)
    : m_size{ list.size() }
    , m_capacity{ m_size }
    {
        m_arr = new type_name[m_size];
        size_type i{0};
        for(auto it{ list.begin()}; it!=list.end(); ++it)
        {
            m_arr[i] = *it;
            ++i;
        }

    }

    DynamicArray(int size, const T value)
    : m_size{ size_type(size) }
    , m_capacity{ m_size }
    {
        m_arr = new type_name[m_size]{value};
    }

    
    ~DynamicArray()
    {
        delete[] m_arr;
    }


    const type_name& operator[](int i) const { return m_arr[i];}
    type_name operator[](int i){ return m_arr[i];}

    const type_name& at(int i) const
    {
        if(m_size <= i || 0 > i)
            throw std::out_of_range("at(i) wrong index");
        
        return m_arr[i];
    }

    type_name& at(int i) 
    {
        if(m_size <= i || 0 > i)
            throw std::out_of_range("at(i) wrong index");
        
        return m_arr[i];
    }

    size_type size() const noexcept
    { return m_size; }
    size_type capacity() const noexcept 
    { return m_capacity;}

    bool empty() const noexcept
    {
        return m_size == 0;
    }

    void shrink(int new_size)
    { 
        m_size = m_size < new_size ? m_size: new_size; 
    }

    friend bool operator==(const DynamicArray<T>& arr, const std::initializer_list<T>& list)
    {
        if( arr.size() != list.size() ) 
            return false;
        
        DynamicArray::size_type i { 0 };
        for(auto it{ list.begin()}; it != list.end(); ++it)
        {
            if(arr[i++] != (*it))
                return false;
        }

        return true;
    }

    friend std::ostream& operator<<(std::ostream& out, const DynamicArray<T>& arr)
    {
        for(int i{0}; i < arr.size(); ++i)
            out<<arr[i]<<' ';
        
        return out;
    }
};

#endif