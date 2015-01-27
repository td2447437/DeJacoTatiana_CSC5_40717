/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 12, 2015, 10:04 AM
 * Purpose: Illustrate file i/o and random
 */

#include <cstdlib>  // Random rand(), srand()
#include <iostream> // Keyboard/Monitor I/O
#include <fstream>  // File I/O
#include <ctime>    // Time functions

using namespace std;

// User Libraries

// Global Constants

// Function Prototypes

// Execution Begins here
int main(int argc, char** argv) 
{
    // Set the random number seed
    srand (static_cast<unsigned int>(time(0)));
    // Declare a file object
    ofstream output;
    // Open the file
    output.open("RollTheDice.txt");
    // Declare 5 dice
    unsigned short die1, die2, die3, die4, die5;
    // Set the values for each dice
    die1 = rand() % 6 + 1; // gives # from 1 to 6
    die2 = rand() % 6 + 1;
    die3 = rand() % 6 + 1;
    die4 = rand() % 6 + 1;
    die5 = rand() % 6 + 1;
    // Output the results tot he screen
    cout << " Yahtzee first roll = ";
    cout << die1 << " " << die2 << " ";
    cout << die3 << " " << die4 << " " << die5 << endl;
    // Output the results to the file
    output << " Yahtzee first roll = ";
    output << die1 << " " << die2 << " "; 
    output << die3 << " " << die4 << " " << die5 << endl;   
    // Close the stream
    output.close();
    return 0;
}