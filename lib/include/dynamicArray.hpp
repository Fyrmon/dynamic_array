#ifndef DYNAMICARRAY_HPP
#define DYNAMICARRAY_HPP
#include <algorithm>
#include <initializer_list>
#include <iterator>
#include <limits>
#include <ranges>

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
    DynamicArray(size_type size)
    : m_size{ size}
    , m_capacity{ m_size }
    {
        m_arr = new type_name [m_size]{};
    }

    DynamicArray(std::initializer_list<T> list)
    : DynamicArray(list.size())
    {
        std::copy(list.begin(), list.end(), m_arr);
    }

    DynamicArray(int size, const T value)
    : m_size{ size_type(size) }
    , m_capacity{ m_size }
    {
        m_arr = new type_name[m_size];
        std::fill(begin(),end(), value);
    }

    DynamicArray(const DynamicArray& other)
    :DynamicArray(other.size())
    {
        for(size_type i{ 0 }; i < m_size; ++i)
            m_arr[i] = other[i];
    }

    DynamicArray(DynamicArray&& other) noexcept
    : m_arr{other.m_arr}
    , m_size{other.m_size}
    , m_capacity{other.m_capacity}

    {
        other.m_arr=nullptr;
        other.m_size=0;
        other.m_capacity=0;
    }
    
    DynamicArray(iterator start, iterator finish)
    {
        deepCopy(start,finish);
    }
    
    ~DynamicArray()
    {
        delete[] m_arr;
    }

    void assign(size_type size, type_name value)
    {
        if(size <= 0 )
            return;
        
        m_size = size;
        m_capacity = m_size;
        delete[] m_arr;
        m_arr = new type_name[m_size]{};
        
        std::fill(begin(), end(), value);
    }

    void assign(iterator start, iterator finish)
    {
        deepCopy(start,finish);
    }

    void assign(std::initializer_list<type_name> list)
    {
        deepCopy(list.begin(), list.end());
    }

    template<std::ranges::input_range Range>
    void assign_range(Range&& source_range)
    {
        auto start{ std::ranges::begin(source_range)};
        auto finish{ std::ranges::end(source_range)};

        auto new_size = std::ranges::distance(start,finish);

        if(new_size > 0 )
        {
            m_size = new_size;
            m_capacity = new_size;
            
            delete[] m_arr;
            m_arr = new type_name[m_size]{};

            std::copy(start,finish,m_arr);
        }
    }

    template<typename SourceIt>
    void assign_range(SourceIt first, SourceIt last)
    {
        deepCopy(first,last);
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

    type_name& front() noexcept
    {
        return m_arr[0];
    }

    const type_name& front() const noexcept
    {
        return m_arr[0];
    }

    type_name& back() noexcept
    {
        return m_arr[m_size-1];
    }

    const type_name& back() const noexcept
    {
        return m_arr[m_size-1];
    }

    type_name* data()
    {
        return m_arr;
    }

    const type_name* data() const
    {
        return m_arr;
    }

    // CAPACITY 

    bool empty() const noexcept
    {
        return m_size == 0;
    }

    size_type size() const noexcept
    { 
        return m_size; 
    }

    const size_type max_size() const noexcept
    {
        // not really true as the docs say that at runtime 
        // it might be smaller due to amount of RAM
        return std::numeric_limits<size_type>::max() / sizeof(type_name);
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

    size_type capacity() const noexcept 
    { 
        return m_capacity;
    }

    void shrink(int new_size)
    { 
        m_size = m_size < new_size ? m_size: new_size; 
    }

    void shrink_to_fit()
    {
        if(m_capacity > m_size)
        {
            m_capacity = m_size;
            auto* new_arr{ new type_name[m_size] };
            for( size_type i{ 0ul }; i < m_size; i++)
                new_arr[i] = m_arr[i];
            
            delete[] m_arr;
            m_arr = new_arr;
        }
    }

    // MODIFIERS

    void clear()
    {
        for(size_type i { 0 }; i < m_size; i++)
            m_arr[i].~type_name();
        m_size = 0;
    }

    void insert(const_iterator pos, const type_name& val)
    {
        size_type new_size = m_size+1;
        size_type new_cap = new_size;
        type_name* new_arr{ new type_name[new_size]};

        const size_type target_i = std::distance(begin(),pos);

        for(size_t i{ 0 }; i < target_i; ++i)
            new_arr[i] = m_arr[i];
        
        new_arr[target_i] = val;

        for(size_t i{ target_i }; i< size(); i++)
            new_arr[i+1] = m_arr[i];

        delete[] m_arr;
        m_arr = new_arr;
        m_size = new_size;
        m_capacity = new_cap;
    }

    void insert(const_iterator pos, size_type count,  const type_name& val)
    {
        size_type new_size = m_size+count;
        size_type new_cap = new_size;
        type_name* new_arr{ new type_name[new_size]};

        const size_type target_i = std::distance(begin(),pos);

        for(size_t i{ 0 }; i < target_i; ++i)
            new_arr[i] = m_arr[i];
        
        for(size_type i{1}; i<=count; ++i )
            new_arr[target_i +(i-1)] = val;

        for(size_t i{ target_i }; i< size(); i++)
            new_arr[i+count] = m_arr[i];

        delete[] m_arr;
        m_arr = new_arr;
        m_size = new_size;
        m_capacity = new_cap;
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
   bool operator==(const DynamicArray<T>& other) const
    {
        if( size() != other.size() ) 
            return false;
        
        DynamicArray::size_type i { 0 };
        for(auto it{ other.begin()}; it != other.end(); ++it)
        {
            if(m_arr[i++] != (*it))
                return false;
        }
        return true;
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


private:
    // HELPER PRIVATE METHODS
    template<typename SourceIt>
    void deepCopy(SourceIt start,SourceIt finish)
    {
        const auto r = std::distance(start,finish);
        if(r > 0)
        {
            m_size = r;
            m_capacity = r;
            
            delete[] m_arr;
            m_arr = new type_name[m_size];

            std::copy(start, finish, m_arr);
        }
    }
};

#endif