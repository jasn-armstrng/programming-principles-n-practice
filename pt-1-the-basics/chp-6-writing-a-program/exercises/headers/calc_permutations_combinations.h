#include <iostream>

int factorial(const int n);
int permutations();
int combinations();

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
