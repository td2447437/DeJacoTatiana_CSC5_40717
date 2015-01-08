/* 
 * File:   main.cpp
 * Author: Tati
 *
 * Created on January 6, 2015, 10:30 AM
 * Purpose: Homework, Solution to free fall problem
 */

//System Libraries
#include <iostream>
using namespace std;

// User Libraries

// Global Constants
const float GRAVITY = 32.174; // unit: ft/sec^2

// Function Prototypes

// Execution Begins Here
int main(int argc, char** argv) 
{
    // Declare variables
    unsigned int time; // unit: seconds
    float        dist; // distance in ft
    
    // Prompt user for input
    cout << "This program calculates free fall"           << endl;
    cout << "Distance dropped in feet with an"            << endl;
    cout << "Object starting at rest."                    << endl;
    cout << "Input the free fall time to drop in seconds" << endl;
    cout << "**The time input is an positive integer**"   << endl;
    cin  >> time;
    // Calculate distance dropped
    dist = (GRAVITY * time * time) / 2; // 1/2*g*t^2
    // Output results
    cout << "Distance dropped = " << dist << " (ft)" << endl;
    
    return 0; // returns void 
}
/* 1.0f >> Tells computer you want a float and not a double
   1.0  >> Computer automatically reads it as a double */

