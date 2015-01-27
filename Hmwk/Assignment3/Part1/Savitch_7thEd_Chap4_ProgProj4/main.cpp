/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 23, 2015, 5:36 PM
 * 
 * Homework:
 * Write a program to gauge the rate of inflation for the past year. 
 * The program asks for the price of an item (such as a hot dog) both one year ago and today. 
 * It estimates the inflation rate as the difference in price divided by the year ago price. 
 * 
 * Your program should allow the user to repeat this calculation as often as the user wishes. 
 * Define a function to compute the rate of inflation. The inflation rate should be a value of  
 * type double giving the rate as a percent, for example 5.3 for 5.3%.
 * 
 */

#include <iostream>
using namespace std;

// A function to compute the rate of inflation
//                 yrAgoPrice   today's price
float rateOfInflation(float, float);
// ask user if they would like to repeat calculation
bool  askToRepeat();

int main(int argc, char** argv) 
{
    // Declare variables
    float yrAgoPrice; // price of an item one year ago
    float todayPrice; // price of an item today
    // Loop until user no longer wants to calculate
    bool repeat = true; // assumes user wants to repeat calculation
    while (repeat)
    {
        // Prompt user for input
        cout << "What was the price of a hot dog one year ago?  "; cin >> yrAgoPrice;
        cout << "What is the price of a hot dog today?  "; cin >> todayPrice;
        // Calculate rate of inflation
        //Output results
        cout.setf(ios::fixed); cout.precision(1);
        cout << "The rate of Inflation is " << rateOfInflation(yrAgoPrice, todayPrice) << "%" << endl;
        // Ask they user if they would like to repeat the calculation
        if ( askToRepeat() )
            continue;
        else
            repeat = false;
    }
    return 0;
}

float rateOfInflation(float p1, float p2)
{
    // Declare variables
    float diff = p2 - p1;       // the difference in prices
    float results = diff / p1; // the inflation rate as the difference in price divided by the year ago price.
    return results;
}

bool askToRepeat()
{
    // Declare variables
    string input;  // user input
    // Ask user if repeat is wanted
    cout << "Repeat Calculation? "; cin  >> input;
    // Check if input is valid
    if (input == "yes")
        return true;
    else if (input == "no")
        return false;
    else
        askToRepeat();   
    return false;
}