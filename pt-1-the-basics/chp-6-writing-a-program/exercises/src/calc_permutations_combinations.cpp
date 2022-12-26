/*
  A permutation is an ordered subset of a set. For example, say you wanted to
  pick a combination to a vault. There are 60 possible numbers, and you need
  three different numbers for the combination. There are P(60, 3) permutations
  for the combination, where P is defined by the formula,
              P(n, r) = n!/(n-r)!
  where n is the size of the set and r is the size of the ordered subset of n

  Combinations are similar to permutations except the order of the of the objects
  does not matter. The formula for combinations is,
              C(n, r) = n!/(r!(n-r)!)
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
    - What are reasonable inputs for a and b in P(n, r) and C(n, r). Update the
      program instructions and the function pre-conditions.
    - What data type is a appropriate for the results of P(n, r) and C(n, r),
      where a and b are reasonable inputs
    - Letting the function handle input validation with the main catching the
      errors.

  To do:
    - Research reasonable inputs for n and r in P(n, r) and C(n, r)
    - Error checking/throwing for function inputs
    - Error catching in main
    - Create UI function -- done
    - Move functions to header file
    - consider a token stream to handle user input into the functions. Bad inputs
      give an error message to the user, put back into the token stream and the
      program continues until valid inputs are entered.
*/
#include <iostream>

void ui();
int factorial(const int n);
int permutations();
int combinations();

int main(){
  ui();
  return 0;
}

void ui() {
  const char *intro =
    "This program calculates,\n"
    " 1. Permutations using the formula nPr = n!/(n-r)! where,\n"
    "    n is the size of the set, and r is the size of the ordered subset of n\n"
    " 2. Combinations using the formula nCr = n!/(r!(n-r)!) where,\n"
    "    n is the size of the set, and r is the size of the un-ordered subset of n\n";

  const char *options =
    "\nEnter,\n"
    " 1 for Permutations\n"
    " 2 for Combinations\n"
    " 3 to EXIT\n"
    "\nOption: ";

  std::cout << intro << options;

  char option;
  while(std::cin >> option){
    if (option == '1') {
      int result = permutations();
      std::cout << " nPr: " << result << '\n';
    } else
    if (option == '2') {
      int result = combinations();
      std::cout << " nCr: " << result << '\n';
    } else
    if (option == '3') {
      break;
    } else {
      std::cout << "Sorry, " << option << " is not an option\n";
    }
    std::cout << "\nOption: "; // Repeat options till user exits
  }
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
  std::cout << "\nCalculating permutations:\n";
  std::cout << " Enter the size of the set (n): "; std::cin >> n;
  std::cout << " Enter the size of the subset (r): "; std::cin >> r;
  return factorial(n)/factorial(n-r);
}

int combinations() {
  // calculates combinations using the formula C(a, b) = P(a, b)/b!
  // pre-conditions: a, b are +ve integers, a >= b
  // post-conditions: returns +ve integer result
  int n, r;
  std::cout << "\nCalculating combinations:\n";
  std::cout << " Enter the size of the set (n): "; std::cin >> n;
  std::cout << " Enter the size of the subset (r): "; std::cin >> r;
  return factorial(n)/(factorial(r)*factorial(n-r));
}


/*
Tests:
  test factorial
  std::cout << "\nfactorial tests:\n";
  std::cout << factorial(2) << '\n';
  std::cout << factorial(3) << '\n';
  std::cout << factorial(4) << '\n';
  std::cout << factorial(5) << '\n';

  test permutation
  std::cout << "\npermutation tests:\n";
  std::cout << permutations(5, 3) << '\n'; // = 60
  std::cout << permutations(10, 3) << '\n'; // = 720
  std::cout << permutations(3, 3) << '\n'; // = 6

  test combination
  std::cout << "\ncombination tests:\n";
  std::cout << combinations(6, 4) << '\n'; // = 15
  return 0;
*/

/*
Execution with sample use cases:

This program calculates,
 1. Permutations using the formula nPr = n!/(n-r)! where,
    n is the size of the set, and r is the size of the ordered subset of n
 2. Combinations using the formula nCr = n!/(r!(n-r)!) where,
    n is the size of the set, and r is the size of the un-ordered subset of n

Enter,
 1 for Permutations
 2 for Combinations
 3 to EXIT

Option: 1

Calculating permutations:
 Enter the size of the set (n): 10
 Enter the size of the subset (r): 3
 nPr: 720

Option: 2

Calculating combinations:
 Enter the size of the set (n): 6
 Enter the size of the subset (r): 4
 nCr: 15

Option: 3
*/
