#include <iostream>
#include <vector>
#include "../headers/compute_index.h"

inline void error(const std::string& s) { throw std::runtime_error(s); }

double compute_index(const std::vector<double> x, const std::vector<double> y) {
  // computes index: sum of all x[i]*y[i]
  // pre-conditions: vector x and y must be of same size and size > 0
  // post-conditions: return sum

  // Check if pre-conditions are met
  if(x.size() != y.size()) { error("Inputs are not the same size!"); }
  if(x.size() == 0 || y.size() == 0) { error("Input contains no data!"); }

  double sum {0};
  for(unsigned i = 0; i < x.size(); ++i) {
    sum += x[i]*y[i];
  }
  return sum;
}
