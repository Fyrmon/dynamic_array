#ifndef DYNAMICARRAY_HPP
#define DYNAMICARRAY_HPP
#include <initializer_list>
#include <iterator>

template<typename T>
class DynamicArray
{
public:
    using type_name = T;
    using size_type = std::size_t;
    using iterator = type_name*;
    using const_iterator = const iterator;
    using reverse_iterator = std::reverse_iterator<iterator>;
private:
    type_name* m_arr{ nullptr };
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

    // ELEMENT ACCESS

    type_name& at(int i) 
    {
        if(m_size <= i || 0 > i)
            throw std::out_of_range("at(i) wrong index");
        
        return m_arr[i];
    }

    const type_name& at(int i) const
    {
        if(m_size <= i || 0 > i)
            throw std::out_of_range("at(i) wrong index");
        
        return m_arr[i];
    }

    type_name& operator[](int i)
    {
        return m_arr[i];
    }

    const type_name& operator[](int i) const
    {
        return m_arr[i];
    }

    type_name& front()
    {
        return m_arr[0];
    }

    const type_name& front() const noexcept
    {
        return m_arr[0];
    }

    size_type size() const noexcept
    { 
        return m_size; 
    }

    size_type capacity() const noexcept 
    { 
        return m_capacity;
    }

    bool empty() const noexcept
    {
        return m_size == 0;
    }

    void shrink(int new_size)
    { 
        m_size = m_size < new_size ? m_size: new_size; 
    }

    void reserve(int new_cap)
    {
        if(new_cap > m_capacity)
        {
            type_name* new_arr = new type_name [new_cap]{0};
            m_capacity = new_cap;
            for(size_type i {0}; i < m_size; ++i)
                new_arr[i] = m_arr[i];

            delete[] m_arr;
            m_arr = new_arr;
        }
    }

    // ITERATORS
    iterator begin() const
    { 
        return m_arr; 
    }

    const_iterator cbegin() const
    { 
        return m_arr; 
    }

    reverse_iterator rbegin() const
    {
        return reverse_iterator(end());
    }

    const reverse_iterator crbegin() const
    {
        return reverse_iterator(end());
    }

    iterator end() const
    { 
        return m_arr+m_size; 
    }

    const_iterator cend() const
    { 
        return m_arr+m_size; 
    }

    reverse_iterator rend() const
    { 
        return reverse_iterator(begin()); 
    }

    const reverse_iterator crend() const
    {
        return reverse_iterator(begin());
    }

    // OPERATOR OVERLOADS
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