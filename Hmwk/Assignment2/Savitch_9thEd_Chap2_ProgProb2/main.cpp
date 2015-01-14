/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 13, 2015, 8:52 AM
 * 
 * Homework: 
 * Workers at a particular company have won a 7.6% (0.076) pay increase 
 * retroactive for six months. 
 * 
 * Write a program that; 
 * 1. Takes an employee’s previous annual salary as input 
 * 
 * 2. outputs:
 *    - the amount of retroactive pay due the employee, 
 *    - the new annual salary, 
 *    - and the new monthly salary. 
 * 
 * 3. Use a variable declaration with the modifier const to express the 
 *    pay increase. 
 * 
 * 4. Your program should allow the calculation to be repeated as 
 *    often as the user wishes.
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
          monthlySalary; // employee's new monthly salary
    
    // Set the variables to the inputs
    cout << "Employee's Previous Annual Salary: ";
    cin  >> prevSalary;
    
    // Calculate retroactive pay
    monthlySalary = prevSalary / 12;
    rPay          = (monthlySalary * payIncrease)* 6;
    // Calculate new annual salary
    monthlySalary = ((payIncrease * prevSalary) + prevSalary) / 12;
    newSalary     = monthlySalary * 12;
    
    // Output results
    cout.setf(ios::fixed); cout.precision(2);
    cout << "  Retroactive pay due the employee: " << rPay          << endl;
    cout << "  The new annual salary: "            << newSalary     << endl;
    cout << "  The new monthly salary: "           << monthlySalary << endl;
    
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

