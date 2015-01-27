/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 21, 2015, 11:13 AM
 * 
 * 
 */

// System Libraries
#include <iostream>
using namespace std;

// User Libraries

// Global Constants
const float G = 6.673e-8f; // Weak force attraction constants in cm^3/g/sec^2

// Function Prototype
//       F          m1    m2      d
float atrForc(float, float, float);

// Execution Begins Here
int main(int argc, char** argv)
{
    // Declare Variables, Values found off Google
    float mEarth = 5.972e24f; //Earth's mass in kilograms
    float wtMark = 188.0f;       // Weight of Mark in lbs
    float rEarth   = 6.371e3f;  // Earth's radius in kilometers
    // COnvertions for consistent units
    mEarth *= 1e3f; // Convert to grams -> 10^3 g/kg
    float mMark = wtMark * 453.59; // 453.59 g /lb
    rEarth *= (1e3f * 1e2f); // 10^3 m/km * 10^2 cm m
    // Calculate the attractive force in dynes
    float dynes = atrForc(mEarth, mMark, rEarth);
    float lbs = dynes / 4.44822e5f; // Conversion 1 lb/ 4.44822e5
    // Output the results
    cout << "My Weight in dynes = " << dynes << endl;
    cout << "My Weight in lbs = " << lbs << endl;
    // Exit Stage Right
    return 0;
}

// Inputs:
//       F              m1          m2          d
float atrForc(float m1, float m2, float d)
{
    return G * m1 * m2 / d / d;
}