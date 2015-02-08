/* 
 * File:   main.cpp
 * Author: Tati
 * Created on February 4, 2015, 6:16 PM
 * 
 * Homework: 
 * Write a function named swapFrontBack that takes as input 
 * - an array of integers 
 * - and an integer that specifies how many entries are in the array. 
 * The function should 
 * - swap the first element in the array with the last element in the array. 
 * The function should check if the array is empty to prevent errors. 
 * 
 * Test your function with arrays of different length and with varying front 
 * and back numbers.
 */

#include <iostream>
using namespace std;

void swapFrontBack(int [], int);
void printArray(int [], int);

int main(int argc, char** argv) 
{
    int size = 5;
    int array[5] = {0};
    
    //Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < size; i++)
        array[i] = rand() % 9 + 1;
    
    // Print array
    cout << "Before swap: " << endl;
    printArray(array, size);
    // Swap front and back
    swapFrontBack(array, size);
     // Print array
    cout << endl << "After swap: " << endl;
    printArray(array, size);

    return 0;
}

void printArray(int a[], int size)
{
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
}

void swapFrontBack(int a[], int size)
{
    bool empty = false;
    // check if empty
    for (int i = 0; i < size; i++)
    {
        if (a[i] == 0)
            empty = true;
    }
    if (empty)
        cout << "Array is empty.";
    else
    {
        // Swap front and back
        int temp = a[0];
        a[0] = a[size - 1];
        a[size - 1] = temp;
    }
}