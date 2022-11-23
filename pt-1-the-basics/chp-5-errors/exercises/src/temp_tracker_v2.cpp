// This program collects day/temp values from user in a vector.
// It rejects invalid days of the week and writes out at the end
// the temps stored and the number of rejected values
#include <iostream>
#include <vector>

bool valid_day(const std::string s);

int main() {
  std::vector<std::string> days;
  std::vector<int> temps;

  std::string day;
  int temp;

  int rejected_entries = 0;

  // prompt user input
  std::cout << "Enter day/temp pairs e.g. Tues 23 (press ctrl+D to stop)\nPairs: ";
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

  std::cout << "\nDay:\t";
  for (std::string d: days) { std::cout << d << '\t'; }
  std::cout << "\nTemp:\t";
  for (int t: temps) { std::cout << t << '\t'; }
  std::cout << '\n';
  std::cout << "\nRejected entries: " << rejected_entries << '\n';

  return 0;
}

bool valid_day(std::string d) {
   // use to validate day input
  std::vector<std::string> valid_days = { "Monday", "Mon", "monday",
  "Tuesday", "Tues", "tuesday", "Wednesday", "Wed", "wednesday", "Thursday",
  "Thur", "thursday", "Friday", "Fri", "friday", "Saturday", "Sat", "Saturday",
  "Sunday", "Sun", "sunday" };

  for (std::string s: valid_days) {
    if (d == s) {
      return true;
    }
  }
  return false;
}
