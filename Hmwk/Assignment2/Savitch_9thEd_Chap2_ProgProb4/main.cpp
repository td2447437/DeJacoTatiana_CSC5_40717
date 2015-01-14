/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 13, 2015, 5:18 PM
 * 
 * Homework:
 * Negotiating a consumer loan is not always straightforward. One form of loan 
 * is the discount installment loan, which works as follows. 
 * 
 * Suppose a loan has a face value of $1,000, the interest rate is 15%, and the 
 * duration is 18 months. 
 * * The interest is computed by multiplying the face 
 *   value of $1,000 by 0.15, to yield $150. That figure is then multiplied by 
 *   the loan period of 1.5 years to yield $225 as the total interest owed. 
 * 
 * That amount is immediately deducted from the face value, leaving the consumer   
 * with only $775. Repayment is made in equal monthly installments based on the  
 * face value. So the monthly loan payment will be $1,000 / 18, which is 
 * $55.56. This method of calculation may not be too bad if the consumer needs 
 * $775 dollars, but the calculation is a bit more complicated if the consumer 
 * needs $1,000. 
 * 
 * Write a program that
 * 1. Will take three inputs: 
 *    - the amount the consumer needs to receive, 
 *    - the interest rate, 
 *    - and the duration of the loan in months. 
 * 
 * 2. The program should then calculate 
 *    - The face value required in order for the 
 *      consumer to receive the amount needed. 
 *    - It should also calculate the monthly payment. 
 * 
 * 3. Your program should allow the calculations 
 *    to be repeated as often as the user wishes.
 */

#include <iostream>
using namespace std;

int main(int argc, char** argv) 
{
    // Declare variables
    string input;     // user input
    float loan,       // the amount the consumer needs to receive
          rate,       // the interest rate
          duration,   // the duration of the loan in months
          faceVal,    // face value of a loan
          monthlyPay; // monthly payment
    
    // Set the variables with user input
    cout << "The amount the consumer needs: ";
    cin  >> loan;
    cout << "The interest rate (percent): ";
    cin  >> rate;
    rate = rate / 100; // converting percent into decimal
    cout << "The duration of the loan (months): ";
    cin  >> duration;
    
    // Calculate the face value required in order
    // for the consumer to receive the amount needed.
    faceVal = loan / 1 - (rate * duration);
    // Calculate the monthly payment.
    monthlyPay = faceVal / duration;
    
    // Output the results
    cout.setf(ios::fixed); cout.precision(2);
    cout << "  The face value of the loan is $" << faceVal    << endl;
    cout << "  The monthly payment is $"        << monthlyPay << endl;
    
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

