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
#include <iomanip>

//The program asks the user for his or her first and last name,
// and test the String class functions
int main()
{
    const int BUF_SIZE = 80;
    //create objects of String class
    String str1;
    String str2;
    String str3("Ahmet");
    String str4("Yilmaz");
    
    char* buffer = new char[BUF_SIZE];
    //prompt the user for their name
    std::cout << "What is your first name? ";
    // read no more than BUF_SIZE - 1
    std::cin >> std::setw(BUF_SIZE) >> buffer;
    str1.assign(buffer);
    //if names are the same print this
    if (equal(str1, str3 ))
    {
        std::cout<< "That is the same as my first name!" << std::endl;
    }
    //else print this
    else
    {
        std::cout<< "My first name is "<< str3.begin() << "." << std::endl;
    }
    //prompt the user for their last name
    std::cout << "What is your last name? ";
    std::cin >> std::setw(BUF_SIZE) >> buffer;  // read no more than BUF_SIZE - 1
    str2.assign(buffer);
    //if names are the same print this
    if(equal(str2, str4))
    {
        std::cout<< "That is the same as my last name!" << std::endl;
    }
    //else print this
    else
    {
        std::cout<< "My last name is "<< str4.begin() << "." << std::endl;
    }
    std::cout << "I am happy to meet you, " << str1.begin() << " "
    << str2.begin() << std::endl;
    /*
    // testing every single funtion I wrote below
    String s;
    str1.print();
    str1.swap(str2);
    str1.print();
    s.assign("abc");
    s.print();
    s.append("def");
    s.print();
    std::cout << s.back() << std::endl;
    std::cout << s.front() << std::endl;
    std::cout << s.begin() << std::endl;
    std::cout << s.size() << std:: endl;
    s.print();
    s.clear();
    s.assign("Program");
    s.print();
    std::cout << s.at(3) << std::endl;
    s.print();
    std::cout << s.end() << std::endl;
    std::cout << s.empty() << std::endl;
    s.assign("C++");
    str1.assign("Program");
    s.print();
    str2.swap(str4);
    str2.print();
    concat(s,str1);
    */
    return 0;
}//end of main
