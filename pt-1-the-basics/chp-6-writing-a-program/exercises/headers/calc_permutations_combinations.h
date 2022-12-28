#include <iostream>
#include <vector>

int factorial(const int n);
int permutations(const int n, const int r);
int combinations(const int n, const int r);
std::vector<int> get_set_and_subset();

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
      std::vector<int> set_subset = get_set_and_subset();
      int result = permutations(set_subset[0], set_subset[1]);
      std::cout << " Permutation (nPr): " << result << '\n';
    } else
    if (option == '2') {
      std::vector<int> set_subset = get_set_and_subset();
      int result = combinations(set_subset[0], set_subset[1]);
      std::cout << " Combination (nCr): " << result << '\n';
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

int permutations(const int n, const int r) {
  // calculates permutations using the formula nPr = n!/(n-r)!
  // pre-conditions: n, r are +ve integers, n >= r
  // post-conditions: returns +ve integer result
  return factorial(n)/factorial(n-r);
}

int combinations(const int n, const int r) {
  // calculates combinations using the formula nCr = n!/r!(n-r)!
  // pre-conditions: n, r are +ve integers, n >= r
  // post-conditions: returns +ve integer result
  return factorial(n)/(factorial(r)*factorial(n-r));
}

std::vector<int> get_set_and_subset() {
  // prompt and validate user input for the n and r in nPr/nCr
  // pre-conditions:
  // post-conditions: returns a type int vector with n in [0], and r in [1]
  std::vector<int> set_and_subset;
  int set, subset;
  std::cout << " Enter the size of the set (n): "; std::cin >> set;
  set_and_subset.push_back(set);
  std::cout << " Enter the size of the subset (r): "; std::cin >> subset;
  set_and_subset.push_back(subset);
  return set_and_subset;
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
