/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 6, 2015, 5:11 PM
 * 
 * Homework: 
 * Modify the C++ program that you entered in Programming Project 1. Change the 
 * multiplication sign * in your C++ program to an addition sign +.
 * Recompile and run the changed program. Notice that the program compiles and
 * runs perfectly fine, but the output is incorrect. That is because this 
 * modification is a logic error.
 */

#include <iostream>
using namespace std;

void doProgProj1()
{
    // Declare local variables.
    int numberOfPods, peasPerPod, totalPeas;
    
    // Get the values of numberOfPods, peasPerPod from user.
    cout << "Press return after entering a number." << endl;
    cout << "Enter the number of pods: ";
    cin  >> numberOfPods;
    
    cout << "Enter the number of peas per pod: ";
    cin  >> peasPerPod;
    
    // Calculate totalPeas.
    totalPeas = numberOfPods + peasPerPod;
    
    // Print the values.
    cout << endl;
    cout << "If you have " << numberOfPods << " pea pods"           << endl;
    cout << "and "         << peasPerPod   << " peas per pod, then" << endl;
    cout << "you have "    << totalPeas    << " peas in total."     << endl;
    
    /* Prints: 
       "If you have ____ pea pods
        and ____ peas per pod, then
        you have ____ peas in total." */
    
}

int main(int argc, char** argv) 
{
    doProgProj1();
  
    return 0;
}

