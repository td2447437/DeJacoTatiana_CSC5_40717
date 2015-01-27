/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 23, 2015, 3:18 PM
 * 
 * Homework:
 * The price of stocks is sometimes given to the nearest eighth of a dollar; 
 * for example, 29 7/8 or 89 1/2. 
 * 
 * Write a program that computes the value of the user’s holding of one stock. 
 * The program asks for 
 * - the number of shares of stock owned, 
 * - the whole dollar portion of the price, 
 * - the fraction portion. 
 * The fraction portion is to be input as two int values, one for the numerator and one for the denominator. 
 * 
 * The program then outputs 
 * - the value of the user’s holdings. 
 * Your program should allow the user to repeat this calculation as often as the user wishes. 
 * 
 * Your program will include a function definition that has three int arguments consisting of 
 * - the whole dollar portion of the price  
 * - the two integers that make up the fraction part. 
 * The function returns the price of one share of stock as a single number of type double.
 * 
 */

#include <iostream>
using namespace std;

// A function declaration tells the compiler about a function's name, return type, and parameters. 
float stockShare(int, int, int); // The function returns the price of one share of stock
                                     // as a single number of type double
// ask user if they would like to repeat calculation
bool  askToRepeat();

int main(int argc, char** argv) 
{
    bool repeat = true; // assumes user wants to repeat calculation
    while (repeat)
    {
        // Declare variables
        int    shares,   // the number of shares of stock owned
               dollar,    // the whole dollar portion of the price
               numer,    // the fraction portion: numerator
               denom;   // the fraction portion: denominator
        float price;    // price of one share of stock as a single number
        // Prompt user for input
        cout << "The number of shares of stock owned: "; cin >> shares;
        cout << "The whole dollar portion of the price: "; cin >> dollar;
        cout << "The fraction portion of the price: ";      cin >> numer; cin.ignore(); cin >> denom;
        // Calculate price of one share of stock
        price = stockShare(dollar, numer, denom);
        price /= shares;
        // Output results
        cout.setf(ios::fixed); cout.precision(2);
        cout << "The value of the user's holdings: $" << price << endl; 
        // Ask they user if they would like to repeat the calculation
        if ( askToRepeat() )
            continue;
        else
            repeat = false;
    }
    return 0;
}

/***************************************************
 * Computes the value of the user's holdings
 * @param $ - the whole dollar portion of the price
 * @param n - fraction portion: numerator
 * @param d - fraction portion: denominator
 * @return the price of one share of stock as a 
 *             single number of type double
 ***************************************************/
// A function definition provides the actual body of the function.
float stockShare(int m, int n, int d)
{
    // Declare variables
    float results;
    float decimal;
    // Convert ints to floats
    float dollar = static_cast<float>(m);
    float numer = static_cast<float>(n);
    float denom = static_cast<float>(d);
    // Convert fraction to decimal
    if (n == d)
       results = dollar + 1;
    else
    {
        decimal = numer/denom;
        results = dollar + decimal;
    }
    return results;
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