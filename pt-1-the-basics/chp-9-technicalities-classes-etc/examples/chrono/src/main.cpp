// Testing the date class
#include "../headers/chrono.h"
using namespace Chrono;

int main() try {
  Date default_day; // test default day
  Date today { 1978, Month::jun, 25 }; // new date object initialization
  Date today_next_year { today };  // copy object. Note: cannot copy object.add_day(n)
  today_next_year.add_year(1);

  std::cout << "Default: " << default_day << '\n';
  std::cout << "Today: " << today << '\n';
  std::cout << "Today (next year): " << today_next_year << '\n';

  Date bad_day { 1980, Month::apr, 35}; // test error reporting with bad day
  return 0;
}
catch (Date::Invalid) {
  std::cerr << "Error: Invalid date\n";
  return 1;
}
catch (...) {
  std::cerr << "Error: Unknown exception\n";
  return 2;
}
