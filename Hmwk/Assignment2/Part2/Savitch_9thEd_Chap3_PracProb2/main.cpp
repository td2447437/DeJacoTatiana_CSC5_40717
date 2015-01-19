/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 14, 2015, 9:59 AM
 * 
 * Homework:
 * Write a program to compute 
 * - the interest due, 
 * - total amount due, 
 * - and the minimum payment for a revolving credit account. 
 * 
 * The program accepts the 
 * 1. Account balance as input, 
 * 2. Then adds on the interest to get the total 
 *    amount due. 
 * 
 * The rate schedules are the following: 
 * - The interest is 1.5% on the first $1,000 and 1 percent on any amount over 
 *   that. 
 * - The minimum payment is the total amount due if that is $10 or less; 
 *   otherwise, it is $10 or 10 percent of the total amount owed, whichever is 
 *   larger. 
 * 
 * Your program should include a loop that lets the user repeat this 
 * calculation until the user says she or he is done.
 */

#include <iostream>
using namespace std;

bool repeat()
{
    string input;  // user input
    
    // Ask user if repeat is wanted
    cout << "Repeat Calculation? ";
    cin  >> input;
    
    while (true)
    {
        // Check if input is valid
        if (input == "yes")
            return true;
        else if (input == "no")
            return false;
        else
        {
            cout << "What was that? yes or no? ";
            cin  >> input;
        } 
    }  
}

int main(int argc, char** argv) 
{
    float accBal,     // account balance
          interest,   // 1.5% on 1000, 1% over that
          totalDue,   // the total amount due
          minPayment; // minimum payment 
    
    // Include a loop that lets the user repeat this 
    // calculation until the user says she or he is done.
    while (true)
    {
        // Set variables with user inputs
        cout << "Account Balance: $";
        cin  >> accBal;
        
        // Calculate Interest due
        if (accBal <= 1000)
            interest = 1.5 / 100;
        else
            interest = 1 / 100;
        // Calculate total amount due
        totalDue = (accBal * interest) + accBal;
        cout.setf(ios::fixed); cout.precision(2);
        // Calculate minimum payment for credit account 
        if (totalDue <= 10)
            minPayment = totalDue;
        else
        {
            float t; // temporary variable
            t = totalDue * (1/100);
            if (t >= 10)
                minPayment = t;
            else
                minPayment = 10;
        }
        
        // Output Results
        cout << "Total Amount Due: $" << totalDue << endl;
        cout << "Minimum payment for a revolving credit account: $";
        cout << minPayment << endl;

        // Ask user if repeat is wanted and repeat if yes
        if (repeat())
            continue;
        else
            break;
        
    } 
    return 0;
}