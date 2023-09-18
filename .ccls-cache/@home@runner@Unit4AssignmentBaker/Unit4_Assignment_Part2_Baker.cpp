/*
Charles Baker, Programming Fundamentals I: COSC-1436-57001
IDE: Replit
Summary: Take an input for the amount of times to loop. Output on each loop the number of where we are in the loop followed by "Hello"
*/
#include "Input_Validation_Extended.h"
#include <cstdlib>
#include <iostream>
using namespace std;

void ordinals() {
  string promptString = "Please enter the amount of times to loop.";
  int input = validateInt(input, promptString);

  for (input; input >= 0; input--) {
    cout << input << " Hello!" << endl;
  }
}