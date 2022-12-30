#pragma once

class Combinatorics {
  public:
    long long factorial(const int n);
    long long permutations(const int n, const int r);
    long long combinations(const int n, const int r);
};

long long Combinatorics::factorial(const int n) {
  // calculate n!
  // pre-conditions: input is a +ve integer
  // post-conditions: result fits into an int
  long long f = 1;
  for (int i = n; i > 0; --i) { f *= i; }
  return f;
}

long long Combinatorics::permutations(const int n, const int r) {
  // calculates permutations using the formula nPr = n!/(n-r)!
  // pre-conditions: n, r are +ve integers, n >= r
  // post-conditions: returns +ve integer result
  return factorial(n)/factorial(n-r);
}

long long Combinatorics::combinations(const int n, const int r) {
  // calculates combinations using the formula nCr = n!/r!(n-r)!
  // pre-conditions: n, r are +ve integers, n >= r
  // post-conditions: returns +ve integer result
  return factorial(n)/(factorial(n-r)*factorial(r));
}
