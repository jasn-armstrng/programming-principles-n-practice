// This program stores and presents the avg. temperature of all the days of a
// given week, computes and presents the avg. temperature for the given week.
#include <iostream>
#include <vector>

inline void error(const std::string& s);
double average(const std::vector<int> v);
void ui();

int main()
try {
  ui();
  return 0;

} catch (std::exception& e) {
  std::cerr << "Error: " << e.what() << '\n';
  return 1;
} catch (...) {
  std::cerr << "Error: Unknown exception\n";
  return 2;
}

inline void error(const std::string& s) { throw std::runtime_error(s); }

void ui(){
  int weeks = 3, days = 7;
  std::vector<std::vector<std::string>> temperatures; // temperatures is a 2D vector
  temperatures.resize(weeks, std::vector<std::string>(days, "-")); // initialize as 3*7

  int week_number; // corresponds to a lvl-1 index of the temp vector
  std::string day; // mapped to a lvl-2 index of the temp vector
  int temp; // value at a lvl-2 index of the temp vector

  char more_entries;
  bool data = true;

  while(data){
    // get data from user
    std::cout << "Enter the week#: ";
    std::cin >> week_number;
    std::cout << "Enter the day: ";
    std::cin >> day;
    std::cout << "Enter the avg. temperature: ";
    std::cin >> temp;

    if (week_number < 1 || week_number > 52) { error("Invalid input for week#"); }
    if (temp < -90 || temp > 58) { error("Temperature input outside normals"); }

    std::string str_temp = std::to_string(temp); // convert temp to store

    if (day == "Mon" || day == "monday") {
      temperatures[week_number-1][0] = str_temp;
    } else if (day == "Tues" || day == "tuesday") {
      temperatures[week_number-1][1] = str_temp;
    } else if (day == "Wed" || day == "wednesday") {
      temperatures[week_number-1][2] = str_temp;
    } else if (day == "Thur" || day == "thursday") {
      temperatures[week_number-1][3] = str_temp;
    } else if (day == "Fri" || day == "friday") {
      temperatures[week_number-1][4] = str_temp;
    } else if (day == "Sat" || day == "saturday") {
      temperatures[week_number-1][5] = str_temp;
    } else if (day == "Sun" || day == "sunday") {
      temperatures[week_number-1][6] = str_temp;
    } else {
      error("Invalid input for day");
    }

    // this goes in a function
    std::cout << "\n";
    std::cout << "Week\t" << "Mon\t" << "Tues\t" << "Wed\t"
              << "Thur\t" << "Fri\t" << "Sat\t" << "Sun\t\n";
    for (unsigned i = 0; i < temperatures.size(); ++i) {
      std::cout << i+1 << "\t"
                << temperatures[i][0] << "\t"
                << temperatures[i][1] << "\t"
                << temperatures[i][2] << "\t"
                << temperatures[i][3] << "\t"
                << temperatures[i][4] << "\t"
                << temperatures[i][5] << "\t"
                << temperatures[i][6] << '\n';
    }
    std::cout << "...";

    std::cout << "\nEnter another week/day/temp [y/n]: ";
    std::cin >> more_entries;
    if (more_entries == 'n' || more_entries == 'N') {
      data = false;
    }
  }
}
