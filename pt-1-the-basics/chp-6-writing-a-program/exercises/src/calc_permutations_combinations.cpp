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
    - print result to screen'

  Expected output examples:
    permutations(5, 3) -> 60
    permutations(10, 3) -> 720
    permutations(3, 3) -> 6
    combinations(6, 4) -> 15
    combinations(10, 3) -> 120

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
    - Consider a token stream to handle user input into the functions. Bad inputs
      give an error message to the user, put back into the token stream and the
      program continues until valid inputs are entered.
*/

#include "../headers/calc_permutations_combinations.h"

int main(){
  ui();
  return 0;
}

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
