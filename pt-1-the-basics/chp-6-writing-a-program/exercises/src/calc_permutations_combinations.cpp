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

int main(){
  // test factorial function
  std::cout << factorial(2) << '\n';
  std::cout << factorial(3) << '\n';
  std::cout << factorial(4) << '\n';
  std::cout << factorial(5) << '\n';
  return 0;
}

int factorial(const int a) {
  // calculate a!
  // pre-conditions: input is a +ve integer
  // post-conditions: result fits into an int
  int f = 1;
  for (int i = a; i > 0; --i) {
    f *= i;
  }
  return f;
}
