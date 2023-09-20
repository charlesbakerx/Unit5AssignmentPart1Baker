/*
Charles Baker, Programming Fundamentals I: COSC-1436-57001
IDE: Replit
Summary: A function that calculates and returns weekly pay taking into consideration taxes and overtime pay.
*/
#include "Input_Validation_Extended.h"
#include "Utilities.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

string blue = "\x1b[34;6m";
string green = "\x1b[32;6m";
string red = "\x1b[31;6m";
string reset = "\x1b[0m";
double weeklyPay(string name, double hoursWorked, double payRate, int empType);

int main() {
  cout << weeklyPay("Charles", 47, 505.75, 1) << endl << endl; 
  cout << weeklyPay("Melivin", 45, 55.25, 1) << endl << endl; 
  cout << weeklyPay("Susan", 15, 65.25, 2) << endl << endl; 
  cout << weeklyPay("Mika", 41, 14.75, 1) << endl << endl; 
  cout << weeklyPay("Eldridge", 25, 15.0, 2) << endl << endl; 
  cout << weeklyPay("Freedom", 55, 203.50, 1) << endl << endl; 
  cout << weeklyPay("Tyson", 32.5, 100.25, 1) << endl << endl; 

  cout << endl << allToLower("TCC-TR IS COOL") << endl;
  cout << allToUpper("i will succeed at c++");
  return 0; 
}

double weeklyPay(string name, double hoursWorked, double payRate, int empType) {
  double grossPay = 0, netPay = 0, denDuct = 0, retDuct = 0,
        fitTax = 0, socSec = 0, medicareTax = 0, taxableIncome = 0; 
  // If the employee makes $15 or greater an hour set the fitRate to 15% otherwise 12%
  double fitRate = (payRate >= 15) ? 0.15 : 0.12;
  // If the employee worked overtime we calculate 2 times pay on the hours worked over 40
  if (hoursWorked > 40) {
    grossPay = (hoursWorked - 40) * (payRate * 2);
    // Set hours worked to 40 so we don't calculate the overtime hours in the base pay as well.
    hoursWorked = 40;
  } // Now we calculate the base pay and add it to grossPay in the event that the employee worked overtime.
  grossPay += hoursWorked * payRate;
  netPay = grossPay;
  // If the employee is full time subtract the $17 and $77 otherwise we don't subtract anything.
  netPay -= (empType == 1) ? 94 : 0;
  // Take out FIT based on taxable income
  fitTax = netPay * fitRate;
  netPay -= fitTax;
  // Take out social security and medicare
  socSec = (grossPay * 0.062);
  medicareTax = (grossPay * 0.0145);
  netPay -= (socSec + medicareTax);

  // cout << color << allToUpper(name) << reset << ": $" << fixed << setprecision(2) << netPay << " : " << ((empType == 1) ? "Full time" : "Part time") << endl;

  cout << fixed << setprecision(2);
  cout << blue << allToUpper(name) << "'S" << reset << " Weekly Pay:" << endl;
  cout << green << "Status: " << reset << ((empType == 1) ? "Full-time" : "Part-time") << endl;
  cout << "Gross Pay: $" << grossPay << endl;
  cout << "Dental deduction (pre-tax): $17.00" << endl;
  cout << "Retirement deduction (pre-tax): $77.00" << endl;
  cout << "Taxable Wages: $" << taxableIncome << endl;
  cout << "Federal Income Tax: $" << fitTax << endl;
  cout << "Social Security Taxes: $" << socSec << endl;
  cout << "Medicare Taxes: $" << medicareTax << reset << endl;
  cout << blue << allToUpper(name) << "'S" << reset << " Net Pay is $"; 
  
  
  return netPay;
}