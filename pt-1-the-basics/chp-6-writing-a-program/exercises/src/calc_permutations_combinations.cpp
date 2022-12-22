/*
  A permutation is an ordered subset of a set. For example, say you wanted to
  pick a combination to a vault. There are 60 possible numbers, and you need
  three different numbers for the combination. There are P(60, 3) permutations
  for the combination, where P is defined by the formula,
              P(a, b) = a!/(a-b)!

  Combinations are similar to permutations except the order of the of the objects
  does not matter. The formula for combinations is,
              C(a, b) = P(a, b)/b!

  Program requirements:
  - Ask user for two integers
  - Ask if to calculate Permutations or Combinations
  - Print the result
  - Check for input errors
  - All erroneous inputs will generate good error messages

  Simple sketch of program:
    display program instructions
    prompt calculation type - permutation/combination
    prompt for input - 2 numbers
    perform calculation
    print result to screen
*/

#include <iostream>

int factorial(const int a);
int permutations(const int a, const int b);
int combinations(const int a, const int b);

int main(){
  // test factorial
  std::cout << "\nfactorial tests:\n";
  std::cout << factorial(2) << '\n';
  std::cout << factorial(3) << '\n';
  std::cout << factorial(4) << '\n';
  std::cout << factorial(5) << '\n';

  // test permutation
  std::cout << "\npermutation tests:\n";
  std::cout << permutations(5, 3) << '\n';
  std::cout << permutations(10, 3) << '\n';
  std::cout << permutations(3, 3) << '\n';

  // test combination
  std::cout << "\ncombination tests:\n";
  std::cout << combinations(6, 4) << '\n';
  return 0;
}

int factorial(const int a) {
  // calculate a!
  // pre-conditions: input is a +ve integer
  // post-conditions: result fits into an double
  int f = 1;
  for (int i = a; i > 0; --i) { f *= i; }
  return f;
}

int permutations(const int a, const int b) {
  // calculates permutations using the formula P(a, b) = a!/(a-b)!
  // pre-conditions: a, b are +ve integers, a >= b
  // post-conditions: returns +ve integer result
  return factorial(a)/factorial(a-b);
}

int combinations(const int a, const int b) {
  // calculates combinations using the formula C(a, b) = P(a, b)/b!
  // pre-conditions: a, b are +ve integers, a >= b
  // post-conditions: returns +ve integer result
  return permutations(a, b)/factorial(b);
}
