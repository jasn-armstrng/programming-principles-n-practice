/**
 * @file main.cpp
 * @author Jason Armstrong
 * @brief
 * @version 0.1
 * @date 2023-02-10
 */

#include <iostream>
#include "../headers/chrono.h"

using namespace Chrono;

int main() try
{
  // Test Date construction
  Date date { 23, Month::jul, 2023 };

  // Test Date member function outputs
  std::cout << date.dd() << ',' << date.mm() << ',' << date.yr() << '\n';
  std::cout << date.dd() << ' ' << date.mon() << ' ' << date.yr() << '\n';
  std::cout << date << '\n';

  // Test bad date values, error throw and catch
  // Date date2 { 0, Month::jul, 2023 }; // day < 1
  // Date date2 { 33, Month::jul, 2023 }; // day > 31
  // Date date2 { 01, Month::jul, 10000 }; // year > 10000
  // Date date2 { 01, Month::jul, 0 }; // year < 1
  // Date date2 { 39, Month::feb, 2023 };

  Date date1 { 23, Month::jul, 2023 };
  Date date2 { 24, Month::jul, 2023 };

  // Test date comparison
  std::cout << (date == date1) << '\n';
  std::cout << (date == date2) << '\n';

  // Test feb 29 on leap year
  Date date4 { 29, Month::feb, 2024 };

  return 0;
}
catch(std::exception& e)
{
  std::cerr << "Error: " << e.what() << '\n';
  return 1;
}
catch(...)
{
  std::cerr << "Error: Unknown exception!\n";
  return 2;
}
