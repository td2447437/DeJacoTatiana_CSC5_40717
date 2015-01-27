/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 14, 2015, 11:26 AM
 */

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(int argc, char** argv) 
{
    float i,  // interest rate per cent
          t,  // temp variables
          l,  // loan amount $'s
          mp; // monthly payment $'s
    unsigned short n; // number of months
    
    // Input the variables required
    cout << "Interest rate in per cent per year! (float): ";
    cin  >> i;
    i /= (100 * 12); // convert to decimal
    cout << "Loan amount $'s (float): ";
    cin  >> l;
    cout << "Number of monthly payments (integer): ";
    cin  >> n;
    
    // Calculate the monthly payment
    if (i <= 0)
        mp = l / n;
    else
    {
        t = pow(1 + i, n);
        mp = (i * t * l) / (t - 1);
    }
    
    //Display the results
    cout << fixed << setprecision(2);
    cout << "Your monthly payment = $" << mp << endl; //0, 4000, 60 = 666.67
    return 0;
}