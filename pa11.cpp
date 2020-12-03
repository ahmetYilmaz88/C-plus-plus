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

//main entry point for this application
int main()
{
    double shippingCost;//variable that holds the value shipping cost
    double paintCost;//variable for paintCost
    double radius;// variable to store the value for radius
    double height;// variable for height
   
    Cylinder cylinder;// cylinder object of the Cylinder class
    
    //essential outputs and function calls below
    cout<< " Enter the radius of the container, in inches\n"
        << " height of the container, in inches\n"
        << " the shipping cost, in dollars per liter\n"
        << " the paint cost, in dollars per square foot\n"
        << " Enter the values in order:";
    cin >> radius >> height >> shippingCost >> paintCost;
    cout << endl;
    
    cylinder.set_radius(radius);//set radius into the set_radius function
    cylinder.set_height(height);// set height as parameter
    
    shippingCost *= cylinder.volume();
    paintCost *= cylinder.area();
    
    cout << fixed << showpoint  << setprecision(2) << endl;
    cout << "$" << shippingCost << " " << "$" << paintCost << endl;
    return 0;
}//end of main
