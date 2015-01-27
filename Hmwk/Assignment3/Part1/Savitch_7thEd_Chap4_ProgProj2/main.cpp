/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 21, 2015, 4:03 PM
 * 
 * Homework:
 * Modify your program from Programming Project 1 so that it 
 * - will take input data for two cars and 
 * - output the number of miles per gallon delivered by each car. 
 * 
 * Your program will also announce which car has the best fuel efficiency (highest number of miles per gallon).
 */

#include <iostream>
using namespace std;

const float L = 0.264179f; // A liter is 0.264179 gallons.

// Get the data for a car
float getCarData();
// Compare the data for two cars
void  compareCars(float, float);
// get miles traveled per gallon
float milesPerGallon(float, float);
// ask user if they would like to repeat calculation
bool  askToRepeat();

int main(int argc, char** argv) 
{
    bool repeat = true; // assumes user wants to repeat calculation
    while (repeat)
    {
        float c1Miles,  // the number of miles per gallon car one traveled
               c2Miles; // the number of miles per gallon car two traveled
        // Get data for each car and calculate it's miles per gallon
        c1Miles = getCarData();
        c2Miles = getCarData();
        // Announce which car has the best fuel efficiency
        compareCars(c1Miles, c2Miles);
        // Ask they user if they would like to repeat the calculation
        if ( askToRepeat() )
            continue;
        else
            repeat = false; 
    }
    return 0;
}

float getCarData()
{
    // Declare variables
    float liters; // number of liters of gasoline
    float miles; // number of miles traveled by the car
    
    // Prompt user for liters of gasoline
    cout << "Number of liters consumed:   ";
    cin   >> liters;
    // Prompt user for number of miles 
    cout << "Number of miles traveled:    ";
    cin   >> miles;
    
    // Output the number of miles per gallon the car delivered
    cout.setf(ios::fixed); cout.precision(2);
    cout << "Car delivered " << milesPerGallon(liters, miles) << " miles per gallon." << endl;
    return milesPerGallon(liters, miles);        
}

void compareCars(float c1, float c2)
{
    if (c1 > c2)
        cout << "Car 1 has the best fuel efficiency." << endl;
    else
        cout << "Car 2 has the best fuel efficiency." << endl;
}

float milesPerGallon(float liters, float miles)
{
    // Convert liters to gallons
    float gallons          = liters * L;
    // Calculate miles per gallon
    float milesPerGallon = miles / gallons;
    return milesPerGallon;
}

bool askToRepeat()
{
    // Declare variables
    string input;  // user input
    
    // Ask user if repeat is wanted
    cout << "Repeat Calculation? ";
    cin  >> input;

    // Check if input is valid
    if (input == "yes")
        return true;
    else if (input == "no")
        return false;
    else
        askToRepeat();
    
    return false;
}