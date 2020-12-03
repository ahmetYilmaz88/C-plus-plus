/// @file String.h
/// @author Ahmet Yilmaz <ahmet.yilmaz@student.csn.edu>
/// @date 2020-06-20
/// @note I pledge my word of honor that I have complied with the
/// CSN Academic Integrity Policy while completing this assignment.
/// @brief This is the interface for the String class.
/// @note Time taken to complete this assignment is more than 10 hours

# include "String.h"

#include <cassert>
#include <cstddef>
#include <iostream>
#include <cstring>
#include <iomanip>

//null terminated default constructor
String::String(const char* s)
{
    // determine length of src
    length = strlen(s);
    // allocate enough memory
    str = new char[length + 1];
    // copy src to dest
    strcpy(str, s);
}//end of default constructor

//copy constructor which initializes the str and length
String::String(const String& other)
: str(other.str), length(other.length) {}//end copy constructor

//the function assign specified string to the other
String& String::assign(const char* other)
{
    clear();
    // determine length of src
    length = strlen(other);
    // allocate enough memory
    str = new char[length + 1];
    strcpy(str, other);
    
    return *this;
}//end of assign

//the function assign specified string to the other
String& String::assign(const String& other)
{
    clear();
    str = other.str;
    length = other.length;
    
    return *this;
}//end of assign

// the function returns the specified character in the string
char& String::at(size_t pos)
{
    // if negative throw an error and crash the program
    assert(pos >= 0);
    // if pos is too big throw an error and crash the program
    assert(pos < length);
    
    return str[pos];
}//end of at

// the function returns the specified character in the string
const char& String::at(size_t pos) const
{
    // if negative throw an error and crash the program
    assert(pos >= 0);
    // if pos is too big throw an error and crash the program
    assert(pos < length);
    
    return str[pos];
}//end of at

//the function returns the last character of the string
char& String::front()
{
      return at(0);
}//end of front

//the function returns the first character of the string
const char& String::front() const
{
    return at(0);
}//end of front

//the function returns the last character of the string
char& String::back()
{
    return at(length - 1);
}//end of back

//the function returns the last character of the string
const char& String::back() const
{
    return at(length - 1);
}//end of back

//the function return the char at the end of the string
char* String::end()
{
    return str + this->length - 1;
}//end of end

//the function return the char at the end of the string
const char* String::end() const
{
    return str + this->length - 1;
}//end of end function

// the function clear the data
void String::clear()
{
    //if there is no data in str
    if (str != nullptr )
    {
        // delete the current string
        delete [] str;
        // return the str and length to NULL
        str = nullptr;
        length = 0;
    }
}//end of clear

//the function add two objects together
String& String::append(const char* s)
{
    // the new length
    size_t new_length = length + std::strlen(s);
    // allocate memory for the new string
    char* new_str = new char[new_length + 1];
    size_t i = 0;
    while (i < length) {
        new_str[i] = str[i];
        i++;
    }
    // copy s into new_str from index length to the end
    while (i < new_length)
    {
        new_str[i] = s[i - length];
        i++;
    }
    // delete the old string
    clear();
    str = new_str;
    length = new_length;
    
    return *this;
}// end of append

//the function add two objects together
String& String::append(const String& other)
{
    // the new length
    size_t new_length = length + other.size();
    
    // allocate memory for the new string
    char* new_str = new char[new_length + 1];
    
    size_t i = 0;
    while (i < length)
    {
        new_str[i] = str[i];
        i++;
    }
    // copy s into new_str from index length to the end
    while (i < new_length)
    {
        new_str[i] = other.str[i - length];
        i++;
    }
    // delete the old string
    clear();
    str = new_str;
    length = new_length;
         
    return *this;
}//end of append

// the function takes part and exchange the two objects
void String::swap(String& other)
{
    char * temp = str;
    str = other.str;
    other.str = temp;
    size_t hold = length;
    length = other.length;
    other.length = hold;
}// end of swap

//the function output the data
void String::print(std::ostream& output = std::cout) const
{
    output << str << std::endl;
}//end of print

//the function links 2 objects together
String concat(const String& lhs, const String& rhs)
{
    // return a call to the constructor
    String s(lhs.begin());
    // append rhs to lhs
    s.append(rhs.begin());
    return s;
}// end of concat

// lhs and rhs are STRING objects.
//we compare and see if they math in this function
// if they match we return true else false
bool equal(const String& lhs, const String& rhs)
{
    //compare the length of each objects
    if ( lhs.size() != rhs.size() )
    {
        return false;
    }
    
    // need to compare each character in both strings to each other
    for ( size_t i = 0; i < lhs.size(); i++)
    {
        // if they aren't the same
        if (lhs.at(char(i)) != rhs.at(i))
        {
            // then theyre not equal
            return false;
        }
    }
    //they are equal
    return true;
}//enf of equal
