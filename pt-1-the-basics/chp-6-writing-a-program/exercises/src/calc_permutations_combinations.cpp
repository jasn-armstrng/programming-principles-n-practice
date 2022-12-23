/*
  A permutation is an ordered subset of a set. For example, say you wanted to
  pick a combination to a vault. There are 60 possible numbers, and you need
  three different numbers for the combination. There are P(60, 3) permutations
  for the combination, where P is defined by the formula,
              P(n, r) = n!/(n-r)!
  where n is the size of the set and r is the size of the ordered subset of n

  Combinations are similar to permutations except the order of the of the objects
  does not matter. The formula for combinations is,
              C(a, b) = P(a, b)/b!
  where n is the size of the set and r is the size of the UN-ordered subset of n

  Program requirements:
  - Ask user for two integers
  - Ask if to calculate Permutations or Combinations
  - Print the result
  - Check for input errors
  - All erroneous inputs will generate good error messages

  Simple sketch of program:
    - display program instructions
    - prompt calculation type - permutation/combination
    - prompt for input - 2 numbers
    - perform calculation
    - print result to screen

  Considerations:
    - What are reasonable inputs for a and b in P(a, b) and C(a, b). Update the
      program instructions and the function pre-conditions.
    - What data type is a appropriate for the results of P(a, b) and C(a, b),
      where a and b are reasonable inputs
    - Letting the function handle input validation with the main catching the
      errors.
*/

#include <iostream>

int factorial(const int n);
int permutations();
int combinations();

int main(){
  // prompt for calculation type and inputs
  std::string prompt_calculation_type = "Enter 1 for PERMUTATIONS or 2 for COMBINATIONS: ";
  int option;
  int result;

  std::cout << prompt_calculation_type;
  while(std::cin >> option){
    if (option == 1) {
      result = permutations();
      std::cout << "\nPermutations: " << result << '\n';
    } else
    if (option == 2) {
      result = combinations();
      std::cout << "\nCombinations: " << result << '\n';
    } else {
      std::cout << "Sorry, " << option << " is not an option\n";
    }

    std::cout << prompt_calculation_type;

    // switch (option) {
    //   case '1':
    //     result = permutations();
    //     std::cout << "\nPermutations: " << result << '\n';
    //     break;
    //   case '2':
    //     result = combinations();
    //     std::cout << "\nCombinations: " << result << '\n';
    //     break;
    //   default:
    //     std::cout << "Sorry, " << option << " is not an option\n"; // should validate option at user input
    //     std::cout << prompt_calculation_type;
    //     break;
    // }
  }



  // test factorial
  // std::cout << "\nfactorial tests:\n";
  // std::cout << factorial(2) << '\n';
  // std::cout << factorial(3) << '\n';
  // std::cout << factorial(4) << '\n';
  // std::cout << factorial(5) << '\n';

  // test permutation
  // std::cout << "\npermutation tests:\n";
  // std::cout << permutations(5, 3) << '\n'; // = 60
  // std::cout << permutations(10, 3) << '\n'; // = 720
  // std::cout << permutations(3, 3) << '\n'; // = 6

  // test combination
  // std::cout << "\ncombination tests:\n";
  // std::cout << combinations(6, 4) << '\n'; // = 15
  // return 0;
}

int factorial(const int n) {
  // calculate n!
  // pre-conditions: input is a +ve integer
  // post-conditions: result fits into an int
  int f = 1;
  for (int i = n; i > 0; --i) { f *= i; }
  return f;
}

int permutations() {
  // calculates permutations using the formula P(n, r) = n!/(n-r)!
  // pre-conditions: n, r are +ve integers, n >= r
  // post-conditions: returns +ve integer result
  int n, r;
  std::cout << "Enter the size of the SET (n): "; std::cin >> n;
  std::cout << "Enter the size of the SUBSET (r): "; std::cin >> r;
  return factorial(n)/factorial(n-r);
}

int combinations() {
  // calculates combinations using the formula C(a, b) = P(a, b)/b!
  // pre-conditions: a, b are +ve integers, a >= b
  // post-conditions: returns +ve integer result
  int n, r;
  std::cout << "Enter the size of the SET (n): "; std::cin >> n;
  std::cout << "Enter the size of the SUBSET (r): "; std::cin >> r;
  return factorial(n)/(factorial(r)*factorial(n-r));
}
