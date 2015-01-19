/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 6, 2015, 7:28 PM
 * 
 * Homework: 
 * A metric ton is 35,273.92 ounces. Write a program that will read the weight 
 * of a package of breakfast cereal in ounces and output the weight in metric 
 * tons as well as the number of boxes needed to produce one metric ton of 
 * cereal. Your program should allow the user to repeat this calculation as 
 * often as the user wishes.
 */

#include <iostream>
using namespace std;

const float OUNCES_IN_TON = 35273.92; // The amount of ounces in a metric ton

int calculate(string n)
{
    float weight;           // Weight of the cereal box in ounces 
    float convertedWeight;  // Weight of cereal converted into metric tons
    float total;            // the number of boxes needed to produce 
                            // one metric ton of cereal 
    
    // Read the weight of a package of breakfast cereal in ounces
    cout << "How many ounces is the cereal box? ";
    cin  >> weight; 
    
    // Output the weight in metric tons
    convertedWeight = weight / OUNCES_IN_TON;
    cout << n << "'s weight in metric tons is " << convertedWeight << endl;        
    // The number of boxes needed to produce one metric ton of cereal.
    total =  OUNCES_IN_TON / weight;
    cout << "You need " << total << " " << n << " boxes of cereal to produce"
         << " one metric ton."   << endl;
    
    string input;
    // Ask the user if they want to repeat this calculation
    cout << "Would you like to repeat this calculation? ";
    cin  >> input;
    
    if (input == "yes")
        calculate(n);
    else if (input == "no")
        return 0;
    else
    {
        cout << "What was that? yes or no? ";
        cin  >> input;
    }  
    return 0;
}

int main(int argc, char** argv) 
{   
    string name;  // The name of the cereal    
    cout << "What brand is the cereal? ";
    cin  >> name;

    calculate(name);

    return 0;
}