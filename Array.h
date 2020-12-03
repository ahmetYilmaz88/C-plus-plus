/// @file Array.h
/// @author Ahmet Yilmaz <5005155332@student.csn.edu>
/// @date 2020-07-06
/// @note I pledge my word of honor that I have complied with the
/// Academic Integrity Policy while completing this assignment.
/// @brief This is the interface for the Array class and templates.
/// @note This is a hpp file, which also handle an exception.

#ifndef ARRAY_H_
#define ARRAY_H_

#include <cstddef>
#include <stdexcept>

/// A class that models an Array.

class Array
{
public:
    /// -----------------------------------------------------------------------
    /// Default constructor. Allocates and default-initializes an array of
    /// 'length' elements.
    /// @param length The number of elements to allocate for this Array.
    /// -----------------------------------------------------------------------

    Array(size_t length = 0) : m_length(length), m_array(new int[length] {}) {}

    /// -----------------------------------------------------------------------
    /// Copy constructor.
    /// @param other Another Array used to initialize this Array.
    /// -----------------------------------------------------------------------

    Array(const Array& other);

    /// -----------------------------------------------------------------------
    /// List constructor. Copies the contents of list.
    /// @param list   The source array.
    /// @param length The number of elements in the array.
    /// -----------------------------------------------------------------------

    Array(const int* list, size_t length);

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

    int& at(size_t pos);
    const int& at(size_t pos) const;

    /// -----------------------------------------------------------------------
    /// Returns a reference to the element at specified position 'pos'.
    /// No bounds checking performed.
    /// @param pos Position of the element to return.
    /// @return Reference to the requested element.
    /// -----------------------------------------------------------------------

    int& operator[](size_t pos)             { return m_array[pos]; }
    const int& operator[](size_t pos) const { return m_array[pos]; }

    /// -----------------------------------------------------------------------
    /// Returns reference to the first element in the array. The behavior is
    /// undefined if empty() == true.
    /// @return Reference to the first element (equivalent to m_array[0]).
    /// -----------------------------------------------------------------------

    int& front()             { return m_array[0]; }
    const int& front() const { return m_array[0]; }

    /// -----------------------------------------------------------------------
    /// Returns reference to the last element in the array. The behavior is
    /// undefined if empty() == true.
    /// @return Reference to the last element (equivalent to
    /// m_array[size() - 1])
    /// -----------------------------------------------------------------------

    int& back()             { return m_array[size() - 1]; }
    const int& back() const { return m_array[size() - 1]; }

    /// -----------------------------------------------------------------------
    /// Returns an iterator (pointer) to the first element in the array.
    /// @returns Iterator (pointer) to the fist element.
    /// -----------------------------------------------------------------------

    int* begin()             { return m_array; }
    const int* begin() const { return m_array; }

    /// -----------------------------------------------------------------------
    /// Returns an iterator (pointer) to the element following the last
    /// element of the array. This element acts as a placeholder;
    /// attempting to access it results in undefined behavior.
    ///
    /// @return Iterator (pointer) to the element following the last
    /// element.
    /// -----------------------------------------------------------------------

    int* end()             { return begin() + size(); }
    const int* end() const { return begin() + size(); }

    /// -----------------------------------------------------------------------
    /// Returns the number of int elements in the array, i.e., the distance
    /// between begin() and end().
    /// @returns The number of int elements in the array.
    /// -----------------------------------------------------------------------

    size_t size() const { return m_length; }

    /// -----------------------------------------------------------------------
    /// Copy assignment operator. Replaces the contents of the Array.
    /// -----------------------------------------------------------------------

    Array& operator=(const Array& other);

    /// -----------------------------------------------------------------------
    /// Appends additional elements to the array.
    /// -----------------------------------------------------------------------

    Array& operator+=(const Array& other);
    Array& operator+=(const int& value);

    /// -----------------------------------------------------------------------
    /// Exchanges the contents of the array with those of other. All iterators
    /// and references may be invalidated.
    /// @param [in,out] other Array to exchange the contents with.
    /// -----------------------------------------------------------------------

    void swap(Array& other);

private:
    size_t m_length = 0;         ///< The length of the array.
    int*   m_array  = nullptr;   ///< Pointer to the array in heap memory.

};  // Array class

// ============================================================================
//                      non-member functions
// ============================================================================

/// ---------------------------------------------------------------------------
/// Returns a new Array containing elements from lhs followed by
/// the elements from rhs.
/// ---------------------------------------------------------------------------

Array operator+(const Array& lhs, const Array& rhs);
Array operator+(const Array& lhs, const int& rhs);

/// ---------------------------------------------------------------------------
/// Relational operators.
/// ---------------------------------------------------------------------------

bool operator==(const Array& lhs, const Array& rhs);
inline bool operator!=(const Array& lhs, const Array& rhs) { return !(lhs == rhs); }

#endif  // ARRAY_H_

/* EOF */

