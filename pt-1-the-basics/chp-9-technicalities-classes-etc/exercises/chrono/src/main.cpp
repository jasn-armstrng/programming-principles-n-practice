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

int main()
{
  // Test Date construction
  Date date { 23, Month::jul, 2023 };

  // Test Date member function outputs
  std::cout << date.dd() << ',' << date.mm() << ',' << date.yr() << '\n';
  std::cout << date.dd() << ' ' << date.mon() << ' ' << date.yr() << '\n';
  std::cout << date << '\n';

  return 0;
}
