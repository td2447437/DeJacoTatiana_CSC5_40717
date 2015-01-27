/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 21, 2015, 2:27 PM
 * 
 * Homework:
 * A liter is 0.264179 gallons. 
 * 
 * Write a program that 
 * Reads:
 * - number of liters of gasoline consumed by the user’s car 
 * - number of miles traveled by the car 
 * Outputs: 
 * - number of miles per gallon the car delivered. 
 * 
 * Your program should allow the user to repeat this calculation as often as the user wishes. 
 * 
 * Define a function to compute the number of miles per gallon. 
 * Your program should use a globally defined constant for the number of liters per gallon.
 * 
 */

#include <iostream>
using namespace std;

const float L = 0.264179f; // A liter is 0.264179 gallons.

// get miles traveled per gallon
float milesPerGallon(float, float);
// ask user if they would like to repeat calculation
bool  askToRepeat();

int main(int argc, char** argv) 
{
    bool repeat = true; // assumes user wants to repeat calculation
    while (repeat)
    {
        // Declare variables
        float liters; // number of liters of gasoline
        float miles; // number of miles traveled by the car
        
        // Prompt user for liters of gasoline
        cout << "Number of liters consumed:   ";
        cin   >> liters;
        // Prompt user for number of miles 
        cout << "Number of miles traveled:    ";
        cin   >> miles;
        
        // Output the number of miles per gallon the car delivered
        cout.setf(ios::fixed); cout.precision(2);
        cout << "The car delivered " << milesPerGallon(liters, miles) << " miles per gallon." << endl;
        
        // Ask they user if they would like to repeat the calculation
        if ( askToRepeat() )
            continue;
        else
            repeat = false; 
    }
    return 0;
}

float milesPerGallon(float liters, float miles)
{
    // convert liters to gallons
    float gallons          = liters * L;
    // calculate miles per gallon
    float milesPerGallon = miles / gallons;
    return milesPerGallon;
}

bool askToRepeat()
{
    // Declare variables
    string input;  // user input
    
    // Ask user if repeat is wanted
    cout << "Repeat Calculation? ";
    cin  >> input;

    // Check if input is valid
    if (input == "yes")
        return true;
    else if (input == "no")
        return false;
    else
        askToRepeat();
    
    return false;
}