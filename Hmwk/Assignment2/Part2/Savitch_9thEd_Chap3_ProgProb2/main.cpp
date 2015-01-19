/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 16, 2015, 9:42 PM
 * 
 * Homework:
 * (This Project requires that you know some basic facts about complex numbers, 
 * so it is only appropriate if you have studied complex numbers in some 
 * mathematics class.)
 * 
 * Write a C++ program that solves a quadratic equation to find its roots. 
 * The roots of a quadratic equation
 *      ax^2 + bx + c = 0
 * (where a is not zero) are given by the formula 
 *      ( –b ± sqrt(b^2 – 4ac) ) / 2a
 * 
 * The value of the discriminant (b^2 – 4ac) determines the nature of roots. 
 * - if the value of the discriminant is zero, then the equation  
 *   has a single real root. 
 * - if the value of the discriminant is positive then the equation 
 *   has two real roots. 
 * - if the value of the discriminant is negative, then the 
 *   equation has two complex roots.
 * 
 * The program 
 * - takes values of a, b, and c as input and 
 * - outputs the roots. 
 * 
 * Be creative in how you output complex roots. include a loop that allows the 
 * user to repeat this calculation for new input values until the user says she 
 * or he wants to end the program.
 */

#include <iostream>
#include <cmath>
#include <complex>
using namespace std;

float a, b, c,      // variables
          d;            // discriminant
float root1, root2; // solutions
    
void getInputs()
{
    cout << "a, b, and c: ";
    cin  >> a >> b >> c;
}

void calculate()
{
    // calculate discriminant
    cout.setf(ios::fixed); cout.precision(2);
    d = b*b - 4*a*c;
            
    // if the value of the discriminant is zero, then the equation  
    // has a single real root. 
    if (d == 0)
    {
        root1 = ( -(b*b) + sqrt(d) ) / (2*a);
        cout << "Discriminant is " << d << ", " << "Root(s): " << root1;
    }
    // if the value of the discriminant is positive then the equation 
    // has two real roots. 
    else if (d > 0)
    {
        root1 = ( -(b*b) + sqrt(d) ) / (2*a);
        root2 = ( -(b*b) - sqrt(d) ) / (2*a);
        cout << "Discriminant is " << d << ", ";
        cout << "Root(s): " << root1 << ", " << root2;
    }
    // if the value of the discriminant is negative, then the 
    // equation has two complex roots.
    else
    {
        float real,      // real part of solution
              imaginary; // imaginaru part of solution
        // Calculate solution
        real = -b / (2*a);
        imaginary = sqrt(-d) / (2*a);
        // Output solution
        cout << "Discriminant is " << d << endl;
        cout << "Complex Root(s): " << real << " + " << imaginary << "i" << ", ";
        cout << real << " - " << imaginary << "i";
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
        getInputs();
        cout << endl;
        calculate();
        cout << endl;
        // Ask user if repeat is wanted and repeat if yes
        if (repeat())
            continue;
        else
            break; 
        
    } 
    return 0;
}

