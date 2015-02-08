/* 
 * File:   main.cpp
 * Author: Tati
 * Created on February 4, 2015, 6:59 PM
 * 
 * Homework: 
 * Write a function called delete_repeats that has a partially filled array of 
 * characters as a formal parameter and that deletes all repeated letters from 
 * the array. 
 * 
 * Since a partially filled array requires two arguments, the function will 
 * actually have two formal parameters: 
 * - an array parameter 
 * - and a formal parameter of type int that gives the number of array 
 *   positions used. 
 * 
 * When a letter is deleted, the remaining letters are moved forward to fill 
 * in the gap. This will create empty positions at the end of the array so that 
 * less of the array is used. 
 * 
 * Since the formal parameter is a partially filled 
 * array, a second formal parameter of type int will tell how many array 
 * positions are filled. 
 * 
 * This second formal parameter will be a 
 * call-by-reference parameter and will be changed to show how much of the 
 * array is used after the repeated letters are deleted.
 * 
 */

#include <iostream>
using namespace std;

// Deletes all repeated letters from array
void delete_repeats(char [], int);
void printArray(char [], int);

int main(int argc, char** argv) 
{
    char array[10];
    array[0] = 'a';
    array[1] = 'b';
    array[2] = 'a';
    array[3] = 'c';
    int size = 4;
    cout << " Before removing: ";
    printArray(array, size);
    delete_repeats(array, size);
    cout << " After removing:  ";
    printArray(array, size);
    return 0;
}

void printArray(char a[], int size)
{
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
}

void delete_repeats(char a[], int size)
{
    // Go through and find the repeated characters
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            // If the character is repeated, delete it
            if (a[i] == a[j]) 
                a[j] = 0;
            else
                continue;
        }
    }
    
    // Go through and find all the deleted character
    for (int i = 0; i < size - 1; i++)
    {
        // If there is an empty space, move the next character forward.
        if (a[i] == 0)
        {
            a[i] = a[i+1];
            a[i+1] = 0; // because we moved it forward it now is empty
        }
        else
            continue;
    }
}