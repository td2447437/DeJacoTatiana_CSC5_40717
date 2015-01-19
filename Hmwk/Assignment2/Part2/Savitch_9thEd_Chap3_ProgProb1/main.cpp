/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 16, 2015, 5:23 PM
 * 
 * Homework:
 * Write a program that computes the cost of a long-distance call. The cost of 
 * the call is determined according to the following rate schedule:
 * 
 * a. Any call started between 8:00am and 18:00pm, Monday through Friday, is 
 *    billed at a rate of $0.40 per minute.
 * b. Any call starting before 8:00 am or after 18:00 pm, Monday through Friday, 
 *    is charged at a rate of $0.25 per minute.
 * c. Any call started on a Saturday or Sunday is charged at a rate of 
 *    $0.15 per minute.
 *
 * The input will consist of 
 * - the day of the week, 
 * - the time the call started, 
 * - and the length of the call in minutes. 
 * 
 * The output will be the cost of the call. The time is to be input in 
 * 24-hour notation, so the time 1:30 pm is input as
 *       13:30
 * The day of the week will be read as one of the following pairs of character 
 * values, which are stored in two variables of type char:
 *       Mo  Tu  We  Th  Fr  Sa  Su
 * 
 * - Be sure to allow the user to use either uppercase or lowercase letters or
 *   a combination of the two. 
 * - The number of minutes will be input as a value of type int. 
 *   (You can assume that the user rounds the input to a whole number of 
 *   minutes.) 
 * 
 * Your program should include a loop that lets the user repeat this 
 * calculation until the user says she or he is done.
 */

#include <iostream>
using namespace std;

string day;      // day of call
short  hr, mins; // time of call
int    length;   // length of call in minutes
float  cost;     // cost of the call

void getDay()
{
    while (true)
    {
        cout << "Day of the call: ";
        cin  >> day;
        
        if (cin.fail())
            continue;
        else if (day == "Mo" || day == "Tu" || day == "We"|| day == "Th" || day == "Fr" || day == "Sa" || day == "Su"
                || day == "mo" || day == "tu" || day == "we"|| day == "th" || day == "fr" || day == "sa" || day == "su"
                || day == "MO" || day == "TU" || day == "WE"|| day == "TH" || day == "FR" || day == "SA" || day == "SU")
            break;
        else if (day == "Mo" || day == "Tu" || day == "We"|| day == "Th" || day == "Fr" || day == "Sa" || day == "Su"
                || day == "mo" || day == "tu" || day == "we"|| day == "th" || day == "fr" || day == "sa" || day == "su"
                || day == "MO" || day == "TU" || day == "WE"|| day == "TH" || day == "FR" || day == "SA" || day == "SU")
            break;
        else
            continue;
    }
}

void getTime()
{
    cout << "Time of call\n(24-hr notation): ";
    cin  >> hr;
    cin.ignore();
    cin  >> mins;
}

void getLength()
{
    cout << "Length of call\n(in minutes): ";
    cin  >> length;
}

void getInputs()
{
    getDay();
    getTime();
    getLength();  
}

void getCost()
{
    if (day == "Mo" || day == "Tu" || day == "We"|| day == "Th" || day == "Fr" 
      || day == "mo" || day == "tu" || day == "we"|| day == "th" || day == "fr"
      || day == "MO" || day == "TU" || day == "WE"|| day == "TH" || day == "FR")
    {
        if (hr >= 8 && hr <= 18)
            cost = 0.40 / length;
        else 
            cost = 0.25 / length;         
    }
    else   
        cost = 0.15 / length;
    
    // converting dollars to cents
    cost *= 100;
    if (cost > 1)
    {
        cout.setf(ios::fixed); cout.precision(0);
        cout << "Cost is " << cost << "¢" << endl;  
    }
    else
    {
        cout.setf(ios::fixed); cout.precision(2);
        cout << "Cost is $" << cost << endl;
    }
}

bool repeat()
{
    string input;  // user input
    
    // Ask user if repeat is wanted
    cout << "  Repeat Calculation? ";
    cin  >> input;
    
    while (true)
    {
        // Check if input is valid
        if (input == "yes")
            return true;
        else if (input == "no")
            return false;
        else
        {
            cout << "What was that? yes or no? ";
            cin  >> input;
        } 
    }  
}

int main(int argc, char** argv) 
{
    while (true)
    {
        // get day, hr, mins, length from user
        getInputs();
        // calculate the cost of call
        getCost();
        // Ask user if repeat is wanted and repeat if yes
        if (repeat())
            continue;
        else
            break; 
    }
    return 0;
}

