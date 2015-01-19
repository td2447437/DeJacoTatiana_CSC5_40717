/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 15, 2015, 7:38 AM
 * 
 * Homework:
 * Write a program that 
 * 1. Finds and prints all of the prime numbers between 3 
 *    and 100. A prime number is a number such that 1 and itself are the only 
 *    numbers that evenly divide it (for example, 3, 5, 7, 11, 13, 17, ...).
 * 
 * One way to solve this problem is to use a doubly nested loop. The outer 
 * loop can iterate from 3 to 100 while the inner loop checks to see if the 
 * counter value for the outer loop is prime. 
 * - one way to see if number n is prime is to loop from 2 to n-1 and if any 
 *   of these numbers evenly divides n, then n cannot be prime. if none of the 
 *   values from 2 to n-1 evenly divides n, then n must be prime. 
 *  (Note that there are several easy ways to make this algorithm more 
 *   efficient.)
 */

#include <iostream>
using namespace std;

short isPrime(short n)
{
    for (short i = 2; i < n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main(int argc, char** argv) 
{
    short end  = 10;  // end search at this number
    
    for (short i = 3; i < end; i++)
    { 
        if (isPrime(i))
            cout << i << endl;
    }  
}

