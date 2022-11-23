/*
  This program collects day/temp values from user and stores them in a vector.
  It rejects invalid days of the week and writes out at the end the temps stored
  and the number of rejected values.

  Sample output,
  Day:    Mon     Tues    Thur    Sat
  Temp:   23      24      23      24

  Rejected entries: 4
*/
#include <iostream>
#include <vector>

bool valid_day(const std::string s);
void ui();

int main() {
  std::cout << "+---------------------+\n";
  std::cout << "| Temperature Tracker |\n";
  std::cout << "+---------------------+\n\n";
  ui();
  return 0;
}

bool valid_day(std::string d) {
  // validate day input
  // pre-condition: d must be a string
  // post-condtion: return validation as a boolean value
  std::vector<std::string> valid_days = { "Monday", "Mon", "monday",
  "Tuesday", "Tues", "tuesday", "Wednesday", "Wed", "wednesday", "Thursday",
  "Thur", "thursday", "Friday", "Fri", "friday", "Saturday", "Sat", "Saturday",
  "Sunday", "Sun", "sunday" };

  for (std::string s: valid_days) { if (d == s) { return true; } }
  return false;
}

void ui() {
  std::vector<std::string> days;
  std::vector<int> temps;
  std::string day;
  int temp, rejected_entries = 0;

  std::string instructions =
  "How to use this program:\n"
  "- Enter day/temperature pairs e.g. Mon 23 Tuesday 24 ...\n"
  "- A valid day can take the forms Monday, monday, or Mon.\n"
  "- Invalid days will be rejected and total rejected displayed at the end.\n";

  std::cout << instructions;

  // prompt user input
  std::cout << "\nPlease enter day/temp pairs (press ctrl+D to stop)\nPairs: ";
  while (std::cin >> day >> temp) {
    // input validation for day
    if(!valid_day(day)) {
      ++rejected_entries;
    } else {
      // read in user input
      days.push_back(day);
      temps.push_back(temp);
    }
  }

  // output days, temps and no. of rejected entries to user
  std::cout << "\nDay:\t";
  for (std::string d: days) { std::cout << d << '\t'; }
  std::cout << "\nTemp:\t";
  for (int t: temps) { std::cout << t << '\t'; }

  std::cout << "\n\nRejected entries: " << rejected_entries << '\n';
}

// Test stream
// Mon 23 Tues 24 Thur 23 Funday 23 Sat 24 Subway 23 Monday 22 Chuesday 21
// Should reject 3
