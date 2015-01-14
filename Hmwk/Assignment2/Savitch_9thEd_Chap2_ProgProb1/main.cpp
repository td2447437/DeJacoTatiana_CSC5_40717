/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 13, 2015, 7:33 AM
 * 
 * Homework: 
 * A government research lab has concluded that an artificial 
 * sweetener commonly used in diet soda pop will cause death in laboratory 
 * mice. A friend of yours is desperate to lose weight but cannot give up soda 
 * pop. * Your friend wants to know how much diet soda pop it is possible to 
 * drink without dying as a result.
 * 
 * Write a program to supply the answer.
 * 1. The input to the program is the amount of artificial sweetener needed to 
 *    kill a mouse, the weight of the mouse, and the weight of the dieter. 
 *    * To ensure the safety of your friend, be sure the program requests the  
 *    weight at which the dieter will stop dieting, rather than the dieter’s 
 *    current weight.
 * 
 * 2. Assume that diet soda contains 1/10th of 1% artificial sweetener. 
 *    Use a variable declaration with the modifier const to give a name to this 
 *    fraction. * You may want to express the percent as the double value 
 *    0.001. 
 * 
 * 3. Your program should allow the calculation to be repeated as often as the 
 *    user wishes. 
 */

#include <iostream>
#include <iomanip>  // Format Library
using namespace std;

const float amtOfSweetener = 0.001; // diet soda contains 1/10th of 
                                         // 1% artificial sweetener

int main(int argc, char** argv) 
{
    // Declare the variables
    string input;         // user input
    float  amtToKill,     // amount of sweetener to kill a mouse
           mouseWeight, 
           dieterWeight, 
           amtOfSoda;     // how much the dieter can drink without dying
    
    // Set the variables to user input
    cout << "What is the amount of sweetener is needed to kill a mouse? ";
    cin  >> amtToKill;
    cout << "What is the weight of the mouse? ";
    cin  >> mouseWeight;
    cout << "What will be the weight at which the dieter will stop dieting? ";
    cin  >> dieterWeight;
    cout << endl;
    
    // Calculate the amount of sweetener
    amtOfSoda = (amtToKill / mouseWeight) * dieterWeight;
    amtOfSoda = amtOfSoda / amtOfSweetener;
    cout << "You can drink " << amtOfSoda << " without dying" << endl;
    
    // Allow the calculation to be repeated as often as the user wishes. 
    cout << "Would you like to repeat calculation? ";
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

