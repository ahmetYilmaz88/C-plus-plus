/// @file pa16.cpp
/// @author Ahmet Yilmaz <ahmet.yilmaz@student.csn.edu>
/// @date 2020-07-11
/// @note I pledge my word of honor that I have complied with the
/// CSN Academic Integrity Policy while completing this assignment.
/// @brief This is the interface for the sorting functions.
/// @note Seaching and sorting functions
/// DO NOT ALTER THIS INTERFACE

#include <cassert>
#include <cstddef>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <chrono>
#include <ctime>
#include <ratio>
#include <iomanip>

using namespace std::chrono;

// Declare aliases for more complex data types.
using iterator       = std::vector<int>::iterator;
using const_iterator = std::vector<int>::const_iterator;
const int MAXSIZE = 320000;
/// Sorts the elements in the range [first, last) in ascending order.
/// @param first The beginning of the range of elements to sort.
/// @param last  The end of the range of elements to sort.

//protototypes below
void bubble_sort   (iterator first, iterator last);
void selection_sort(iterator first, iterator last);
void insertion_sort(iterator first, iterator last);

//struct defines a random generator for later use
struct RandomGenerator {
    int maxValue;
    RandomGenerator(int max) :
            maxValue(max) {
    }
    int operator()() {
        return rand() % maxValue;
    }
};//end of struct

int main()
{
    int numSize = 10000;// first size
    std::vector<int> vec(10);//declare a vector that has 10 elemnt
    std::generate(vec.begin(), vec.end(), []() {
    return rand() % 10;});
    
    //below there are few print statements
    //to prove that sorting is working
    std::cout << "Sorting numbers" << std::endl;
    for (int val : vec)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    bubble_sort(vec.begin(), vec.end());
    std::cout << "Bubble" << std::endl;
    for (int val : vec)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    selection_sort(vec.begin(), vec.end());
    std::cout << "Selection" << std::endl;
    for (int val : vec)
        
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
            
    insertion_sort(vec.begin(), vec.end());
    std::cout << "Insertion" << std::endl;
    for (int val : vec)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    std::sort(vec.begin(), vec.end());
    std::cout << "std::sort" << std::endl;
    for (int val : vec)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    //print statements to match output sample
    std::cout<<"| Size        | Bubble      | Insertion   | Selection   | std::sort   |" << std::endl;
    std::cout<<"+-------------+-------------+-------------+-------------+-------------+" << std::endl;
    //for loop to check measuring time for each sorting
    //with number of different sizes
    for(numSize = 10000; numSize <= MAXSIZE; numSize *= 2)
    {
        std::vector<int> vec1(numSize);
        std::generate(vec1.begin(), vec1.end(), []() {
            return rand() % 10000;});
        
        std::cout<<"|"<< std::setfill(' ') << std::setw(13) << numSize;
        
        // To get the time_point at this instant, use function now().
        auto start = high_resolution_clock::now();
        //Get the time_point after the function returns.
        bubble_sort(vec1.begin(), vec1.end());
        // after function call
        auto stop = high_resolution_clock::now();
        //Get the difference in time_points and cast it to desired unit.
            
        // Predefined units are nanoseconds, microseconds, milliseconds,
        // seconds, minutes, hours. Use duration_cast() function.
        //auto duration = duration_cast<seconds>(stop - start);
        std::chrono::duration<double> duration = duration_cast<microseconds>(stop - start);
        // To get the value of duration, use the count() member function
        // of the duration object:
        std::cout<<"|"  << std::showpoint << std::setprecision(6)
                << std::setw(13)<< (double)duration.count() / 1000000.0;
  
        //below are just same as above for other sorting algorithms
        start = high_resolution_clock::now();
        selection_sort(vec1.begin(), vec1.end());
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        std::cout<<"|" << std::fixed << std::showpoint << std::setprecision(6)
                << std::setw(13)<< (double)duration.count() / 1000000.0;
        
        
        start = high_resolution_clock::now();
        insertion_sort(vec1.begin(), vec1.end());
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        std::cout<<"|" << std::fixed << std::showpoint << std::setprecision(6)
                << std::setw(13)<< (double)duration.count() / 1000000.0;
        
        start = high_resolution_clock::now();
        std::sort(vec1.begin(), vec1.end());
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        std::cout<<"|" << std::fixed << std::showpoint << std::setprecision(6)
                << std::setw(13)<< (double)duration.count() / 1000000.0 << "|" << std::endl;
            
    }
    std::cout<<"+-------------+-------------+-------------+-------------+-------------+" << std::endl;
    std::cout << "Time reported in seconds." << std::endl;
    
    return 0;
}

//bubble sort function
void bubble_sort(iterator first, iterator last)
{
    bool temp = false;
    iterator begin, end = last - 1;
    while (!temp)
    {
        bool temp1 = false;
        for (begin = first; begin != end; ++begin)
        {
            if (*begin  > *(begin + 1))
            {
                std::swap(*begin, *(begin + 1));
                temp1 = true;
            }
        }
        if (temp1)
            end--;
        else
            temp = true;
    }
}// end of bubble sort

//selection sort function
void selection_sort(iterator first, iterator last)
{
    iterator begin = first;
    while (begin < last)
    {
        iterator iteratorR, smallest;
        bool temp = false;
        for (iteratorR = begin; iteratorR < last; iteratorR++)
        {
            if (!temp || *iteratorR < *smallest)
            {
                smallest = iteratorR;
            }
            temp = true;
        }
        std::swap(*smallest, *begin);
        begin++;
    }
}//end of selection sort

//insertion sort function
void insertion_sort(iterator first, iterator last)
{
    std::iter_swap(first, std::min_element(first, last));
    for (iterator it = first; ++it < last; first = it)
        for (iterator iter = it; *iter < *first; --iter, --first)
            std::iter_swap(first, iter);
    
}//end of insertion_sort

/* EOF */

