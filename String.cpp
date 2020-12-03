/// @file String.h
/// @author Ahmet Yilmaz <ahmet.yilmaz@student.csn.edu>
/// @date 2020-06-20
/// @note I pledge my word of honor that I have complied with the
/// CSN Academic Integrity Policy while completing this assignment.
/// @brief This is the interface for the String class and operator overloading.
/// @note Time taken to complete this assignment is more than 10 hours

# include "String.h"

//null terminated default constructor
String::String(const char* s)
: length(strlen(s))
{
    str = new char [length + 1];
    strcpy(str,s);
}

String::~String()
{
    length = 0;
    delete [] str;
    str = nullptr;
}

//the function assign specified string to the other
String& String::assign(const char* other)
{
    if (str != other) {
        String(other).swap(*this);
    }
    
    return *this;
}// end of assign

String& String::assign(const String& other)
{
    if (this != &other) {
        assign(other.begin());
    }

    return *this;
}//end of assign

// the function returns the specified character in the string
char& String::at(size_t pos)
{
    assert(pos < size());
    return str[pos];
}//end of at

// the function returns the specified character in the string
const char& String::at(size_t pos) const
{
    assert(pos < size());
    return str[pos];
}//end of at

//the function add two objects together
String& String::append(const char* s)
{
    // buffer used to build a new string
    char* buffer = nullptr;
    length += strlen(s);
    // allocate buffer memory
    buffer  = new char[length + 1];
    // concatenate the two strings
    strcat(strcpy(buffer, str), s);
    // free existing string and reassign pointer
    delete [] str;
    str = buffer;

    return *this;
}// end of append

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

//the function links 2 objects together
String concat(const String& lhs, const String& rhs)
{
    return String(lhs).append(rhs);
}// end of concat

// if they match we return true else false
bool equal(const String& lhs, const String& rhs)
{
    return strcmp(lhs.begin(), rhs.begin()) == 0;
}// end of equal

String operator+(const String& lhs, const String& rhs) 
{ 
    return concat(lhs, rhs);
}
String operator+(const String& lhs, const char* rhs) 
{ 
    return concat(lhs, rhs);
}
String operator+(const String& lhs, char rhs)
{
    return concat(lhs, &rhs);
}

/// Relational operators.
bool operator==(const String& lhs, const String& rhs)
{
    return equal(lhs,rhs);
}
bool operator!=(const String& lhs, const String& rhs)
{
    return !equal(lhs,rhs);
}
bool operator < (const String& lhs, const String& rhs)
{
    return strcmp( lhs.begin( ), rhs.begin( ) ) < 0;
}
bool operator> (const String& lhs, const String& rhs)
{
    return strcmp( lhs.begin( ), rhs.begin( ) ) > 0;
}
bool operator<=(const String& lhs, const String& rhs)
{
    return strcmp( lhs.begin( ), rhs.begin( ) ) <= 0;
}
bool operator>=(const String& lhs, const String& rhs)
{
    return strcmp( lhs.begin( ), rhs.begin( ) ) >= 0;
}

// overloaded output function.
std::ostream& operator<<(std::ostream& os, const String& string)
{
    os << string.begin();
    return os;
}// end of <<
    
//overloaded operator>>(input) function
std::istream& operator>>(std::istream& is, String& string)
{
    is >> string.begin();
    return is;
}//end of >>

// overloaded getline function
std::istream& getline(std::istream& input, String& string, char delim)
{
    const int CAPACITY = 8;
    char buffer[CAPACITY];//buffer
    string.clear();// empty the string
    char character = '\0';
    int end = 0;
    
    while(input.good() && character != delim)
    {
        if((input.get(character)))
        {
            buffer[end] = character;
            end++;
        }
        if (end == CAPACITY - 1) {
            buffer[end] = '\0';
            string.append(buffer);
            end = 0;
        }
    }
    buffer[end] = '\0';//null terminate the buffer
    string.append(buffer);//append buffer to string
    
    return input;
}// end of getline
/* EOF */
