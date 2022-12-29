#include <iostream>
#include <vector>
#include "combinatorics.h"

Combinatorics combinatorics; // create a new instance of combinatorics
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
      int result = combinatorics.permutations(set_subset[0], set_subset[1]);
      std::cout << " Permutations (nPr): " << result << '\n';
    } else
    if (option == '2') {
      std::vector<int> set_subset = get_set_and_subset();
      int result = combinatorics.combinations(set_subset[0], set_subset[1]);
      std::cout << " Combinations (nCr): " << result << '\n';
    } else
    if (option == '3') {
      break;
    } else {
      std::cout << "Sorry, " << option << " is not an option\n";
    }
    std::cout << "\nOption: "; // Repeat options till user exits
  }
}

std::vector<int> get_set_and_subset() {
  // prompt and validate user input for the n and r in nPr/nCr
  // pre-conditions:
  // post-conditions: returns a type int vector with n in [0], and r in [1]
  std::vector<int> set_and_subset;
  int set, subset;
  std::cout << " Enter the size of the set (n): "; std::cin >> set; // to-validate
  set_and_subset.push_back(set);
  std::cout << " Enter the size of the subset (r): "; std::cin >> subset; // to-validate
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
