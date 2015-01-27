/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 22, 2015, 12:55 PM
 * 
 * Homework:
 * Write an overloaded function max that takes 
 * - either two or three parameters of type double and 
 * - returns the largest of them.
 */

#include <iostream>
using namespace std;

// Returns the largest of the numbers.
float largestNum(float, float);
float largestNum(float, float, float);

int main(int argc, char** argv) 
{
    // Declare variables
    float x, y, z;
    // Prompt user for input
    cout << "x = "; cin >> x;
    cout << "y = "; cin >> y;
    cout << "z = "; cin >> z;
    // Output results
    cout << "Largest number is " << largestNum(x, y, z);
    return 0;
}

float largestNum(float x, float y)
{
    if (x > y)
        return x;
    else
        return y;
    
    return -1;
}

float largestNum(float x, float y, float z)
{
    if ( z > largestNum(x, y) )
        return z;
    else
        return largestNum(x, y);
    
    return -1; 
}