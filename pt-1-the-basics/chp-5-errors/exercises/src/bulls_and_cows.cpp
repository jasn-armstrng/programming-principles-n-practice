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

int main(){
  // in progress
  std::vector<int> secret = {3, 1, 2, 2}; //random_integers(4);
  std::vector<int> guess;
  std::vector<std::string> hint(4);

  std::cout << "Guess: ";
  for(int g; std::cin>>g;){guess.push_back(g);}

  // for trouble shooting
  for(int i: secret){std::cout << i;}
  std::cout << '\n';
  for(int i: guess){std::cout << i;}
  std::cout << '\n';

  // working
  for(int i = 0; i<int(secret.size()); ++i){
    if(guess[i]==secret[i]){
      hint[i] = "B";
    }else{
      hint[i] = "_";
    }
  }

  // working
  for(int i = 0; i<int(secret.size()); ++i){
    for(int j = 0; j<int(secret.size()); ++j){

      std::cout << secret[i] << ", " << guess[j] << ", " << hint[i] << " => " << (secret[i]==guess[j] && (hint[i]!="B" && hint[j]!="B")) << '\n';
      if (secret[i]==guess[j] && (hint[i]!="B" && hint[j]!="B")){
        hint[j]="C";
      }
    }
  }
  for(std::string s: hint){std::cout << s;}
  std::cout <<'\n';
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
  for(int i = 0; i<n; ++i){random_ints.push_back(dist(ran_dev));}
  return random_ints;
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
