#include <iostream>
#include <vector>

class Vector_stats {
  public:
    double smallest;
    double largest;
    double mean;
    double median;

    void show_stats() {
      std::cout << "Smallest element: " << smallest << '\n';
      std::cout << "Largest element: " << largest << '\n';
      std::cout << "Mean: " << mean << '\n';
      std::cout << "Median: " << median << '\n';
    }
};

inline void error(const std::string& s) { throw std::runtime_error(s); }

Vector_stats compute_stats(std::vector<double> v) {
  // 1. find the smallest and largest element in input vector
  // 2. compute the mean and median of vector
  // pre-conditions: input vector is not empty
  // post-conditions: return struct with above values

  // check pre-condition
  if (v.size() ==  0) { error("Input has no data!"); }

  Vector_stats vs; // vector stats

  // 1. find smallest element in v
  vs.smallest = v[0];
  for(double i: v) {
    if(i < vs.smallest) { vs.smallest = i; }
  }

  // 2. find largest element in v
  vs.largest = v[0];
  for(double i: v) {
    if(i > vs.largest) { vs.largest = i; }
  }

  // 3. find mean
  vs.mean = 0;
  for(unsigned i = 0; i < v.size(); ++i) {
    vs.mean += v[i];
  }
  vs.mean = vs.mean/v.size();

  // 4. find median
  std::sort(v.begin(), v.end());
  double mid = v.size()/2;

  if (v.size()%2 != 0) {
    vs.median = v[mid];
  } else {
    vs.median = (v[mid]+v[mid-1])/2;
  }

  return vs;
}
