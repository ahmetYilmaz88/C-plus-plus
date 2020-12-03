/// @file Array.h
/// @author Ahmet Yilmaz <5005155332@student.csn.edu>
/// @date 2020-07-06
/// @note I pledge my word of honor that I have complied with the
/// Academic Integrity Policy while completing this assignment.
/// @brief This is the interface for the Array class and templates.
/// @note This is a hpp file, which also handle an exception.

#ifndef ARRAY_H_
#define ARRAY_H_

#include "Array.h"

#include <cstddef>
#include <stdexcept>
#include <cstring>
#include <iostream>
#include <algorithm>

/// A class that models an Array.
template <class T>
class Array
{
public:
    /// -----------------------------------------------------------------------
    /// Default constructor. Allocates and default-initializes an array of
    /// 'length' elements.
    /// @param length The number of elements to allocate for this Array.
    /// -----------------------------------------------------------------------

    Array(size_t length = 0) : m_length(length), m_array(new T [length] {}) {}

    /// -----------------------------------------------------------------------
    /// Copy constructor.
    /// @param other Another Array used to initialize this Array.
    /// -----------------------------------------------------------------------

    Array(const Array<T>& other);

    /// -----------------------------------------------------------------------
    /// List constructor. Copies the contents of list.
    /// @param list   The source array.
    /// @param length The number of elements in the array.
    /// -----------------------------------------------------------------------

    Array(const T* list, size_t length);

    /// -----------------------------------------------------------------------
    /// Destructor.
    /// -----------------------------------------------------------------------

    ~Array();

    /// -----------------------------------------------------------------------
    /// Returns a reference to the element at specified position 'pos'.
    /// Bounds checking is performed.
    /// An exception of type std::out_of_range is thrown if !(pos < size()).
    /// @throws std::out_of_range
    /// @param pos Position of the element to return.
    /// @return Reference to the requested element.
    /// -----------------------------------------------------------------------
    
    T& at(size_t pos);
    const T& at(size_t pos) const;
    
    /// -----------------------------------------------------------------------
    /// Returns a reference to the element at specified position 'pos'.
    /// No bounds checking performed.
    /// @param pos Position of the element to return.
    /// @return Reference to the requested element.
    /// -----------------------------------------------------------------------

    T& operator[](size_t pos)             { return m_array[pos]; }
    const T& operator[](size_t pos) const { return m_array[pos]; }

    /// -----------------------------------------------------------------------
    /// Returns reference to the first element in the array. The behavior is
    /// undefined if empty() == true.
    /// @return Reference to the first element (equivalent to m_array[0]).
    /// -----------------------------------------------------------------------

    T& front()             { return m_array[0]; }
    const T& front() const { return m_array[0]; }

    /// -----------------------------------------------------------------------
    /// Returns reference to the last element in the array. The behavior is
    /// undefined if empty() == true.
    /// @return Reference to the last element (equivalent to
    /// m_array[size() - 1])
    /// -----------------------------------------------------------------------

    T& back()             { return m_array[size() - 1]; }
    const T& back() const { return m_array[size() - 1]; }

    /// -----------------------------------------------------------------------
    /// Returns an iterator (pointer) to the first element in the array.
    /// @returns Iterator (pointer) to the fist element.
    /// -----------------------------------------------------------------------

    T* begin()             { return m_array; }
    const T* begin() const { return m_array; }

    /// -----------------------------------------------------------------------
    /// Returns an iterator (pointer) to the element following the last
    /// element of the array. This element acts as a placeholder;
    /// attempting to access it results in undefined behavior.
    ///
    /// @return Iterator (pointer) to the element following the last
    /// element.
    /// -----------------------------------------------------------------------

    T* end()             { return begin() + size(); }
    const T* end() const { return begin() + size(); }

    /// -----------------------------------------------------------------------
    /// Returns the number of int elements in the array, i.e., the distance
    /// between begin() and end().
    /// @returns The number of int elements in the array.
    /// -----------------------------------------------------------------------

    size_t size() const { return m_length; }

    /// -----------------------------------------------------------------------
    /// Copy assignment operator. Replaces the contents of the Array.
    /// -----------------------------------------------------------------------

    Array& operator=(const Array<T>& other);

    /// -----------------------------------------------------------------------
    /// Appends additional elements to the array.
    /// -----------------------------------------------------------------------

    Array& operator+=(const Array<T>& other);
    Array& operator+=(const T& value);

