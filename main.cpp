/*
Charles Baker, Programming Fundamentals I: COSC-1436-57001
IDE: Replit
Summary: A function that calculates and returns weekly pay taking into consideration taxes and overtime pay.
*/
#include "Input_Validation_Extended.h"
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
  return 0; 
}

double weeklyPay(string name, double hoursWorked, double payRate, int empType) {
  double grossPay = 0, netPay = 0;
  // If the employee is full time (1) set the fitRate to 15% otherwise they are part time (2) so we set it to 12%
  double fitRate = (empType == 1) ? 0.15 : 0.12;
  
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
  
  return netPay;
}