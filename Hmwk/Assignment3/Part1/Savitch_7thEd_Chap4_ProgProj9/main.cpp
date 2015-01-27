/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 22, 2015, 11:37 AM
 * 
 * Homework: 
 * Write a program that asks for the user’s 
 * - height
 * - weight
 * - age 
 * Then computes clothing sizes according to the formulas: 
 * 
 * - Hat size = weight in pounds divided by height in inches and all that multiplied by 2.9.
 * 
 * - Jacket size (chest in inches) = height times weight divided by 288 and then 
 *                                        adjusted by adding 1/8 of an inch for each 10 years over age 30. 
 * (Note that the adjustment only takes place after a full 10 years. So, there is 
 * no adjustment for ages 30 through 39, but 1/8 of an inch is added for age 40.)
 * 
 * - Waist in inches = weight divided by 5.7 and then 
 *                        adjusted by adding 1/10 of an inch for each 2 years over age 28. 
 * (Note that the adjustment only takes place after a full 2 years. So, there is no adjustment for 
 * age 29, but 1/10 of an inch is added for age 30.)
 * 
 * Use functions for each calculation. Your program should allow the user to repeat this calculation as often as 
 * the user wishes.
 */

#include <iostream>
#include <cmath>
using namespace std;

// Computes clothing sizes according to formulas
//                       height weight
float computeHatSize(float, float);
//                           height weight age
float computeJacketSize(float, float, float);
//                           weight age
float computeWaistSize(float, float);
// Asks user to repeat calculation
bool  askToRepeat();

int main(int argc, char** argv) 
{
    bool repeat = true; // assumes user wants to repeat calculation
    while (repeat)
    {
        // Declare variables
        float height, weight, age;
        // Prompt user for height, weight, age
        cout << "Your height (in):  ";
        cin   >> height;
        cout << "Your weight (lbs):  ";
        cin   >> weight;
        cout << "Your age (yrs):  ";
        cin   >> age;
        // Compute and Output clothing sizes
        cout.setf(ios::fixed); cout.precision(2);
        cout << "Your hat size is "     << computeHatSize(height, weight) << endl;
        cout << "Your jacket size is " << computeJacketSize(height, weight, age) << " inches" << endl;
        cout << "Your waist size is "   << computeWaistSize(weight, age)  << " inches" << endl; 
        // Ask they user if they would like to repeat the calculation
        if ( askToRepeat() )
            continue;
        else
            repeat = false;
    }
    return 0;
}

float computeHatSize(float h, float w)
{
    // user's hat size according to their height, weight
    float hatSize = (w / h) * 2.9f; 
    return hatSize;
}

float computeJacketSize(float h, float w, float a)
{
    // user's jacket size according to their height, weight, age
    float jacketSize = (h * w) / 288.0f;
    
    int t; // temporary variable
    if (a > 40)
    {
        t = a - 30;
        if (t % 10 == 0)
            jacketSize += ( (1/8) * t ) ;
    }  
    return jacketSize; 
}

float computeWaistSize(float w, float a)
{
    // user's waist size according to their height, weight, age
    float waistSize = w / 5.70f;
    
    int t; // temporary variable
    if (a > 30)
    {
        t = a - 28;
        if (t % 2 == 0)
            waistSize += ( (1/10) * t ) ;
    }  
    return waistSize;  
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