    /// -----------------------------------------------------------------------
    /// Exchanges the contents of the array with those of other. All iterators
    /// and references may be invalidated.
    /// @param [in,out] other Array to exchange the contents with.
    /// -----------------------------------------------------------------------

    void swap(Array& other);

private:
    size_t m_length = 0;         ///< The length of the array.
    T*   m_array  = nullptr;   ///< Pointer to the array in heap memory.

};  // Array class

// ============================================================================
//                      non-member functions
// ============================================================================

/// ---------------------------------------------------------------------------
/// Returns a new Array containing elements from lhs followed by
/// the elements from rhs.
/// ---------------------------------------------------------------------------
template <class T>
Array<T> operator+(const Array<T>& lhs, const Array<T>& rhs);
template <class T>
Array<T> operator+(const Array<T>& lhs, const T& rhs);

/// ---------------------------------------------------------------------------
/// Relational operators.
/// ---------------------------------------------------------------------------
template <class T>
bool operator==(const Array<T>& lhs, const Array<T>& rhs);
template <class T>
inline bool operator!=(const Array<T>& lhs, const Array<T>& rhs) { return !(lhs == rhs); }

template <class T>
Array<T>::Array(const Array<T>& other)
{
    {

    m_length = other.size();
    m_array = new T[m_length];
    const T* p = other.begin();
    for(size_t i = 0; i < m_length; i++)
    {
    m_array[i] = p[i];
    }

    }
    //Array(other.m_array, other.m_length);
}

template <class T>
Array<T>::Array(const T* list, size_t length)
{
    m_array = new T[m_length];
    m_length = length;
    size_t i;
    for(i = 0; i< length; i++)
    {
        m_array[i] = list[i];
    }
}

// ----------------------------------------------------------------------------

template <class T>
Array<T>::~Array()
{
    m_length = 0;
    delete [] m_array;
    m_array = nullptr;
}

// ----------------------------------------------------------------------------

template <class T>
T& Array<T>::at(size_t pos)
{
     if (!(pos < size()))
        throw std::out_of_range("The value is out of range!");
    
    return m_array[pos];
}

template <class T>
const T& Array<T>::at(size_t pos) const
{
    if (!(pos < size()))
        throw std::out_of_range("The value is out of range!");
    
    return m_array[pos];
}

// ----------------------------------------------------------------------------

template <class T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
    if (this != &other)
    {
        if(other.m_length!= m_length)
        {
        delete [] m_array;
        m_length =0;
        m_array = nullptr;
        m_array = new T [other.m_length];
        m_length = other.m_length;
        }
        std::copy(other.m_array, other.m_array + other.m_length, m_array);
    }
    return *this;
}

// ----------------------------------------------------------------------------

template <class T>
Array<T>& Array<T>::operator+=(const Array<T>& other)
{
    T* temp = m_array;
    m_array = new T [m_length + other.size()];
    size_t i;
    for(i =0; i < m_length; i++)
    {
        m_array[i] = temp[i];
    }
    m_length += other.size();
    for(size_t j = 0; i < m_length; j++,i++)
    {
        m_array[i] = temp[j];
    }
    delete [] temp;

    return *this;
}

template <class T>
Array<T>& Array<T>::operator+=(const T& value)
{
    T* temp = m_array;
    m_array = new T [m_length + 1];
    size_t i;
    for(i = 0; i < m_length; i++)
    {
        m_array[i] = temp[i];
    }
    m_array[m_length] = value;
    m_length ++;
    delete [] temp;

    return *this;
}

// ----------------------------------------------------------------------------

template <class T>
void Array<T>::swap(Array<T>& other)
{
    std::swap(m_length, other.m_length);
    std::swap(m_array, other.m_array);
}

// ============================================================================
// non-member functions
// ============================================================================

template <class T>
Array<T> operator+(const Array<T>& lhs, const Array<T>& rhs)
{
    return Array<T>(lhs)+=rhs;
}

template <class T>
Array<T> operator+(const Array<T>& lhs, const T& rhs)
{
    return Array<T>(lhs).operator+=(rhs);
    
}

// ----------------------------------------------------------------------------
template <class T>
bool operator==(const Array<T>& lhs, const Array<T>& rhs)
{
    bool ret = true;
    if(lhs.size() != rhs.size())
    {
        ret = false;
    }
    for(size_t i = 0; i < lhs.size(); i++)
    {
        if(lhs.begin()[i] != rhs.begin()[i])
        {
            ret = false;
        }
    }
    return ret;
}

/* EOF */
#endif  // ARRAY_H_
