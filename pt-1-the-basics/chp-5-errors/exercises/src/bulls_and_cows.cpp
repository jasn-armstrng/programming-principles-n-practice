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
void ui();
std::vector<int> random_integers(const int n);
std::string get_hint(const std::vector<int> s, const std::vector<int> g);

int main(){
  std::cout << "+----------------+\n";
  std::cout << "| Bulls and Cows |\n";
  std::cout << "+----------------+\n\n";

  const char *instructions =
    "A secret 4 digit number has been generated. You have to guess what the\n"
    "number is. With each guess, a hint is provided with the following info:\n\n"
    "* The B(ulls), are digits in the guess that are in the correct position.\n"
    "* The C(ows), are digits in the guess that are in the secret number but\n"
    "  are located in the wrong position. Specifically, the non-bull digits in\n"
    "  the guess that could be rearranged such that they become bulls.\n"
    "* The '_', indicates digits not in secret.\n"
    "\nPlease separate your each digit of your guess with a space e.g. 1 2 3 4\n";

  std::cout << instructions << "\n";
  ui();
  return 0;
}

// ------------------------- function definitions ------------------------------
void ui(){
  // present user input prompt and program output until player wins
  std::vector<int> guess, secret = random_integers(4);
  int a, b, c, d;
  std::string hint;

  std::cout << "Guess: ";
  while(std::cin>>a>>b>>c>>d){
    guess.push_back(a);
    guess.push_back(b);
    guess.push_back(c);
    guess.push_back(d);

    hint = get_hint(secret, guess);
    std::cout << "Hint:  " << hint << '\n'; // show hint

    if(hint=="B B B B"){
      std::cout << "\nCongrats! You got four bulls.\n"; // Winning message
      break;
    }else{
      hint = ""; // reset the hint
      guess.clear(); // empty the vector
      std::cout << "\nGuess: "; // prompt for new guess
    }
  }
}

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

std::string get_hint(const std::vector<int> s, const std::vector<int> g){
  // compare value/position in secret with guess
  // pre-conditions: s.size() == g.size()
  // post-conditions: print hint with B(ulls), C(ows) or (_)
  std::vector<std::string> v = {"_", "_", "_", "_"};
  std::string hint = "";
  // hint bulls
  for (unsigned i = 0; i<s.size(); ++i){
    if (g[i]==s[i]){ v[i]="B"; }
  }
  // hint cows
  for(unsigned i = 0; i<s.size(); ++i){
    for(unsigned j = 0; j<s.size(); ++j){
      if (s[i]==g[j] && (v[i]!="B" && v[j]!="B")){ v[j]="C"; }
    }
  }
  // format output
  for(unsigned i = 0; i<v.size(); ++i){
    if(i==v.size()-1){
      hint+=v[i];
    }else{
      hint+=(v[i]+" ");
    }
  }

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
  Truth table for debugging get_hint function:
  bool cow = s[i]==g[j] && (hint[i]!="B" && hint[j]!="B");
  std::cout << g[i] << ", " << g[j] << ", " << hint[i] << " => " << cow << '\n';
*/
