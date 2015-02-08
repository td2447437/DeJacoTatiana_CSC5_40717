/* 
 * File:   main.cpp
 * Author: Tati
 * Created on February 5, 2015, 6:53 PM
 * 
 * Homework:
 * Write a program that will 
 * - read a line of text and 
 * - output a list of all the letters that occur in the text 
 *   together with the number of times each letter occurs in the line. 
 * End the line with a period that serves as a sentinel value. 
 * 
 * The letters should be listed in the following order: the most 
 * frequently occurring letter, the next most frequently occurring letter, 
 * and so forth. 
 * 
 * Use two arrays, one to hold integers and one to hold letters. 
 * You may assume that the input uses all lowercase letters.
 * 
 * Your program will need to sort the arrays according to the values in the 
 * integer array. This will require that you modify the function sort given 
 * in Display 7.12. You cannot use sort to solve this problem without changing 
 * the function. 
 * 
 */

#include <iostream>
#include <sstream>
using namespace std;

int   readInput(char letters[], int); // returns size
// Counts how many times letter was repeated
void  count_repeats(char letters[], int repeats[], int);
// Delete the repeated letters as well as it's corresponding repeats
void   delete_repeats(char letters[], int repeats[], int); // returns new size
void  sortArray(char letters[], int repeats[], int);
void  printArray(char letters[], int repeats[], int);

int main(int argc, char** argv) 
{
    int  initSize = 1000; // maximum characters text can be
    char letters[1000];
    int  repeats[1000];
    
    // Prompt user for input
    cout << "Enter a text that is less than 1000 characters"            << endl;
    cout << "and then end your text with a period. Spaces are allowed." << endl;
    int size = readInput(letters, initSize);
    
    // Calculate number of repeated characters
    count_repeats(letters, repeats, size);
    delete_repeats(letters, repeats, size);
    sortArray(letters, repeats, size);
    printArray(letters, repeats, size);
    
    return 0;
}

// this method works fine
int readInput(char letters[], int initSize)
{
    int size = 0;
    char temp;
    for (int i = 0; i < initSize; i++)
    {
        cin >> temp;
        // Don't add spaces or periods to the array
        if (temp == '.')
            break;
        else // Will go here if input was a letter
        {
            letters[i] = temp;
            size++;
        }
    }
    return size;
}

// This method works fine
void count_repeats(char letters[], int repeats[], int size)
{ 
    int counter = 0;
    // Go through the array and count repeated characters
    for (int i = 0; i < size; i++)
    {
        counter++; // count itself
        for (int j = i+1; j < size; j++)
        {
            // If the character is repeated, count it
            if (letters[i] == letters[j])
            {
                counter++; // count repeats
                letters[j] = 0; // delete repeat
            }
        }
        
        if (letters[i] == 0)
            repeats[i] = 0; // there should be no number in corresponding 
        else
            repeats[i] = counter;
        
        counter = 0; // reset counter  
    }
}

void delete_repeats(char letters[], int repeats[], int size)
{
    // Go through and find all the deleted character
    for (int i = 0; i < size - 1; i++)
    {
        // If there is an empty space, move the next character forward.
        if (letters[i] == 0)
        {
            letters[i] = letters[i+1];
            letters[i+1] = 0; // because we moved it forward it now is empty
        }
        if (repeats[i] == 0)
        {
            repeats[i] = repeats[i+1];
            repeats[i+1] = 0; // because we moved it forward it now is empty
        }
    }
}

void sortArray(char letters[], int repeats[], int size)
{
    // sort repeats as well as it's corresponding letter from greatest to least 
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (repeats[i] < repeats[j])
            {
                // swap
                int temp   = repeats[i];
                repeats[i] = repeats[j];
                repeats[j] = temp;
                
                char c     = letters[i];
                letters[i] = letters[j];
                letters[j] = c;
            }
        }
    }
}

void printArray(char letters[], int repeats[], int size)
{
    // Display arrays
    for (int i = 0; i < size; i++)
    {
        if (repeats[i] != 0) // don't display if empty
            cout << letters[i] << " : " << repeats[i] << endl;
    }
}