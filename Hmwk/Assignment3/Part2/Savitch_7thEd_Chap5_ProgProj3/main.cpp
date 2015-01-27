/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 24, 2015, 3:52 PM
 * 
 * Homework: 
 * Modify your program for Programming Project 2 so that it uses 12 hour notation, such as 3:45 PM.
 * 
 */

#include <iostream>
using namespace std;

// Combine two ints into one
int combine(int, int);
// Calculate and output the time after wait period
void calculateTime(int, int);
// Fixes Time if necessary
void formatTime(int);
// Asks user to repeat calculation
bool  askToRepeat();

int main(int argc, char** argv) 
{
    bool repeat = true; // assumes user wants to repeat calculation
    while (repeat)
    {
        // Declare variables
        int currHr, currMins, waitHr, waitMins, currTime, waitTime;
        // Prompt user for input
        cout << "Give time in 12-hr notation." << endl;
        cout << "Current Time: "; cin >> currHr; cin.ignore(); cin >> currMins;
        cout << "Wait Time: ";    cin >> waitHr; cin.ignore(); cin >> waitMins;
        // Combine hr and mins to get time
        currTime = combine(currHr, currMins);
        waitTime = combine(waitHr, waitMins);
        // Calculate and output time after wait period
        calculateTime(currTime, waitTime);
        // Ask they user if they would like to repeat the calculation
        if ( askToRepeat() )
            continue;
        else
            repeat = false;
    }
    return 0;
}

// Combine two ints into one
int combine(int a, int b)
{
    int times = 1;
    while (times <= b)
       times *= 10;
    return a * times + b;
}

// Calculate and output the time after wait period
void calculateTime(int currTime, int waitTime)
{
    int results;
    // Calculate time after wait period
    results = currTime + waitTime;
    formatTime(results);
}

// Fix Time if necessary and output the results
void formatTime(int time)
{
    // Separate the time 
    int array[4];
    int divide = 1000;
    for (int i = 0; i < 4; i++)
    {
        array[i] = time / divide % 10;
        divide /= 10;
    }
    // Combine the time into two ints: hr and mins
    int hr   = combine(array[0], array[1]); 
    int mins = combine(array[2], array[3]);
    // Fix the format for hr
    if (hr > 12)
        hr -= 12;
    // Fix the format for mins
    if (mins >= 60)
    {
        hr++;
        mins -= 60;
    }
    // Output the formatted time
    cout << "The time after the waiting period will be " << hr << ":" << mins << endl;
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

