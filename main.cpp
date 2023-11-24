/*******************************************************************************
This program determines the monthly payments on a
mortgage given the loan amount, the yearly interest,
and the number of years.
*******************************************************************************/
#include <iostream>                         // Access cout
#include <cmath>                            // Access power function
#include <fstream>                          // Access to I/O functions
#include <string>                           // Access string objects
using namespace std;
float LOAN_AMOUNT;                          // Amount of loan
float YEARLY_INTEREST;                      // Yearly interest
int NUMBER_OF_YEARS;                        // Number of years
float monthlyInterest;                      // Monthly interest rate
int numberOfPayments;                       // Total number of payments
float payment;                              // Monthly payment
ofstream outData;                           // Link to output file
string mortPay = "Mortgage Plan(s)";        /* Output file name; allows user to 
                                            output data to this file (change #1)*/

int main()
{
    // Open output file
    outData.open(mortPay.c_str());
    
    // Prompt user for loan amount, yearly interest, and years (change #2)
    cout << "Enter the loan amount (0 to exit): ";
    cin >> LOAN_AMOUNT;
    
    while (LOAN_AMOUNT != 0){               /* allows user to calulate multiple 
                                            loans w/o exiting program (change #3)*/
    
        cout << "Enter the yearly interest: ";
        cin >> YEARLY_INTEREST;
    
        cout << "Enter the number of years: ";
        cin >> NUMBER_OF_YEARS; cout << endl;
    
        // Calculate values
        monthlyInterest = YEARLY_INTEREST / 12;
        numberOfPayments = NUMBER_OF_YEARS * 12;
        payment =(LOAN_AMOUNT *
              pow(monthlyInterest + 1, numberOfPayments)
              * monthlyInterest)/(pow(monthlyInterest + 1,
              numberOfPayments) - 1);
              
        // Output results to screen
        cout << "For a loan amount of "
            << LOAN_AMOUNT  << " with an interest rate of "
            << YEARLY_INTEREST << " and a "
            << NUMBER_OF_YEARS
            << " year mortgage, " << endl;
        cout << " your monthly payments are $" << payment
            << "." << endl;
            
        // Output results to file
        outData << "For a loan amount of "
            << LOAN_AMOUNT  << " with an interest rate of "
            << YEARLY_INTEREST << " and a "
            << NUMBER_OF_YEARS
            << " year mortgage, " << endl;
        outData << " your monthly payments are $" << payment
            << "." << endl;
            
        // Prompt user for another loan amount 
        cout << endl << "Enter another loan amount (0 to exit): ";  // user can exit or go to loop
        cin >> LOAN_AMOUNT;
        
    }
    // Close file
    outData.close();
    
    return 0;
}
