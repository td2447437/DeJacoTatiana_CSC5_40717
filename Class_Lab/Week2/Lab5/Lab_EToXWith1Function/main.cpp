/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 21, 2015, 9:17 AM
 */

#include <iostream>
#include <cmath>
using namespace std;

// User Libraries

// Global Constants

// Function Prototypes
int nFactrl(int);

// Execution begins here
int main(int argc, char** argv) 
{
    // Declare variables
    float approxEx = 1, exactEx, x;
    // Prompt the user for the power of e^x
    cout << "What x in e^x would you like to use?   ";
    cin   >> x;
    // Calculate e^x
    for (int n = 1; n <= 13; n++) 
        approxEx += (pow(x,n) / nFactrl(n));
    // Calculate the exact e^x
    exactEx = exp(x);
    // Compare the results
    cout << "Approximate e^x = " << approxEx << endl;
    cout << "Exact e^x       = "      << exactEx   << endl;
    // Exit Stage right
    return 0;
}

int nFactrl(int n)
{
    // Declare variables
    // Note: function only works for values 0 to 13
    int factorial = 1;
    if (n == 0 || n== 1)
        return factorial;
    else if (n <= 13)
    {
        for (int i = 2; i <= n; i++) 
            factorial *= i;
        return factorial;
    }
    else // do calculation
        return -1;
}