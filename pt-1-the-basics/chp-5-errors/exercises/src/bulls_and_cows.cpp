/*
This program implements the guessing game 'Bulls and Cows'.
A sequence of n integers in the range 0-9 are selected. The integers do not
repeat. Through guesses and hints a user has to discover the integers in the
correct order.

How the guess and hints work:
- If the number is 1234 and the guess is 1359 the hint should be '1 bull, 1 cow'
  because the got one digit (1) right and in the right position - the bull. The
  user also got another digit (3) but in the wrong position - the cow.
- Guessing/hints continue until the user gets all 4 numbers in right orider - 4
  bulls.
*/
#include <iostream>
#include <random>
#include <vector>

// ------------------------- function declarations -----------------------------
std::vector<int> random_integers(const int n);
inline int randint(int min, int max);
inline int randint(int max);

int main(){


  return 0;
}

// ------------------------- function definitions ------------------------------
std::vector<int> random_integers(const int n){
  // generate n random (non-repeating) integers in range 0-9
  // pre-conditions: n>1
  // post-conditions: return a vector of random integers
  std::vector<int> random_ints;
  return random_ints;
}

// random number generators taken from std_lib_facilities.h
inline std::default_random_engine& get_rand(){
	static std::default_random_engine ran;	// note: not thread_local
	return ran;
};

inline int randint(int min, int max){return std::uniform_int_distribution<>{min, max}(get_rand());}

inline int randint(int max){return randint(0, max);}
