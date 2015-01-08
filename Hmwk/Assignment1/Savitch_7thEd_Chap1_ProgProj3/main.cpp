/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 6, 2015, 5:02 PM
 * 
 * Homework: 
 * Further modify the C++ program that you already have modified in Programming
 * Project 2. Change the multiplication sign * in your C++ program to a division
 * sign /. Recompile the changes program. Run the program. Enter a zero input 
 * for "number of peas in a pod." Notice the run time error message due to 
 * division by zero.
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
    totalPeas = numberOfPods / peasPerPod;
    
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

