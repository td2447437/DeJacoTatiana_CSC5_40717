/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 15, 2015, 10:54 AM
 * 
 * Homework: 
 * Write a program that finds the temperature that is the same in both 
 * Celsius and Fahrenheit. The formula to convert from Celsius to 
 * Fahrenheit is
 * 
 * Fahrenheit = ( (9 * Celsius) / 5 ) + 32
 * 
 * Your program should create 
 * - two integer variables for the temperature in Celsius and Fahrenheit. 
 * - initialize the temperature to 100 degrees Celsius. 
 * - in a loop, decrement the Celsius value and compute the corresponding 
 *   temperature in Fahrenheit until the two values are the same.
 * 
 * Since you are working with integer values, the formula may not give an 
 * exact result for every possible Celsius temperature. This will not affect 
 * your solution to this particular problem.
 */

#include <iostream>
using namespace std;

int main(int argc, char** argv) 
{
    int F,       // Fahrenheit
        C = 100; // Celsius initialized to 100 degrees
    
    do 
    {
        F = ( (9 * C) / 5 ) + 32;
        
        cout << "Celsius: " << C << " Fahrenheit: " << F << endl;
        if ( F == C )
            break;
        else
            C--;
    }
    while (C != F);
    
    return 0;
}

