/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 26, 2015, 10:05 AM
 * 
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// User Libraries

// Global Constants

// Function Prototypes

// Execution Begins here
int main(int argc, char** argv) 
{
    // Initialize the random number seed
    srand( static_cast<unsigned int>( time(0) ) );
    // Declare 2 variables
    int x, y, begTime, endTime, ans, totTime;
    // Randomly choose 2 digits for each 
    x = rand() % 90 + 10;
    y = rand() % 90 + 10;
    totTime = 10;
    begTime = static_cast<unsigned int>( time(0) );
    // Prompt the user for an answer
    cout << "What is " << x << " + " << y << endl;
    cout << "You have " << totTime << " seconds to answer." << endl;
    cout << "Wait for the next prompt!!!" << endl;
    do
       endTime = static_cast<unsigned int>( time(0) );
    while(endTime - begTime < totTime);
    cout << "Your answer is? " << endl; cin >> ans;
    // Determine if correct
    if (ans == (x+y))
        cout << "You are correct" << endl;
    else
        cout << "You are wrong" << endl;
    // Exit Stage right
    return 0;
}