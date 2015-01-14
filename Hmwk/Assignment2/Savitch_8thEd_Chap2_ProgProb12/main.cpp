/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 13, 2015, 11:35 AM
 */

// System Libraries
#include <iostream>
using namespace std;

// User Libraries

// Global Libraries

// Function Prototypes

// Execution Begins here
int main(int argc, char** argv) 
{
    // Declare variables
    float number, guess, r;
    // Input a number
    cout << "Input a number to estimate it's square root" << endl;
    cout << "The format fill a positive float" << endl;
    cin  >> number;
    // First pass
    guess = number / 2;
    r = number / guess;
    guess = (guess + r ) / 2;
    // Output the first pass
    cout << "First Pass calculation -> " << guess << endl;
    // Second pass
    r = number / guess;
    guess = (guess + r ) / 2;
    // Output the second pass
    cout << "Second Pass calculation -> " << guess << endl;
    // Third pass
    r = number / guess;
    guess = (guess + r ) / 2;
    // Output the third pass
    cout << "Third Pass calculation -> " << guess << endl;
    // Fourth pass
    r = number / guess;
    guess = (guess + r ) / 2;
    // Output the fourth pass
    cout << "Fourth Pass calculation -> " << guess << endl;
    
    //Exit stage right
    return 0;
}

