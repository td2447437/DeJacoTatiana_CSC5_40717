/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 25, 2015, 2:50 PM
 * 
 * Homework:
 * Write a program that combines the functions in the previous two programming projects. 
 * 
 * The program asks the user if he or she wants to 
 * - convert from feet and inches to meters and centimeters
 * - or convert from meters and centimeters to feet and inches. 
 * The program then performs the desired conversion. 
 * 
 * Have the user respond by typing the integer 1 for one type of conversion and 2 for the other conversion. 
 * The program reads the user’s answer and then executes an if-else statement. 
 * 
 * Each branch of the if-else statement will be a function call. 
 * The two functions called in the if-else statement will have function definitions that are very similar to 
 * the programs for the previous two programming projects. Thus, they will be fairly complicated function 
 * definitions that call other functions in their function bodies. 
 * 
 * Include a loop that lets the user repeat this computation for new input values until 
 * the user says he or she wants to end the program.
 * 
 */

#include <iostream>
using namespace std;

// Gets the length in ft and in
float getFtInches(string);
// Converts ft to meters
float convertFtToM(float);
// Converts in to meters
float convertInToM(float);
// Convert ft to cm
float convertFtToCm(float);
// Converts in to cm
float convertInToCm(float);
// Outputs the conversion
void outputFtInConversion(float, float);
// Does all the functions above
void doFtInConversion();

// Gets the length in ft and in
float getMCm(string);
// Converts ft to meters
float convertMToFt(float);
// Converts in to meters
float convertCmToFt(float);
// Convert ft to cm
float convertMToIn(float);
// Converts in to cm
float convertCmToIn(float);
// Outputs the conversion
void outputMCmConversion(float, float);
// Does all the functions above
void doMCmConversion();

// Ask user to repeat
bool askToRepeat();

int main(int argc, char** argv) 
{
    bool repeat = true; // assumes user wants to repeat calculation
    while (repeat)
    {
        // ans = 1 for one type of conversion 
        // ans = 2 for the other conversion.
        int ans; 
        cout << "Type 1 for conversion from feet and inches to meters and centimeters" << endl;
        cout << "Type 2 for conversion from meters and centimeters to feet and inches" << endl;
        cin >> ans;
        // Convert depending on ans
        if (ans == 1)
            doFtInConversion();
        else
            doMCmConversion();
        
        // Ask they user if they would like to repeat the calculation
        if ( askToRepeat() )
            continue;
        else
            repeat = false;
    }
}

void doFtInConversion()
{
    // Declare variables
    float ft, in;
    // Gets two separate lengths in ft and in
    // These lengths are not equivalent
    ft = getFtInches("Length in ft: ");
    in = getFtInches("Length in inches: ");
    // OutputResults
    outputFtInConversion(ft, in);
}

float getFtInches(string s)
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

void outputFtInConversion(float ft, float in)
{
    cout.setf(ios::fixed); cout.precision(2);
    cout << ft << "ft = " << convertFtToM(ft)   << " in meters"       << endl;
    cout << in << "in = "  << convertInToM(in)   << " in meters"       << endl;
    cout << ft << "ft = " << convertFtToCm(ft)  << " in centimeters" << endl;
    cout << in << "in = "  << convertInToCm(in)  << " in centimeters" << endl;
}

// Does all the functions above
void doMCmConversion()
{
    // Declare variables
    float m, cm;
    // Gets two separate lengths in ft and in
    // These lengths are not equivalent
    m  = getMCm("Length in meters: ");
    cm = getMCm("Length in centimeters: ");
    // OutputResults
    outputMCmConversion(m, cm);
}

float getMCm(string s)
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

void outputMCmConversion(float m, float cm)
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