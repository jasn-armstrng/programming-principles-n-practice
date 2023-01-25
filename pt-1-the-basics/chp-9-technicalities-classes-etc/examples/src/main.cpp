#include "../headers/chrono.h"
using namespace Chrono;

int main() try {
  Date today { 1978, Month::jun, 25 };
  Date same_date_next_year { today };
  same_date_next_year.add_year(1);
  std::cout << today << same_date_next_year << '\n';

  Date bad_day { 1980, Month::apr, 35};
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
