#pragma once

class Combinatorics {
  public:
    int factorial(const int n);
    int permutations(const int n, const int r);
    int combinations(const int n, const int r);
};

int Combinatorics::factorial(const int n) {
  // calculate n!
  // pre-conditions: input is a +ve integer
  // post-conditions: result fits into an int
  int f = 1;
  for (int i = n; i > 0; --i) { f *= i; }
  return f;
}

int Combinatorics::permutations(const int n, const int r) {
  // calculates permutations using the formula nPr = n!/(n-r)!
  // pre-conditions: n, r are +ve integers, n >= r
  // post-conditions: returns +ve integer result
  return factorial(n)/factorial(n-r);
}

int Combinatorics::combinations(const int n, const int r) {
  // calculates combinations using the formula nCr = n!/r!(n-r)!
  // pre-conditions: n, r are +ve integers, n >= r
  // post-conditions: returns +ve integer result
  return factorial(n)/(factorial(r)*factorial(n-r));
}
