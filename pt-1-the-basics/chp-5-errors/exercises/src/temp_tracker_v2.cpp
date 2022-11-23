// This program collects day/temp values from user in a vector.
// It rejects invalid days of the week and writes out at the end
// the temps stored and the number of rejected values
#include <iostream>
#include <vector>

int main() {
  std::vector<std::string> days;
  std::vector<int> temps;

  std::string day;
  int temp;

  // use to validate day input
  std::vector<std::string> valid_days = { "Mon", "monday", "Tues", "tuesday", "Wed",
  "wednesday", "Thur", "thursday", "Fri", "friday", "Sat", "Saturday", "Sun",
  "sunday" };

  std::cout << "Enter day/temp pairs e.g. Tues 23 (press ctrl+D to stop)\nPairs: ";
  while(std::cin >> day >> temp) {
    days.push_back(day);
    temps.push_back(temp);
  }

  std::cout << "\nDay:\t";
  for (std::string d: days) { std::cout << d << '\t'; }
  std::cout << "\nTemp:\t";
  for (int t: temps) { std::cout << t << '\t'; }
  std::cout << '\n';

  return 0;
}
