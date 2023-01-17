// This program computes and prints a custom Fibonacci sequence; the first 2
// elements and the length of the sequence are controlled.
#include <iostream>
#include <vector>

std::vector<int> fibonacci(const int, const int, std::vector<int>&, const int);

int main() {

  return 0;
}

std::vector<int> fibonacci(const int x, const int y, std::vector<int>& v, const int n) {
  // computes a custom Fibonacci sequence
  // pre-conditions: x, y, n are +ve ints, v is vector<int> and empty
  // post-condtions: return vector with fibonacci sequence
  std::vector<int> v = {x, y}; // initialize with first 2 fibs - f0, f1
  for(int i = 2; i<n; ++i) {
    int next_fib = v[i-1]+v[i-2];
    v.push_back(next_fib);
  }

  return v;
}
