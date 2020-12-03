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
 
 #ifndef CIRCLE_H_
 #define CIRCLE_H_

// A class that represents a circle

class Circle
{
public:
    Circle();
        //Constructor
        // Sets radius = 0;
  
    void set_radius(double radius);
      //Function to set the value of radius according
      //to the parameters.
    
    double get_radius() const { return radius;}
      //Function to return the radius
      //Postcondition: The value of radius is returned.

    double get_diameter() const { return 2 * radius;}
      //Function to return the diameter of a circle.
      //Postcondition: The value of diameter is returned.
    
    double area() const;
    //Function to calculate the area of Circle
    
    double perimeter() const;
    //Function to calculate the perimeter of Circle class
  
 private:
    double radius; //variable to store the value of radius
};//end of Circle
#endif  // CIRCLE_H_
