/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 14, 2015, 8:19 AM
 * 
 * Homework: 
 * Write a program that determines whether a meeting room is in violation of 
 * fire law regulations regarding the maximum room capacity. 
 * 
 * The program will:
 * 1. Read in the maximum room capacity and the number of people attending the 
 *    meeting. 
 * 2. If the number of people is less than or equal to the maximum room 
 *    capacity, the program announces that 
 *    - it is legal to hold the meeting and 
 *      tells how many additional people may legally attend. 
 * 3. If the number of people exceeds the maximum room capacity, 
 *    the program announces that 
 *    - the meeting cannot be held as planned due to fire regulations and tells  
 *      how many people must be excluded in order to meet the fire regulations. 
 * 
 * For a harder version, write your program so that it allows the calculation   
 * to be repeated as often as the user wishes. If this is a class exercise, ask 
 * your  instructor whether you should do this harder version.
 */

#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{
    // Declare variables
    string input;    // user input
    int maxCapacity; // maximum room capacity
    int numOfppl;    // the number of people attending
    
    // Read in the maximum room capacity and the number of people attending the 
    // meeting.
    cout << "What is the maximum room capacity? ";
    cin  >> maxCapacity;
    cout << "How many people are attending the meeting? ";
    cin  >> numOfppl;
    
    // If the number of people is less than or equal to the maximum room 
    // capacity, the program announces that...
    if (numOfppl <= maxCapacity)
    {
        cout << "  It is legal to hold the meeting."     << endl;
        cout << "  Number of attendees: " << numOfppl    << endl;
        cout << "  Maximum Capacity: "    << maxCapacity << endl;
    }
    // If the number of people exceeds the maximum room capacity, 
    // the program announces that...
    else
    {
        cout << "  The meeting cannot be held due to fire regulations." << endl;
        cout << "  Number of attendees: " << numOfppl    << endl;
        cout << "  Maximum Capacity: "    << maxCapacity << endl;
    } 

    // Ask to repeat
    cout << "Would you like the repeat calculation: ";
    cin  >> input;

    if (input == "yes")
        main(argc, argv);
    else if (input == "no")
        return 0;
    else
    {
        cout << "What was that? yes or no: ";
        cin  >> input;
    }
    
    return 0;
}

