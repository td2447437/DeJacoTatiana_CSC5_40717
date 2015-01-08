/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 6, 2015, 5:21 PM
 * 
 * Homework: 
 * Write a C++ program that reads in two integers and then outputs both their 
 * sum and their product. One way to proceed is to start with the program in 
 * Display 1.8 and to then modify that program to produce the program for this 
 * project. Be certain to type the first line of your program exactly the same 
 * as the first line in Display 1.8. In particular, be sure that the first line 
 * begins at the left-hand end of the line with no space before or after the # 
 * symbol. Also, be certain to add the symbols \n to the last output statement 
 * in your program. For example, the last output statement might be the 
 * following:
 * cout << "This is the end of the program.\n";
 */

#include <iostream>
using namespace std;

int main(int argc, char** argv) 
{
    // Declare local variables
    int x, y, sum, product;
    
    // Read in two integers
    cout << "Enter a number: ";
    cin >> x;
    
    cout << "Enter another number: ";
    cin >> y;
    
    // Calculate the two integers' sum and product
    sum = x + y;
    product = x * y;
    
    // Output their sum
    cout << "The sum of " << x << " and " << y << " is " << sum << endl;
    // Output their product
    cout << "The product of " << x << " and " << y " is " << product << endl;
    // End the program
    cout << "This is the end of the program.\n";
    
    return 0;
}

