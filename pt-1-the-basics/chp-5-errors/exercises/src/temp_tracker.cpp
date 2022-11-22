// This program stores and presents the avg. temperature of all the days of a
// given week, computes and presents the avg. temperature for the given week.
#include <iostream>
#include <vector>

inline void error(const std::string& s);

int main()
try {
  int weeks = 52, days = 7;
  std::vector<std::vector<int>> temperatures; // temperatures is a 2D vector
  temperatures.resize(weeks, std::vector<int>(days, 0)); // initialize as 52*7

  int week_number; // corresponds to a lvl-1 index of the temp vector
  std::string day; // mapped to a lvl-2 index of the temp vector
  int temp; // value at a lvl-2 index of the temp vector

  // get data from user
  std::cout << "Enter the week#: ";
  std::cin >> week_number;
  std::cout << "Enter the day: ";
  std::cin >> day;
  std::cout << "Enter the avg. temperature: ";
  std::cin >> temp;

  if (week_number < 1 || week_number > 52) { error("Invalid input for week#"); }
  if (temp < -90 || temp > 58) { error("Temperature input outside normals"); }

  if (day == "Mon" || day == "monday") {
    temperatures[week_number-1][0] = temp;
  } else if (day == "Tues" || day == "tuesday") {
    temperatures[week_number-1][1] = temp;
  } else if (day == "Wed" || day == "wednesday") {
    temperatures[week_number-1][2] = temp;
  } else if (day == "Thur" || day == "thursday") {
    temperatures[week_number-1][3] = temp;
  } else if (day == "Fri" || day == "friday") {
    temperatures[week_number-1][4] = temp;
  } else if (day == "Sat" || day == "saturday") {
    temperatures[week_number-1][5] = temp;
  } else if (day == "Sun" || day == "sunday") {
    temperatures[week_number-1][6] = temp;
  } else {
    error("Invalid input for day");
  }

  // this goes in a function that
  for (unsigned i = 0; i < temperatures.size(); ++i) {
    // add a function that takes a vector and compute the average
    std::cout << "Week: " << i+1 << " - "
              << temperatures[i][0] << ", "
              << temperatures[i][1] << ", "
              << temperatures[i][2] << ", "
              << temperatures[i][3] << ", "
              << temperatures[i][4] << ", "
              << temperatures[i][5] << ", "
              << temperatures[i][6] << '\n';
  }
  return 0;
} catch (std::exception& e) {
  std::cerr << "Error: " << e.what() << '\n';
  return 1;
} catch (...) {
  std::cerr << "Error: Unknown exception\n";
  return 2;
}


inline void error(const std::string& s) { throw std::runtime_error(s); }
