#include <iostream>
#include <vector>

struct stats {
  double smallest;
  double largest;
  double mean;
  double median;
};

inline void error(const std::string& s) { throw std::runtime_error(s); }

stats compute_stats(std::vector<double> v, stats& s) {
  // 1. find the smallest and largest element in input vector
  // 2. compute the mean and median of vector
  // pre-conditions: input vector is not empty
  // post-conditions: return struct with above values

  // check pre-condition
  if (v.size() ==  0) { error("Input has no data!"); }

  // find smallest element in v
  s.smallest = v[0];
  for(double i: v) {
    if(i < s.smallest) { s.smallest = i; }
  }

  // find largest element in v
  s.largest = v[0];
  for(double i: v) {
    if(i > s.largest) { s.largest = i; }
  }

  // find mean
  s.mean = 0;
  for(unsigned i = 0; i < v.size(); ++i) {
    s.mean += v[i];
  }
  s.mean = s.mean/v.size();

  // find median
  std::sort(v.begin(), v.end());
  double mid = v.size()/2;

  if (v.size()%2 != 0) {
    s.median = v[mid];
  } else {
    s.median = (v[mid]+v[mid-1])/2;
  }


  return s;
}
