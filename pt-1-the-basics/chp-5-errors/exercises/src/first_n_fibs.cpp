// This program prints the first n numbers of the fibonacci series
#include <iostream>
#include <vector>

// --------------------- function declarations ---------------------------------
inline void error(const std::string& s);
void fibonacci(const int n);
void ui();

int main()
try{
  std::cout << "+---------------------------+\n";
  std::cout << "| First N Fibonacci Numbers |\n";
  std::cout << "+---------------------------+\n\n";
  ui();
  return 0;
}
catch(std::exception& e){
  std::cerr << "\nError: " << e.what() << '\n';
  return 1;
}
catch(...){
  std::cerr << "\nError: Unknown exception" << '\n';
  return 2;
}

// --------------------- function definitions ----------------------------------
inline void error(const std::string& s){
  throw std::runtime_error(s);
}

void fibonacci(const int n){
  // prints up to n numbers of the fibonacci series
  // pre-conditions: n must be a positive integer
  // post-conditions:
  if(n<0){error("Bad input for n");} // +ve integer check for n

  std::vector<double> series = {0, 1}; // initialize with first 2 fibs - f0, f1
  for(int i = 2; i<n; ++i){
    double fn = series[i-1]+series[i-2];
    series.push_back(fn);
  }

  std::cout << "\nFn\tNumber\n"; // header for output
  for(int i = 0; i<int(series.size()); ++i){
    std::cout << i << "\t" << series[i] << '\n';
  }
}

void ui(){
  // present UI and program output
  double n;
  std::cout << "Please enter a positive integer value for N: ";
  std::cin>>n;
  fibonacci(n);
}
