/* 
 * File:   main.cpp
 * Author: Tati
 * Created on February 4, 2015, 4:24 PM
 * 
 * Homework:
 * Write a function named firstLast2 that takes as input 
 * - an array of integers 
 * - an integer that specifies how many entries are in the array. 
 * The function should return true 
 * - if the array starts or ends with the digit 2. 
 * otherwise it should return false. 
 * 
 * Test your function with arrays of different length and with the digit 2 at 
 * the beginning of the array, end of the array, middle of the array, and 
 * missing from the array.
 * 
 */

#include <iostream>
using namespace std;

bool firstLast2(int [], int);
void printArray(int [], int);

int main(int argc, char** argv) 
{
    int size = 5;
    int array[size];
    
    cout << "Give me " << size << " numbers. ";
    cin  >> array[0] >> array[1] >> array[2] >> array[3] >> array[4];
    
    // Print array
    printArray(array, size);
    // Find digit 2
    firstLast2(array, size);
    
    return 0;
}

void printArray(int a[], int size)
{
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
}

bool firstLast2(int a[], int size)
{
    bool startsWith = false;
    bool endsWith   = false;
    bool hasTwo     = false;
    
    for (int i = 0; i < size; i++)
    {
        if (i == 0) // check if array starts with 2
        {
            if (a[i] == 2)
                startsWith = true;
        }
        else if (i == (size-1)) // check if array ends with 2
        {
            if (a[i] == 2)
                endsWith = true;
        }
        else continue;
    }
    
    if (startsWith && endsWith)
    {
        cout << "Array both starts and ends with a digit 2." << endl;
        hasTwo = true;
    }
    else if (startsWith)
    {
        cout << "Array starts with a digit 2." << endl;
        hasTwo = true;
    }
    else if (endsWith)
    {
        cout << "Array ends with a digit 2." << endl;
        hasTwo = true;
    }
    else
        cout << "Array does not start or end in digit 2.";
    
    return hasTwo;
}