/// @file pa15.cpp
/// @author
/// @author Ahmet Yilmaz <ahmet.yilmaz@student.csn.edu>
/// @date 2020-07-11
/// @note I pledge my word of honor that I have complied with the
/// CSN Academic Integrity Policy while completing this assignment.
/// @brief This is the interface for the recursive functions.
/// @note Recursive functions
/// DO NOT ALTER THIS INTERFACE

#include <cassert>
#include <cstddef>
#include <iostream>
#include <algorithm>
#include <sstream>

#include "catch.hpp"

#define CATCH_CONFIG_MAIN
//function prototypes below
void pattern(unsigned int n);
long sum_range(long first, long last);
double power(double base, int exp);
template <class T>
void reverse(T* first, T* last);
bool gummybears(unsigned n);
/*
int main()
{
    unsigned n=0;
    long f,l;
    double fi=0.0;
    int la=0;
    unsigned nth=0;
    std::cout<<"Enter nth: ";
    std::cin>> nth;
    std::cout<<"Enter n: ";
    std::cin>> n;
    std::cout<<"Enter f: ";
    std::cin>> f;
    std::cout<<"Enter l: ";
    std::cin>> l;
    std::cout<<"Enter fi: ";
    std::cin>> fi;
    std::cout<<"Enter la: ";
    std::cin>> la;
    pattern(nth);
    std::cout<<sum_range(f,l)<<std::endl;
    std::cout<<power(fi,la)<<std::endl;
    std::cout<<gummybears(n)<<std::endl;
    int list[10]={1,2,3,4,5,6,7,8,9,0};
    reverse(list, list+9);
    for (int i = 0; i < 10; ++i)
        std::cout << list[i] << " ";
    
}
*/

//displays n number of stars 
void pattern(unsigned int n)
{
    if(n <= 0)
        return;
    if(n > 0)
    {
        pattern(n - 1);
        for( int i = 0; i < n; i++)
            std::cout<<("*");
        std::cout<<std::endl;
    }
}

//calculate and print sum of integers
//between first and last
long sum_range(long first, long last)
{
    if (first > last)
        return 0;
    else if (first == last)
        return first;
    else
        return first + sum_range(first + 1, last);
}

//calculate and returns power of a number
//following the specific rules
double power(double base, int exp)
{
    if (base == 0 && exp <= 0)
        return 0.0;
    while (base != 0)
    {
        if(exp == 0)
            return 1.0;
        else if(exp < 0)
            return (1.0 / power(base, -exp));
        else
            return base * (power(base,exp-1));
    }
    return base * (power(base,exp-1));
}

//reverse the first and last 
template <class T>
void reverse(T* first, T* last)
{
    if (first >= last)
        return;
    else
    {
        T temp = *first;//T data type temp variable
        *first = *last;
        *last = temp;//swap the values
        reverse(first + 1, last - 1);
    }
}

//gummybears game with specific rules
bool gummybears(unsigned n)
{
    bool tmp = false;
    if (n < 42)
        tmp = false;
    else if (n == 42)
        tmp = true;
    else
    if (n % 2 == 0)
    {
        gummybears(n / 2);
        tmp = true;
    }
    if(n % 4 == 0|| n % 3 == 0)
    {
        int x = n % 10;
        int y =(n % 100) / 10;
        unsigned temp = x * y;
        x * y != 0 && gummybears(n - temp);
        tmp = true;
    }
        
    if (n % 5 == 0)
    {
        gummybears(n - 42);
        tmp = true;
    }
    
    return tmp;
}//end of gummybears()

//Below is the unit tests for each function
TEST_CASE("pattern()", "")
{
    std::stringstream stream;                        // memory-based text stream
    std::basic_streambuf<char>* oldbuf { nullptr };  // pointer to raw buffer

    // lambda expression to test a particular pattern size
    auto test_size = [&](unsigned size) {
        stream.str("");                            // clear stream
        oldbuf = std::cout.rdbuf(stream.rdbuf());  // change raw buffer
        pattern(size);                             // call the function
        std::cout.rdbuf(oldbuf);                   // restore raw buffer
    };

    test_size(0);

    REQUIRE(stream.str() == "");

    test_size(1);

    REQUIRE(stream.str() == "*\n");

    test_size(7);

    REQUIRE(stream.str() == "*\n**\n***\n****\n*****\n******\n*******\n");
}

TEST_CASE("sum_range()", "")
{
    REQUIRE(sum_range(3, 4) == 7;
    REQUIRE(sum_range(7, 8) == 15;
    REQUIRE(sum_range(0, 5) == 15;
}

TEST_CASE("power()", "")
{
    REQUIRE(power(2, 3) == 8;
    REQUIRE(power(3, 2) == 9;
    REQUIRE(power(-4, 0) == 1;
    REQUIRE(power(0, 5) == 0;
            
}

TEST_CASE("reverse", "")
{
    int list[2]={1,2,3};
    int list1[2]={4,5,6};
    int list2[2]={7,8,9};
    
    REQUIRE(reverse(list) == 3 , 2, 1;
    REQUIRE(reverse(list1) == 6 , 5, 4;
    REQUIRE(reverse(list2) == 9 , 8, 7;
}

TEST_CASE("gummybears()", "")
{
    REQUIRE(gummybears(250) == true;
    REQUIRE(gummybears(42) == true;
    REQUIRE(gummybears(53) == false;
    REQUIRE(gummybears(41) == false;
}

