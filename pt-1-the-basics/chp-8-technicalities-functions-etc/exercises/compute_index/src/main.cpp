// This program computes a value (an "index") that is sum of all
// price[i]*weight[i]
// See chp 8 ex. 9
#include <iostream>
#include <vector>
#include "../headers/compute_index.h"

int main() try {
  std::vector<double> price = {2.5, 3.5};
  std::vector<double> weight = {1, 2};
  std::cout << "Index: " << compute_index(price, weight) << '\n';
  return 0;
}
catch(std::exception& e) {
  std::cerr << "Error: " << e.what() << '\n';
  return 1;
}
catch(...) {
  std::cerr << "Error: Unknown exception" << '\n';
  return 2;
}
