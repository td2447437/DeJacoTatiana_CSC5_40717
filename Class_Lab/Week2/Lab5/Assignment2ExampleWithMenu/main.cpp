/* 
 * File:   main.cpp
 * Author: Tati
 *
 * Created on January 14, 2015, 11:05 AM
 */

#include <iostream>

using namespace std;

/* Tenth One can be this menu with 9 assignments 
 do flowchart to individual problems not menu */

int main(int argc, char** argv) 
{
    int choice;
    
    cout << "Savitch 8thEd Chap 2 Prob 2" << endl;
    cout << "Savitch 9thEd Chap 2 Prob 3" << end;;
    cout << "Input which solution you would like to see: ";
    cin >> choice;
    
    switch(choice)
    {
        case 1:
        {
            cout << "You have choosen Solution 2" << endl;
            // Put program here!
            break;
        }
        case 2:
        {
            cout << "You have choosen Solution 3" << endl;
            // Put program here!
            break;
        }
        default: 
            cout << "Incorrect Choice!" << endl;            
    }
    return 0;
}

