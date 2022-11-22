// This program stores and presents the avg. temperature of all the days of a
// given week, computes and presents the avg. temperature for the given week.
#include <iostream>
#include <vector>
int main(){
  int weeks = 52, days = 7;
  std::vector<std::vector<int>> temperatures; // temperatures is a 2D vector
  temperatures.resize(weeks, std::vector<int>(days, 0)); // initialize as 52*7

  int week_number; // corresponds to a lvl-1 index of the temp vector
  std::string day; // mapped to a lvl-2 index of the temp vector
  int temp; // value at a lvl-2 index of the temp vector

  // get data from user
  std::cout << "Enter the week#: ";
  std::cin>>week_number;
  std::cout << "Enter the day: ";
  std::cin>>day;
  std::cout << "Enter the avg. temperature: ";
  std::cin>>temp;

  return 0;
}
