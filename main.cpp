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

string color = "\x1b[34;6m";
string reset = "\x1b[0m";
double weeklyPay(string name, double hoursWorked, double payRate, int empType);

int main() {
  weeklyPay("Charles", 47, 505.75, 1);
  weeklyPay("Melivin", 45, 55.25, 1);
  weeklyPay("Susan", 15, 65.25, 2);
  weeklyPay("Mika", 41, 14.75, 1);
  weeklyPay("Eldridge", 25, 15.0, 2);
  weeklyPay("Freedom", 55, 203.50, 1);
  weeklyPay("Tyson", 32.5, 100.25, 1);
  return 0; 
}

double weeklyPay(string name, double hoursWorked, double payRate, int empType) {
  double grossPay = 0, netPay = 0;
  // If the employee makes $15 or greater an hour set the fitRate to 15% otherwise 12%
  double fitRate = (payRate >= 15) ? 0.15 : 0.12;
  
  // If the employee worked overtime we calculate 2 times pay on the hours worked over 40
  if (hoursWorked > 40) {
    grossPay = (hoursWorked - 40) * (payRate * 2);
    // Set hours worked to 40 so we don't calculate the overtime hours in the base pay as well.
    hoursWorked = 40;
  } // Now we calculate the base pay and add it to grossPay in the event that the employee worked overtime.
  grossPay += hoursWorked * payRate;
  // Set netPay to grossPay because FIT is calculated based off of taxable income not gross pay
  netPay = grossPay;
  // If the employee is full time subtract the $17 and $77 otherwise we don't subtract anything.
  netPay -= (empType == 1) ? 94 : 0;
  // Take out FIT based on taxable income
  netPay -= (netPay * fitRate);
  // Take out social security and medicare
  netPay -= ((grossPay * 0.062) + (grossPay * 0.0145));

  cout << color << allToUpper(name) << reset << ": $" << fixed << setprecision(2) << netPay << " : " << ((empType == 1) ? "Full time" : "Part time") << endl;
  
  return netPay;
}