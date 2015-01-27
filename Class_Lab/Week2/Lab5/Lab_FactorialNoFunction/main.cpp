/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 21, 2015, 8:52 AM
 * 
 * Purpose: Factorial
 */

#include <iostream>
using namespace std;

// User Libraries

// Global Constants

// Function Prototypes

// Execution begins here
int main(int argc, char** argv) 
{
    int nFactrl = 1, n;
    // Prompt user for factorial
    cout << "What N would you like to use to " << endl << "calculate N!   ";
    cin  >> n;
    // Do the calculation
    for (int i = 1; i <= n;  i++)
        nFactrl *= i;
    // Output the result
    cout << n << "! = " << nFactrl << endl;
    // Exit Stage right
    return 0;
}