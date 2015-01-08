/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 6, 2015, 5:38 PM
 * 
 * Homework: 
 * The purpose of this exercise is to produce a catalog of typical syntax errors 
 * and error messages that will be encountered by a beginner, and to continue 
 * acquainting you with the programming environment. This exercise should leave 
 * you with a knowledge of what error to look for when given any of a number of 
 * common error messages.
 * 
 * Your instructor may have a program for you to use for this exercise. If not, you 
 * should use a program from one of the previous Programming Projects.
 * 
 * Deliberately introduce errors to the program, compile, record the error and the 
 * error message, fix the error, compile again (to be sure you have the program 
 * corrected), then introduce another error. Keep the catalog of errors and add 
 * program errors and messages to it as you continue through this course.
 * 
 * The sequence of suggested errors to introduce is:
 * 
 * a. Put an extra space between the < and the iostream file name.
 * b. Omit one of the < or > symbols in the include directive.
 * c. Omit the int from int main().
 * d. Omit or misspell the word main.
 * e. Omit one of the (), then omit both the ().
 * f. Continue in this fashion, deliberately misspelling identifiers (cout, cin,
 *    and so on). Omit one or both of the << in the cout statement; leave off 
 *    the ending curly brace }.
 */

#include < iostream
using namespace std;

mian int argc, char** argv 
{
    /* This program is from Programming Project 5 */
    
    // Declare local variables
    int x, y, sum, pro;
    
    // Read in two integers
    coute << "Enter a number: ";
    ci >> x;
    
    cout << "Enter another number: ";
    cin >> y;
    
    // Calculate the two integers' sum and product
    sum = x + y;
    product = x * y;
    
    // Output their sum
    cout < "The sum of " << x << " and " << y << " is " << sum << endl;
    // Output their product
    cout << "The product of " << x << " and " << y " is " << product << endl;
    // End the program
    cout << "This is the end of the program.\n";
    
    return 0;


