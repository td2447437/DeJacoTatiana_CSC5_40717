/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 6, 2015, 6:43 PM
 * 
 * Homework:
 * Write a program that allows the user to enter a number of quarters, dimes, 
 * and nickels and then outputs the monetary value of the coins in cents. For 
 * example, if the user enters 2 for the number of quarters, 3 for the number 
 * of dimes, and 1 for the number of nickels, then the program should output 
 * that the coins are worth 85 cents.
 */

#include <iostream>
using namespace std;

int main(int argc, char** argv) 
{
    // Declare local variables
    float quarts = 0.25f; // quarters
    float dimes  = 0.10f;
    float nicks  = 0.05f; // nickels
    
    int   input; // user's input
    float sum;   // the sum a certain coin
    float total; // the sum of all coins
    
    // Calculate the total sum of all quarters
    cout  << "How many quarters are there? ";
    cin   >> input;
    sum   = input * quarts;
    total = sum;
    // Calculate the total sum of all dimes
    cout  << "How many dimes are there? ";
    cin   >> input;
    sum   = input * dimes;
    total += sum;
    // Calculate the total sum of all nickels
    cout  << "How many nickels are there? ";
    cin   >> input;
    sum   = input * nicks;
    total += sum;
    // Print the total value of all coins
    if (total < 1.00)
    {
        cout << "The monetary value of the coins is: ";
        printf("%.02f", total);
        cout << " cent(s)";
    }
    else
    {
        cout << "The monetary value of the coins is: ";
        printf("%.02f", total);
        cout << " dollar(s)";
    }
    
    return 0;
}

