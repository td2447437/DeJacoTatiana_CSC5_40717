/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 15, 2015, 10:33 AM
 * 
 * Homework:
 * Buoyancy is the ability of an object to float. Archimedes’ principle states 
 * that the buoyant force is equal to the weight of the fluid that is displaced 
 * by the submerged object. The buoyant force can be computed by
 * 
 * Fvb = V × y
 * 
 * Where Fvb is the buoyant force, V is the volume of the submerged object, 
 * and y is the specific weight of the fluid. 
 *  - If Fvb is greater than or equal to the weight of the object, 
 *    then it will float, otherwise it will sink.
 * 
 * Write a program that inputs 
 * - the weight (in pounds) and 
 * - radius (in feet) of a sphere and 
 * - outputs whether the sphere will sink or float in water. 
 * 
 * Use y = 62.4 lb/ft^3 as the specific weight of water. 
 * The volume of a sphere is computed by (4/3)πr^3.
 */

#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char** argv) 
{
    float w,         // weight of object
          r,         // radius of object
          PI = 3.14;
          
    cout << "Weight of Object (in lb): ";
    cin  >> w;
    cout << "Radius of Object (in ft): ";
    cin  >> r;
    
    // Calculate
    float v     = (4/3) * PI * pow(r, 3); // volume of object
    float y     = 62.4;                   // weight of fluid
    float force = v * y;                  // buoyant force
    
    // Output results
    if (force >= w)
        cout << "Object will float.";
    else
        cout << "Object will sink.";
    return 0;
}

