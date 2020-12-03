/// @file Array.h
/// @author Ahmet Yilmaz <5005155332@student.csn.edu>
/// @date 2020-07-06
/// @note I pledge my word of honor that I have complied with the
/// Academic Integrity Policy while completing this assignment.
/// @brief This is the interface for the Array class and templates.
/// @note This is a hpp file, which also handle an exception.

#include "Array.h"

Array::Array(const Array& other)
{
    // TODO
}

Array::Array(const int* list, size_t length)
{
    // TODO
}

// ----------------------------------------------------------------------------

Array::~Array()
{
    // TODO
}

// ----------------------------------------------------------------------------

int& Array::at(size_t pos)
{
    // TODO
    return front();  // function stub requires a return value
}

const int& Array::at(size_t pos) const
{
    // TODO
    return front();  // function stub requires a return value
}

// ----------------------------------------------------------------------------

Array& Array::operator=(const Array& other)
{
    // TODO
    return *this;  // function stub requires a return value
}

// ----------------------------------------------------------------------------

Array& Array::operator+=(const Array& other)
{
    // TODO
    return *this;  // function stub requires a return value
}

Array& Array::operator+=(const int& value)
{
    // TODO
    return *this;  // function stub requires a return value
}

// ----------------------------------------------------------------------------

void Array::swap(Array& other)
{
    // TODO
}

// ============================================================================
// non-member functions
// ============================================================================

Array operator+(const Array& lhs, const Array& rhs)
{
    // TODO
    return Array();  // function stub requires a return value
}

Array operator+(const Array& lhs, const int& rhs)
{
    // TODO
    return Array();  // function stub requires a return value
}

// ----------------------------------------------------------------------------

bool operator==(const Array& lhs, const Array& rhs)
{
    // TODO
    return false;  // function stub requires a return value
}

// ----------------------------------------------------------------------------

/* EOF */

