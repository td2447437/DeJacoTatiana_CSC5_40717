/* 
 * File:   main.cpp
 * Author: Tati
 * Created on February 4, 2015, 6:29 PM
 * 
 * Homework: 
 * The following code creates a small phone book. An array is used to store a 
 * list of names and another array is used to store the phone numbers that go 
 * with each name. 
 * 
 * For example, Michael Myers’ phone number is 333- 8000 
 * and Ash Williams’ phone number is 333-2323. 
 * 
 * Write the function lookupName so the code properly looks up and returns 
 * the phone number for the input target name.
 * 
 */

#include <iostream>
using namespace std;

string lookupName(string, string [], string [], int);
int main(int argc, char** argv) 
{
    string names[] = {"Michael Myers", "Ash Williams",
                      "Jack Torrance", "Freddy Krueger"};
    string phoneNumbers[] = {"333-8000","333-2323", "333-6150","339-7970"};
    
    string targetName, targetPhone;
    char c;
    
    do
    {
         cout << "Enter a name to find the corresponding phone number. ";
         getline(cin, targetName);
         targetPhone = lookupName(targetName, names, phoneNumbers, 4);
         
        if (targetPhone.length() > 0)
            cout << "The number is: " << targetPhone << endl;
        else
            cout << "Name not found. " << endl;

        cout << "Look up another name? (y/n)" << endl;
        cin  >> c;
        cin.ignore();
    } 
    while (c == 'y');
    
    return 0;   
}

string lookupName(string targetName, string names[], string phoneNum[], int size)
{
    int indexOfTarget = 0;
    // Find the index of targetName
    for (int i = 0; i < size; i++)
    {
        if (names[i] == targetName)
            indexOfTarget = i;
    }
    
    // Find the it's corresponding phone numer
    for (int i = 0; i < size; i++)
    {
        if (i == indexOfTarget)
            return phoneNum[i];
    }
    return NULL;
}