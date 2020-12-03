/// @file String.h
/// @author Ahmet Yilmaz <ahmet.yilmaz@student.csn.edu>
/// @date 2020-06-20
/// @note I pledge my word of honor that I have complied with the
/// CSN Academic Integrity Policy while completing this assignment.
/// @brief This is the interface for the String class and operator overloading.
/// @note Time taken to complete this assignment is more than 10 hours

# include "String.h"

#include <iostream>

//The program asks the user for his or her first and last name and studentID,
// and test the String class functions

// A person has a first and last name and student ID.
struct student_t {
    String studentFirstName;  // A student's first name.
    String studentLastName;   // A student's last name.
    String studentID; // A student's ID number
    String studentMiddleName;
// Concatenates firstname and lastname, returning a combined full name.
// @returns A student's full name.
    String fullname() const
    {
        return String(studentFirstName).append(" ").append(studentLastName);
    }
};
    
// ---------------------------------------------------------------------------
// Main entry-point for this application.
//
// @returns Exit-code for the process - 0 for success, else an error code.
// ---------------------------------------------------------------------------
int main() {
    student_t user; // the user
    
//prompt the user necessary information below
//std::cout lines can be commented to match with the sample input
    std::cout << "After each input press tab and enter when done:\n";
    std::cout << "What is your student ID number?: \n";
    getline(std::cin, user.studentID,'\t');
    std::cout << "What is your last name?: \n";
    getline(std::cin, user.studentLastName,'\t');
    std::cout << "What is your first name?: \n";
    getline(std::cin, user.studentFirstName,'\t');
    //std::cin.ignore();
    bool valid = true;
    for (auto c : user.studentID)
    {
        if (user.studentID.size() != 10
            && !isdigit(user.studentID.at(0))
            && (!isdigit(c) || !isalpha(c)))
        {
            valid = false;
            break;
        }
    }
    
    if (valid)
    {
        std::cout << user.fullname().append("- Valid Student ID").append("\n");
    }
    else
    {
        std::cout << user.fullname().append("- Invalid Student ID").append("\n");
    }
    return EXIT_SUCCESS;
}//end of main
