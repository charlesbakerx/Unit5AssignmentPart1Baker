#include <string>
using namespace std;

string allToUpper(string input) {
  string allUpper = "";
  for (char c : input) {
    char up = toupper(c);
    allUpper.push_back(up);
  }

  return allUpper;
}

string allToLower(string input) {
  string allLower = "";
  for (char c : input) {
    char up = tolower(c);
    allLower.push_back(up);
  }

  return allLower;
}