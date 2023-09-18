/*
Charles Baker, Programming Fundamentals I: COSC-1436-57001
IDE: Replit
Summary: Take an input from the user and if it is not -1 do 4 calculations on
the input and return the respective values with a message. If the input is -1
then output a message with the count of how many loops were done.
*/
#include "Input_Validation_Extended.h"
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
  string promptString =
      "Please enter a number with or without decimals (Not 0): ";
  double formula1, formula2, formula3, formula4, input;
  int counter = 0;

  do {
    input = validateDouble(input, promptString);
    // Check if input matches our exit code and break out if it does.
    if (input == -1)
      break;
    // Check if input is 0 so we don't get a division by 0 error and continue
    // the loop if it is.
    else if (input == 0) {
      cout << "Can not divide by 0! Please enter a different number." << endl;
      continue;
    }

    // Perform the various formulas on our input.
    formula1 = (input * input);
    formula2 = (input / input);
    formula3 = (input + 3) / 5;
    formula4 = ((input + 3) / 5) + ((input + 7) / 2);

    // Output all the results.
    cout << input << " * " << input << " = " << formula1 << endl;
    cout << input << " / " << input << " = " << formula2 << endl;
    cout << "(" << input << " + 3) / 5 = " << formula3 << endl;
    cout << "((" << input << " + 3) / 5) + ((" << input
         << " + 7) / 2) = " << formula4 << endl;

    // Increment our counter.
    counter++;
  } // So long as input isn't -1 we loop.
  while (input != -1);

  cout << "Exiting loop. You looped " << counter << " times!";

  return 0;
}