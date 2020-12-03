/// @file String.h
/// @author Ahmet Yilmaz <ahmet.yilmaz@student.csn.edu>
/// @date 2020-06-20
/// @note I pledge my word of honor that I have complied with the
/// CSN Academic Integrity Policy while completing this assignment.
/// @brief This is the interface for the String class.
/// @note Time taken to complete this assignment is more than 10 hours

#ifndef STRING_H_
#define STRING_H_

#include <cassert>
#include <cstddef>
#include <iostream>
#include <iomanip>

/// A class that models a string.

class String
{
public:
    
    /// -----------------------------------------------------------------------
    /// Default constructor.
    ///
    /// @param str (Optional) A null-terminated string to used initialize this
    /// String.
    /// -----------------------------------------------------------------------

    String(const char* str = "");

    /// -----------------------------------------------------------------------
    /// Copy constructor.
    ///
    /// @param other Another String used to initialize this String.
    /// -----------------------------------------------------------------------

    String(const String& other);

    /// -----------------------------------------------------------------------
    /// Destructor
    /// -----------------------------------------------------------------------

    ~String() {delete [] str;}

    /// -----------------------------------------------------------------------
    /// Replaces the contents of this string with that of another.
    ///
    /// @param other String to be used as source to initialize the characters
    /// with.
    ///
    /// @return *this.
    /// -----------------------------------------------------------------------

    String& assign(const char* other);
    String& assign(const String& other);

    /// -----------------------------------------------------------------------
    /// Returns a reference to the character at specified position 'pos'.
    /// Bounds checking is performed using an assertion.
    ///
    /// @param pos Position of the character to return.
    ///
    /// @return Reference to the requested character.
    /// -----------------------------------------------------------------------

    char& at(size_t pos);
    const char& at(size_t pos) const;

    /// -----------------------------------------------------------------------
    /// Returns reference to the first character in the string. The behavior is
    /// undefined if empty() == true.
    ///
    /// @return Reference to the first character (equivalent to str[0]).
    /// -----------------------------------------------------------------------

    char& front();
    const char& front() const;

    /// -----------------------------------------------------------------------
    /// Returns reference to the last character in the string. The behavior is
    /// undefined if empty() == true.
    ///
    /// @return Reference to the last character (equivalent to str[size() - 1])
    /// -----------------------------------------------------------------------

    char& back();
    const char& back() const;

    /// -----------------------------------------------------------------------
    /// Returns an iterator (pointer) to the first character in the string.
    /// @returns Iterator (pointer) to the fist character.
    /// -----------------------------------------------------------------------

    char* begin() { return str; }
    const char* begin() const { return str; }

    /// -----------------------------------------------------------------------
    /// Returns an iterator (pointer) to the character following the last
    /// character of the string. This character acts as a placeholder;
    /// attempting to access it results in undefined behavior.
    ///
    /// @return Iterator (pointer) to the character following the last
    /// character.
    /// -----------------------------------------------------------------------

    char* end();
    const char* end() const;

    /// -----------------------------------------------------------------------
    /// Checks if the string has no character, i.e., whether begin() == end().
    /// @returns true if the string is empty, false otherwise.
    /// -----------------------------------------------------------------------

    bool empty() const { return begin() == end(); }

    /// -----------------------------------------------------------------------
    /// Returns the number of char elements in the string, i.e., the distance
    /// between begin() and end().
    /// @returns The number of char elements in the string.
    /// -----------------------------------------------------------------------

    size_t size() const { return length; }

    /// -----------------------------------------------------------------------
    /// Removes all characters from the string. All pointers, references, and
    /// iterators are invalidated.
    /// -----------------------------------------------------------------------

    void clear();

    /// -----------------------------------------------------------------------
    /// Appends null-terminated string s to the string
    ///
    /// @param s Pointer to the character string to append.
    ///
    /// @return *this.
    /// -----------------------------------------------------------------------

    String& append(const char* s);
    String& append(const String& other);

    /// -----------------------------------------------------------------------
    /// Exchanges the contents of the string with those of other. All iterators
    /// and references may be invalidated.
    ///
    /// @param [in,out] other String to exchange the contents with.
    /// -----------------------------------------------------------------------

    void swap(String& other);

    /// -----------------------------------------------------------------------
    /// Prints the string to the specified output stream.
    ///
    /// @param [in,out] output (Optional) The output stream.
    /// -----------------------------------------------------------------------

    void print(std::ostream& output) const;

    /// This is a special value equal to the maximum value representable by
    /// the type size_t. The exact meaning depends on context, but it is
    /// generally used either as an end of string indicator by functions
    /// that expect a string index or as the error indicator by functions
    /// that return a string index.

    static constexpr size_t NPOS = static_cast<size_t>(-1);

private:
    char*  str    = nullptr;    ///< Pointer to the string in heap memory.
    size_t length = 0;          ///< The length of the string.
};  // String class

/// ---------------------------------------------------------------------------
/// Returns a new string containing characters from lhs followed by the
/// characters from rhs.
/// @param lhs String to concatenate.
/// @param rhs String to concatenate.
/// ---------------------------------------------------------------------------

String concat(const String& lhs, const String& rhs);

/// ---------------------------------------------------------------------------
/// Compares the contents of a string with another string. Two strings are
/// equal if both the size of lhs and rhs are equal and each character in
/// lhs has the equivalent character in rhs at the same position.
/// @param lhs String to compare.
/// @param rhs String to compare.
/// @returns true if the corresponding comparison holds, false otherwise.
/// ---------------------------------------------------------------------------

bool equal(const String& lhs, const String& rhs);

static constexpr size_t NPOS = static_cast<size_t>(-1);

#endif
