/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 13, 2015, 4:47 PM
 * 
 * Homework:
 * Modify your program from Programming Project 2 so that it calculates the 
 * retroactive salary for a worker for any number of months, instead of just 
 * 6 months. The number of months is entered by the user.
 */

#include <iostream>
using namespace std;

const float payIncrease = 0.076; // pay increase

int main(int argc, char** argv) 
{
    // Declare Variables
    string input;        // user's input
    float prevSalary,    // employee's previous annual salary
          rPay,          // retroactive pay due the employee
          newSalary,     // employee's new annual salary
          monthlySalary,  // employee's new monthly salary
          numOfMonths;
    
    // Set the variables to the inputs
    cout << "Employee's Previous Annual Salary: ";
    cin  >> prevSalary;
    cout << "Retroactive salary for a worker for (months): ";
    cin  >> numOfMonths;
    
    // Calculate retroactive pay
    monthlySalary = prevSalary / 12;
    rPay          = (monthlySalary * payIncrease)* numOfMonths;
    // Calculate new annual salary
    monthlySalary = ((payIncrease * prevSalary) + prevSalary) / 12;
    newSalary = monthlySalary * 12;
    
    // Output results
    cout.setf(ios::fixed); cout.precision(2);
    cout << "  Retroactive pay due the employee: $" << rPay          << endl;
    cout << "  The new annual salary: $"            << newSalary     << endl;
    cout << "  The new monthly salary: $"           << monthlySalary << endl;
    
    // Ask to repeat
    cout << "Would you like the repeat calculation: ";
    cin  >> input;

    if (input == "yes")
        main(argc, argv);
    else if (input == "no")
        return 0;
    else
    {
        cout << "What was that? yes or no: ";
        cin  >> input;
    }
    
    return 0;
}

