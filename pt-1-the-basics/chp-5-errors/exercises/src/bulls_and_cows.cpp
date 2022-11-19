/*
This program implements the guessing game 'Bulls and Cows'.
A sequence of n integers in the range 0-9 are selected. Through guesses and
hints a user has to discover the integers in the correct order.

How the guess and hints work:
- If the number is 1234 and the guess is 1359 the hint should be '1 bull, 1 cow'
  because the got one digit (1) right and in the right position - the bull. The
  user also got another digit (3) but in the wrong position - the cow.
- Guessing/hints continue until the user gets all 4 numbers in right orider - 4
  bulls.
*/
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>

// ------------------------- function declarations -----------------------------
std::vector<int> random_integers(const int n);

int main(){
  std::vector<int> ri = random_integers(4);
  // for(int i: ri){std::cout << i << '\n';}
  return 0;
}

// ------------------------- function definitions ------------------------------
std::vector<int> random_integers(const int n){
  // generate n random (non-repeating) integers in range 0-9
  // pre-conditions: n>1, s is any number.
  // post-conditions: return a vector of random integers
  std::vector<int> random_ints;
  // std::random_device ran_dev;
  // std::uniform_int_distribution<int> dist(0,8);
  // for(int i = 0; i<n; ++i){
  //   random_ints.push_back(dist(ran_dev));
  // }
  return random_ints;
}
