/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 12, 2015, 11:24 AM
 */

// System Library
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// User Libraries

// Global Constants

// Function prototypes

int main(int argc, char** argv) 
{
    // Declare variables
    float intRate = 0.0319f/12;
    float msrplus = 4e4f; // Loan Amount for Buick
    char nPaymnt = 60;    // Number of monthly payments
    // Calculate the monthly payments
    float temp = pow( (1+intRate) , nPaymnt); 
    float mPaymnt = intRate * temp * msrplus / (temp - 1);
    // Output the inputs
    cout << "Interest per year = " << intRate * 100 * 12 << endl;
    cout << "Number of Payments = " << static_cast<int>(nPaymnt) << endl;
    cout << "Loan Amount = $" << msrplus << endl;
    // Output our car payment
    cout << fixed << setprecision(2) << showpoint;
    cout << "My Avenir will cost $" << mPaymnt << endl;
    
    
    return 0;
}

