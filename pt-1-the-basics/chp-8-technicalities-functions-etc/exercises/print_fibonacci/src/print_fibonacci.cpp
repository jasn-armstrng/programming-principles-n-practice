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

void gui() {
  // present program title and simple instructions for use
  std::string title {
    "+-----------------+\n"
    "| Print Fibonacci |\n"
    "+-----------------+\n\n"
  };

  std::string how_to {
    "x - first number in sequence\n"
    "y - second number in sequence\n"
    "n - number of elements in sequence to compute\n\n"
  };

  std::string input_prompt { "Enter x, y, and n: " };

  int x, y, n;
  std::cout << title << how_to << input_prompt;
  std::cin >> x >> y >> n;
  std::cout << '\n';
  fibonacci(x, y, v, n);
  print("Fibonacci Sequence", v);
}
