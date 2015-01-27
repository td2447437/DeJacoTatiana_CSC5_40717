/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 25, 2015, 2:17 PM
 * 
 * Homework: 
 * Write a program like that of the previous exercise that converts from 
 * - meters and centimeters into feet and inches. 
 * Use functions for the subtasks.
 */

#include <iostream>
using namespace std;

// Gets the length in ft and in
float getLength(string);
// Converts ft to meters
float convertMToFt(float);
// Converts in to meters
float convertCmToFt(float);
// Convert ft to cm
float convertMToIn(float);
// Converts in to cm
float convertCmToIn(float);
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
        float m, cm;
        // Gets two separate lengths in ft and in
        // These lengths are not equivalent
        m  = getLength("Length in meters: ");
        cm = getLength("Length in centimeters: ");
        // OutputResults
        outputResults(m, cm);
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
float convertMToFt(float m)
{
    float ft = m * 3.28084f;
    return ft;
}
    
// Converts in to meters
float convertCmToFt(float cm)
{
    float ft = cm * 0.0328084f;
    return ft;
}

// Convert ft to cm
float convertMToIn(float m)
{
    float in = m * 39.3701f;
    return in;
}

// Converts in to cm
float convertCmToIn(float cm)
{
    float in = cm * 0.393701f;
    return in;
}

void outputResults(float m, float cm)
{
    cout.setf(ios::fixed); cout.precision(2);
    cout << m  << "m = "    << convertMToFt(m)   << " in ft"       << endl;
    cout << cm << "cm = " << convertCmToFt(cm)  << " in ft"       << endl;
    cout << m  << "m = "    << convertMToIn(m)   << " in inches"  << endl;
    cout << cm << "cm = " << convertCmToIn(cm)  << " in inches"  << endl;
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