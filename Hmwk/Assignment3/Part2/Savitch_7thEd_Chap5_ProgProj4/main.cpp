/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 24, 2015, 4:12 PM
 * 
 * Homework:
 * Write a function that computes the average and standard deviation of four scores. 
 * The standard deviation is defined to be the square root of the average of the four values: 
 *      (s − a)^2 
 * where a is average of the four scores s1, s2, s3, and s4. 
 * 
 * The function will have six parameters and will call two other functions. 
 * Embed the function in a driver program that allows you to test the function 
 * again and again until you tell the program you are finished.
 */

#include <iostream>
#include <cmath>
using namespace std;

// Calculate average of four scores
float calcAverage(float, float, float, float);
// Calculate Variance: he average of the squared differences from the Mean
float calcVariance(float, float, float, float, float);
// Calculate standard deviation: the square root of the Variance
float calcStandardDeviation(float);
// Output results
float outputResult(float, float);
// Computes the average and standard deviation of four scores.
void compute(float, float, float, float, float, float);
// Ask user to repeat
bool askToRepeat();

int main(int argc, char** argv) 
{
    bool repeat = true; // assumes user wants to repeat calculation
    while (repeat)
    {
        float s1, s2, s3, s4;
        cout << "s1 = "; cin >> s1;
        cout << "s2 = "; cin >> s2;
        cout << "s3 = "; cin >> s3;
        cout << "s4 = "; cin >> s4;
        compute(s1, s2, s3, s4, 0, 0); 
        // Ask they user if they would like to repeat the calculation
        if ( askToRepeat() )
            continue;
        else
            repeat = false;
    }
    return 0;
}

// Computes the average and standard deviation of four scores.
void compute(float s1, float s2, float s3, float s4, float a, float v)
{
    // Calculate Average
    a = calcAverage(s1, s2, s3, s4);
    v = calcVariance(s1, s2, s3, s4, a);
    float sd = calcStandardDeviation(v);
    
    cout << "Average = " << a << endl;
    cout << "Standard Deviation = " << sd << endl;
}

// Calculate average of four scores
float calcAverage(float s1, float s2, float s3, float s4)
{
    float a = (s1 + s2 + s3 + s4) / 4;
    return a;
}

// Calculate Variance
float calcVariance(float s1, float s2, float s3, float s4, float a)
{
    // Declare variable
    float variance;
    // For each number: subtract the Mean and square the result
    s1 = pow( (s1 - a), 2 );
    s2 = pow( (s2 - a), 2 );
    s3 = pow( (s3 - a), 2 );
    s4 = pow( (s4 - a), 2 );
    // Then work out the mean of those squared differences.
    return variance = calcAverage(s1, s2, s3, s4);
}

// Calculate standard deviation
float calcStandardDeviation(float v)
{
    float result = sqrt(v);
    return result;
}

// Ask user to repeat calculation
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