/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 12, 2015, 10:54 AM
 * Purpose: Use cmath functions sin, cos, and tan
 */

#include <cstdlib>  // Random rand(), srand()
#include <iostream> // Keyboard/Monitor I/O
#include <fstream>  // File I/O
#include <cmath>    // atan
#include <ctime>    // Time functions
#include <iomanip>  // Format Library

using namespace std;

// User Libraries

// Global Constants
const float PIDIV4 = atan(1);        // pi divided by 4
const float CONVERSION = PIDIV4/45; // from degrees to radians
// Function Prototypes

int main(int argc, char** argv) 
{
    // Set the random number seed
    srand (static_cast<unsigned int>(time(0)));
    // Declare a file object
    ofstream output;
    // Open the file
    output.open("SinCosTan.txt");
    // Declare the angle variable as an int in degrees
    // and the radian as a float
    int angDeg = rand() % 361 - 180; // gives # [-180, 180]
    float angRad = angDeg * CONVERSION;
    // Output angle to the screen
    cout << "Angle in degrees = " << angDeg << endl;
    cout << "Angle in radians = " << angRad << endl;
    // Output the sin, cos, tan
    cout << fixed  << setprecision(4) << showpoint;   
    cout << "sin(" << angDeg << ") = " << setw(8) << sin(angRad) << endl;
    cout << "cos(" << angDeg << ") = " << setw(8) << cos(angRad) << endl;
    cout << "tan(" << angDeg << ") = " << setw(8) << tan(angRad) << endl;
    // Output angle to the file
    output << "Angle in degrees = " << angDeg << endl;
    output << "Angle in radians = " << angRad << endl;
    // Output the sin, cos, tan
    output << fixed  << setprecision(4) << showpoint;   
    output << "sin(" << angDeg << ") = " << setw(8) << sin(angRad) << endl;
    output << "cos(" << angDeg << ") = " << setw(8) << cos(angRad) << endl;
    output << "tan(" << angDeg << ") = " << setw(8) << tan(angRad) << endl;
    // Close the stream
    output.close();
    return 0;
}

