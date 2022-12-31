#include <iostream>
#include <vector>
#include "combinatorics.h"

Combinatorics combinatorics; // create a new instance of Combinatorics
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

  int option;
  /*
    To do:
    Chapter 10 covers input error handling deeper. When that info is covered,
    return to this and handle non-integer inputs
  */
  while(std::cin >> option) {
    if (option == 1) {
      std::vector<int> set_subset = get_set_and_subset();
      int result = combinatorics.permutations(set_subset[0], set_subset[1]);
      std::cout << " Permutations (nPr): " << result << '\n';
    } else
    if (option == 2) {
      std::vector<int> set_subset = get_set_and_subset();
      int result = combinatorics.combinations(set_subset[0], set_subset[1]);
      std::cout << " Combinations (nCr): " << result << '\n';
    } else
    if (option == 3) {
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
  const std::string prompt_n = " Enter the size of the set (n): ",
                    prompt_r = " Enter the size of the subset (r): ";

  int set, subset;

  std::cout << prompt_n;
  std::cin >> set; // to-validate
  set_and_subset.push_back(set);

  std::cout << prompt_r;
  std::cin >> subset; // to-validate
  set_and_subset.push_back(subset);

  return set_and_subset;
}
