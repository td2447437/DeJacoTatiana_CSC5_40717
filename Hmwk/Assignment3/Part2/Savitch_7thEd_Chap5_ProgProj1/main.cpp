/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 23, 2015, 10:31 PM
 * 
 * Homework:
 * Write a program that converts from 24-hour notation to 12-hour notation. For example, it should 
 * convert 14:25 to 2:25 PM. 
 * 
 * The input is given as two integers. 
 * 
 * There should be at least three functions, 
 * - one for input, 
 * - one to do the conversion, 
 * - and one for output. 
 * 
 * Record the AM/PM information as a value of type char, 'A' for AM and 'P' for PM. 
 * Thus, the function for doing the conversions will have a call-by-reference formal parameter of 
 * type char to record whether it is AM or PM. (The function will have other parameters as well.) 
 * 
 * Include a loop that lets the user repeat this computation for new input values again and again until 
 * the user says he or she wants to end the program.
 */

#include <iostream>
using namespace std;

// Gets the time from user
void getInput();
// Converts 24 hr notation to 12 hr notation
//                   hr  mins
void doConversion(int, int);
// outputs conversion
//                     hr mins am/pm
void outputResults(int, int, char);
// Asks user to repeat calculation
bool  askToRepeat();

int main(int argc, char** argv) 
{
    bool repeat = true; // assumes user wants to repeat calculation
    while (repeat)
    {
        // Gets the time from the user
        getInput();
        // Ask they user if they would like to repeat the calculation
        if ( askToRepeat() )
            continue;
        else
            repeat = false;
    }
    return 0;
}

void getInput()
{
    // Declare variables
    int hr, mins;
    // Prompt user for input
    cout << "Time (ex: 14:25): "; 
    cin >> hr; 
    cin.ignore(); 
    cin >> mins;
    // Convert time
    doConversion(hr, mins);
}

void doConversion(int hr, int mins)
{
    // Declare variables
    char ampm;
    // Converting 24hr to 12hr
    if (hr < 12)
        ampm = 'A';
    else if (hr == 12)
        ampm = 'P';
    else
    {
        hr = hr - 12;
        ampm = 'P';
    }
    outputResults(hr, mins, ampm);
}

//                      hr    mins    am/pm
void outputResults(int hr, int mins, char c)
{
    cout << "Time Converted: " 
          << hr << ":" << mins << " " << c << endl;
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