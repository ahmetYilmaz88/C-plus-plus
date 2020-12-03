 /// @author Ahmet Yilmaz
 /// I pledge my word of honor that I have abided
 /// by the CSN Academic Integrity Policy while completing
 /// this assignment.
 /// @file AhmetYilmazCit133_pa11.cpp
 /// @version The date is: 2020-06-13
 /// @brief The program uses various number of functions
 /// and two class
///  class names are Circle and Cylinder
///  it has 2 constructors  without parameter, 1 for each class
///  Circle class:
 /// first function sets the value for radius according to the parameter
 /// second function returns the radius value to the parameter
 /// third function returns the diameter
 /// fourth function calculates and returns the area of a circle
///  fifth function calculate and return perimeter
///  Cylinder class:
///  first function sets the value for height according to the parameter
 /// second function returns the height value to the parameter
 /// third function calculates and returns the area of a cylinder
 /// fourth function calculates and returns the volume of a cylinder
 /// @note Time taken to develop, write, test and debug
 /// is less than 4 hour.

 // include the necessary headers
#include <iostream>
#include <string>
#include <time.h>
#include <cmath>
#include <iomanip>

#include "Circle.h"
#include "Cylinder.h"

using namespace std;

Cylinder::Cylinder()  //default - no arguments
{
    height = 0;// Sets height = 0 in default constructor
}//end of default constructor
// constructor with no parameter

void Cylinder:: set_height(double h)//function to set height
{
    if(h <= 0)
    {
        height = 1;
    }
    else
    {
        height = h;
    }//end of set_height()
}
/// sets the values of attribute based on its parameter
/// parameters
/// @ return - none

double Cylinder:: area() const// function area
{
    return (perimeter() * (get_radius() + height)) / 144;
}//end of area()
/// sets the values of attribute based on its parameter
/// parameters
/// @return - area

double Cylinder:: volume() const// function volume
{
    return (Circle::area() * height) / 1728 * 28.31685;
}//end of volume()
/// sets the values of attribute based on its parameter
/// parameters
/// @return - volume
