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
#include <iostream>
#include <random>
#include <vector>

// ------------------------- function declarations -----------------------------
std::vector<int> random_integers(const int n);
std::string hint(const std::vector<int> s, const std::vector<int> g);

int main(){
  // in progress
  std::vector<int> secret = random_integers(4);
  std::vector<int> guess;
  bool four_bulls = false;

  std::cout << "Secret: ";
  for(int i: secret){ std::cout << i; }
  std::cout <<'\n';

  std::cout << "Enter your 4 digit guess (press | to end): ";
  for(int g; std::cin>>g;){guess.push_back(g);}

  // for trouble shooting
  std::cout << "Guess:";
  for(int i: guess){std::cout << i;}
  std::cout << '\n';
  std::cout << "Hint: " << hint(secret, guess) << '\n';

  return 0;
}

// ------------------------- function definitions ------------------------------
std::vector<int> random_integers(const int n){
  // generate n random (non-repeating) integers in range 0-9
  // pre-conditions: n>1, s is any number.
  // post-conditions: return a vector of random integers. Duplicates allowed.
  std::vector<int> random_ints;
  std::random_device ran_dev; // see more in ref below
  std::uniform_int_distribution<int> dist(0,9); // see more in ref below
  for(int i = 0; i<n; ++i){ random_ints.push_back(dist(ran_dev)); }
  return random_ints;
}

std::string hint(const std::vector<int> s, const std::vector<int> g){
  // compare value/position in secret with guess
  // pre-conditions: s.size() == g.size()
  // post-conditions: print hint with B(ulls), C(ows) or (_)
  std::vector<std::string> v = {"_", "_", "_", "_"};
  std::string hint;
  // hint bulls
  for (int i = 0; i<int(s.size()); ++i){
    if (g[i]==s[i]){ v[i]="B"; }
  }
  // hint cows
  for(int i = 0; i<int(s.size()); ++i){
    for(int j = 0; j<int(s.size()); ++j){
      if (s[i]==g[j] && (v[i]!="B" && v[j]!="B")){ v[j]="C"; }
    }
  }

  for(std::string s: v){ hint+=s; }
  return hint;
}

/*
Reference
---------
std::random_device:
is a uniformly-distributed integer random number generator
that produces non-deterministic random numbers.

std::uniform_int_distribution:
Produces random integer values i, uniformly distributed on the closed interval
[a, b] that is, distributed according to the discrete probability function,
P(i|a, b)=1/(b-a+1)
*/


/*
  Truth table for debug:
  bool cow = s[i]==g[j] && (hint[i]!="B" && hint[j]!="B");
  std::cout << g[i] << ", " << g[j] << ", " << hint[i] << " => " << cow << '\n';
*/
