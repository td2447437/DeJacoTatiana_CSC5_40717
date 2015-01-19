/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 17, 2015, 1:24 AM
 * 
 * Homework:
 * Holy digits Batman! The riddler is planning his next caper somewhere on 
 * Pennsylvania Avenue. in his usual sporting fashion, he has left the address 
 * in the form of a puzzle. The address on Pennsylvania is a four-digit 
 * number where:
 * 
 *    • All four digits are different
 *    • The digit in the thousands place is three times the digit 
 *      in the tens place 
 *    • The number is odd
 *    • The sum of the digits is 27
 * 
 * Write a program that uses a loop (or loops) to find the address where the 
 * riddler plans to strike.
 */

#include <iostream>
#include <cstdlib>
using namespace std;

/**
 * Condition 1: All four digits are different
 * @param testing - int array we are testing
 * @return true if all digits are different, false if not
 */
bool diff4Digits( int testing[] )
{
    // got through all instances in array and check for equality.
    if (testing[1] != testing[0])
    {
        if (testing[2] != testing[1] && testing[2] != testing[0])
        {
            if (testing[3] != testing[2] && testing[3] != testing[1] 
                && testing[3] != testing[0])
                return true;
        }
    }
    return false;
}

/**
 * Condition 3 - The number is odd
 * @param testing - int array we are testing
 * @return true if number is odd, false if not
 */
bool numIsOdd( int testing[] )
{
    if (testing[3] % 2 != 0)
        return true;
    else
        return false;
}

/**
 * Condition 4 - The sum of the digits is 27
 * @param testing - int array we are testing
 * @return true if sum is 27, false if not
 */
bool sumIs27( int testing[] )
{
    // sum of all numbers in address
    int sum = testing[0] + testing[1] + testing[2] + testing[3];           
    
    if (sum == 27)
        return true;
    else
        return false;
}

int main(int argc, char** argv) 
{
    srand( time(NULL) ); // set the seed
    
    while (true)
    {
        // Set the digits
        int address[4] = {
                            address[0] =  rand() % 9 + 1,
                            address[1] =  rand() % 3 + 1,
                            address[2] =  rand() % 9 + 1,
                            // Condition 2 - The digit in the thousands place 
                            // is three times the digit in the tens place
                            address[3] =  address[1] * 3 
                         };
    
        // Check if number meets conditions
        if (diff4Digits(address))
        {          
            if (numIsOdd(address))
            {
                if (sumIs27(address))
                {
                    // If the number meets all conditions then
                    // the address has been found
                    cout << "Batman! The Riddler is at ";
                    for (int i = 0; i < 4; i++)
                        cout << address[i];
                    break;
                }
            }
        }
    }
    return 0;
}