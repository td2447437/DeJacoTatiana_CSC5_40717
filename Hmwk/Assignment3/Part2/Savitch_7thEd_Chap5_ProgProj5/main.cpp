/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 25, 2015, 10:54 AM
 * 
 * Homework:
 * Write a program that reads in 
 * - a length in feet and inches  
 * Outputs 
 * - the equivalent length in meters and centimeters. 
 * 
 * Use at least three functions: 
 * - one for input
 * - one or more for calculating 
 * - one for output. 
 * 
 * Include a loop that lets the user repeat this computation for new input values until the user says 
 * he or she wants to end the program.
 *  
 * There are 
 * - 0.3048 meters in a foot, 
 * - 100 centimeters in a meter, 
 * - 12 inches in a foot.
 * 
 */

#include <iostream>
using namespace std;

// Gets the length in ft and in
float getLength(string);
// Converts ft to meters
float convertFtToM(float);
// Converts in to meters
float convertInToM(float);
// Convert ft to cm
float convertFtToCm(float);
// Converts in to cm
float convertInToCm(float);
// Outputs the conversion
void outputResults(float, float);
// Ask user to repeat
bool askToRepeat();

int main(int argc, char** argv) 
{
    bool repeat = true; // assumes user wants to repeat calculation
    while (repeat)
    {
        // Declare variables
        float ft, in;
        // Gets two separate lengths in ft and in
        // These lengths are not equivalent
        ft = getLength("Length in ft: ");
        in = getLength("Length in inches: ");
        // OutputResults
        outputResults(ft, in);
        // Ask they user if they would like to repeat the calculation
        if ( askToRepeat() )
            continue;
        else
            repeat = false;
    }
    return 0;
}

float getLength(string s)
{
    float l; // the length given by user
    cout << s; cin >> l;
    return l;
}

// Converts ft to meters
float convertFtToM(float ft)
{
    float m = ft * 0.3048f;
    return m;
}

// Converts in to meters
float convertInToM(float in)
{
    float m = in * 0.0254f;
    return m;
}

// Convert ft to cm
float convertFtToCm(float ft)
{
    float cm = ft * 30.48f;
    return cm;
}

// Converts in to cm
float convertInToCm(float in)
{
    float cm = in * 2.54f;
    return cm;
}

void outputResults(float ft, float in)
{
    cout.setf(ios::fixed); cout.precision(2);
    cout << ft << "ft = " << convertFtToM(ft)   << " in meters"       << endl;
    cout << in << "in = "  << convertInToM(in)   << " in meters"       << endl;
    cout << ft << "ft = " << convertFtToCm(ft)  << " in centimeters" << endl;
    cout << in << "in = "  << convertInToCm(in)  << " in centimeters" << endl;
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
    