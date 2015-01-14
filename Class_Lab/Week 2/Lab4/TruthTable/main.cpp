/* 
 * File:   main.cpp
 * Author: Tati
 *
 * Created on January 13, 2015, 9:15 AM
 */

// System Libraries
#include <iostream>
using namespace std;

// User Libraries

// Global Constants

// Function Prototypes

// Execution Begins Here
int main(int argc, char** argv) 
{
    // Declare two boolean variables
    bool X, Y;
    // Output the heading
    cout << "X Y !X !Y X&&Y X||Y X^Y X^Y^Y ";
    cout << "X^Y^X !(X||Y) !X&&!Y !(X&&Y) !X||!Y " << endl;
    
    // First Row
    X = true; Y = true;
    cout << (X ? "T" : "F")                   << " "; 
    cout << (Y ? "T" : "F")                   << " ";
    cout << (!X ? " T" : " F")                << " "; 
    cout << (!Y ? " T" : " F")                << " ";
    cout << (X&&Y ? "   T" : "    F")         << " "; 
    cout << (X||Y ? "   T" : "   F")          << " ";
    cout << (X^Y ? "  T" : "  F")             << " "; 
    cout << (X^Y^Y ? "    T" : "    F")       << " ";
    cout << (X^Y^X ? "    T" : "    F")       << " "; 
    cout << (!(X||Y) ? "     T" : "     F")   << " ";
    cout << (!X&&!Y ? "      T" : "      F")  << " "; 
    cout << (!(X&&Y) ? "      T" : "      F") << " ";
    cout << (!X||!Y ? "     T" : "     F")    << endl;    
    
    // Second Row
    X = true; Y = false;
    cout << (X ? "T" : "F")                   << " "; 
    cout << (Y ? "T" : "F")                   << " ";
    cout << (!X ? " T" : " F")                << " "; 
    cout << (!Y ? " T" : " F")                << " ";
    cout << (X&&Y ? "  T" : "   F")           << " "; 
    cout << (X||Y ? "   T" : "   F")          << " ";
    cout << (X^Y ? "  T" : "  F")             << " "; 
    cout << (X^Y^Y ? "    T" : "    F")       << " ";
    cout << (X^Y^X ? "    T" : "    F")       << " "; 
    cout << (!(X||Y) ? "     T" : "     F")   << " ";
    cout << (!X&&!Y ? "      T" : "      F")  << " "; 
    cout << (!(X&&Y) ? "      T" : "      F") << " ";
    cout << (!X||!Y ? "     T" : "     F")    << endl;
    
    // Third Row
    X = false; Y = true;
    cout << (X ? "T" : "F")                   << " "; 
    cout << (Y ? "T" : "F")                   << " ";
    cout << (!X ? " T" : " F")                << " "; 
    cout << (!Y ? " T" : " F")                << " ";
    cout << (X&&Y ? "  T" : "   F")           << " "; 
    cout << (X||Y ? "   T" : "   F")          << " ";
    cout << (X^Y ? "  T" : "  F")             << " "; 
    cout << (X^Y^Y ? "    T" : "    F")       << " ";
    cout << (X^Y^X ? "    T" : "    F")       << " "; 
    cout << (!(X||Y) ? "     T" : "     F")   << " ";
    cout << (!X&&!Y ? "      T" : "      F")  << " "; 
    cout << (!(X&&Y) ? "      T" : "      F") << " ";
    cout << (!X||!Y ? "     T" : "     F")    << endl;
    
    // Fourth Row
    X = false; Y = false;
    cout << (X ? "T" : "F")                   << " "; 
    cout << (Y ? "T" : "F")                   << " ";
    cout << (!X ? " T" : " F")                << " "; 
    cout << (!Y ? " T" : " F")                << " ";
    cout << (X&&Y ? "  T" : "   F")           << " "; 
    cout << (X||Y ? "   T" : "   F")          << " ";
    cout << (X^Y ? "  T" : "  F")             << " "; 
    cout << (X^Y^Y ? "    T" : "    F")       << " ";
    cout << (X^Y^X ? "    T" : "    F")       << " "; 
    cout << (!(X||Y) ? "     T" : "     F")   << " ";
    cout << (!X&&!Y ? "      T" : "      F")  << " "; 
    cout << (!(X&&Y) ? "      T" : "      F") << " ";
    cout << (!X||!Y ? "     T" : "     F")    << endl;
    
    // Exit Stage Right
    return 0;
}

