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
 
 #ifndef CYLINDER_H_
 #define CYLINDER_H_
 
class Cylinder: public Circle
{
public:
    Cylinder();
        //Constructor
        // Sets height = 0;
   
    void set_height(double r);
      //Function to set height of cylinder according
      //to the parameters.
    
    double get_height() const { return height;}
      //Function to return the height
      //Postcondition: The value of height is returned.
    
    double area() const;
    //Function to calculate the surface area of Cylinder
    
    double volume() const;
    //Function to calculate the volume of Cylinder
  
 private:
    double height; //variable to store the height
};//end of Cylinder
 #endif //CYLINDER_H_
