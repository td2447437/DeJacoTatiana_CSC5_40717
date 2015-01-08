/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 6, 2015, 4:37 PM
 * 
 * Homework:
 * Modify the C++ program you entered in Programming Project 1. Change the 
 * program so that it first writes the word Hello to the screen and then goes on 
 * to do the same things that the program in Display 1.8 does. You will only
 * have to add one line to the program to make this happen. Recompile the changed
 * program and run the changed program. Then change the program even more. Add 
 * one more line that will make the program write the word Good-bye to the screen
 * at the end of the program. Be certain to add the symbols \n to the last output
 * statement so that it reads as follows:
 * cout << "Good-Bye\n";
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
    totalPeas = numberOfPods * peasPerPod;
    
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
    /* Part 1 of Homework: 
     * Change the program so that it first writes the word Hello to the screen 
     * and then goes on to do the same things that the program in Display 1.8 
     * does. */
    cout << "Hello" << endl;
    
    doProgProj1();
    
    /* Part 2 of Homework:
     * Add one more line that will make the program write the word Good-bye to 
     * the screen at the end of the program. Be certain to add the symbols \n 
     * to the last output statement so that it reads as follows:
     * cout << "Good-Bye\n"; */
    cout << "Good-Bye\n";

    return 0;
}

