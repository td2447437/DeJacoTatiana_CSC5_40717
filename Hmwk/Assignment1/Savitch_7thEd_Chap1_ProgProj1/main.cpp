/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 6, 2015, 4:09 PM
 * 
 * Homework: 
 * Using your text editor, enter (that is, type in) the C++ program shown in 
 * Display 1.8. Be certain to type the first line exactly as shown. 
 * In particular, be sure that the first line begins at the left-hand
 * end of the line with no space before or after the # symbol. Compile and run 
 * the program. Do this until the compiler gives no error messages. Then run 
 * the program.
 */

#include <iostream>
using namespace std;

int main(int argc, char** argv) 
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
    
    return 0;
}