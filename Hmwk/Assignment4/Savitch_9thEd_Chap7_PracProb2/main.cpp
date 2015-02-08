/* 
 * File:   main.cpp
 * Author: Tati
 * Created on February 4, 2015, 5:20 PM
 * 
 * Homework: 
 * Write a function named countNum2s that takes as input 
 * - an array of integers 
 * - and an integer that specifies how many entries are in the array. 
 * The function should return 
 * - the number of 2’s in the array. 
 * 
 * Test your function with arrays of different length 
 * and with varying number of 2’s.
 */

#include <iostream>
using namespace std;

int countNum2s(int a[], int size);
void printArray(int [], int);

int main(int argc, char** argv) 
{
    int size = 5;
    int array[size];
    int numOf2s = 0;
    
    cout << "Give me " << size << " numbers. ";
    cin  >> array[0] >> array[1] >> array[2] >> array[3] >> array[4];
    
    // Print array
    printArray(array, size);
    // Count the number of 2's
    numOf2s = countNum2s(array, size);
    cout << "The number of 2's in array is: " << numOf2s << endl;
    
    return 0;
}

void printArray(int a[], int size)
{
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
}


int countNum2s(int a[], int size)
{
    int counter = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] == 2)
            counter++;
    }
    
    return counter;
}