/*
This program finds the,
  1. smallest element
  2. largest element
  3. mean
  4. median
of a given vector
*/
#include <iostream>
#include <vector>
#include "../headers/stats_facilities.h"

int main() try {
  std::vector<double> t = {1, 3, 5, 7, 9};
  compute_stats(t).show_stats();

  return 0;
}
catch(std::exception& e) {
  std::cerr << "Error: " << e.what() << '\n';
  return 1;
}
catch(...) {
  std::cerr << "Error: Unknown exception\n";
  return 2;
}
