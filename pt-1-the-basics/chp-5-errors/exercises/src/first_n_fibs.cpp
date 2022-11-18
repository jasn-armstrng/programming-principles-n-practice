// This program prints the first n numbers of the fibonacci series
#include <iostream>
#include <vector>

// function declarations
inline void error(const std::string& s);
void fibonacci(const int n);

int main(){
  fibonacci(-1);
  return 0;
}

// function definitions
inline void error(const std::string& s){throw std::runtime_error(s);}

void fibonacci(const int n){
  // prints up to n numbers of the fibonacci series
  // pre-conditions: n must be a positive integer
  // post-conditions:
  if(n<0){error("Invalid value for n");} // +ve integer check for n

  std::vector<int> series = {0, 1}; // initialize with first 2 fibs - f0, f1

  for(int i = 2; i<n; ++i){
    int fn = series[i-1]+series[i-2];
    series.push_back(fn);
  }

  for(int i = 0; i<int(series.size()); ++i){
    std::cout << i+1 << ". " << series[i] << '\n';
  }
}
