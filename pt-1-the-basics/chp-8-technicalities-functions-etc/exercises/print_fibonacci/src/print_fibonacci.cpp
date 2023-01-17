// This program computes and prints a custom Fibonacci sequence; the first 2
// elements and the length of the sequence are controlled.
#include <iostream>
#include "../headers/print_fibonacci.h"

std::vector<int> v;

std::vector<int> fibonacci(const int x, const int y, std::vector<int>& v, const int n) {
  // computes a custom Fibonacci sequence
  // pre-conditions: x, y, n are +ve ints, v is vector<int> and empty
  // post-condtions: return vector with fibonacci sequence
  v.push_back(x);
  v.push_back(y);
  for(int i = 2; i<n; ++i) {
    int next_fib = v[i-1]+v[i-2];
    v.push_back(next_fib);
  }
  return v;
}

void print(const std::string label, const std::vector<int>& v) {
  // prints a label and the values it describes
  std::cout << label << '\n';
  for(int f: v) {
    std::cout << f << '\n';
  }
};
