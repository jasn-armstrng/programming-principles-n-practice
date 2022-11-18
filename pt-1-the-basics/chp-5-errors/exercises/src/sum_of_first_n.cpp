/*
Description:
This program computes the sum of the first n of a series of real number values.

Program execution:
1. Ask for n - number of values in series to sum. Read into n.
2. Ask for series of values to sum. Read into vector.
3. Check if n <= vector.size().
4. If 3. is false, throw error
5. If 3. is true compute the sum of the first n values in vector.
6. Output n, sum and values that make up sum.
7. End program.
*/
#include <iostream>
#include <vector>

// function declarations
inline void error(const std::string& s);
void sum_first_n(const int n, const std::vector<double> i);
void ui();

int main()
try{
  std::cout << "+--------------------+\n";
  std::cout << "| Sum First N Values |\n";
  std::cout << "+--------------------+\n\n";
  ui();
  return 0;
}
catch(std::exception& e){
  std::cerr << "\nError: " << e.what() << '\n';
  return 1;
}
catch(...){
  std::cerr << "\nError: Unknown exception";
  return 2;
}

// function definitions
inline void error(const std::string& s){throw std::runtime_error(s);}

void sum_first_n(const int n, const std::vector<double> v){
  // sums the first n elements in a vector
  // pre-conditions: n<=vector.size()
  // post-condtions: print "The sum of the first n numbers ( numbers ) is sum"
  double sum = 0;
  if(!(n<=int(v.size()))){error("Not enough values provided");} // pre-condition check
  for(int i = 0; i<n; ++i){sum+=v[i];} // compute sum
  std::cout << "The sum of the first " << n << " values ( "; // build output string "The sum of the first n numbers ( numbers ) is sum"
  for(int i = 0; i<n; ++i){std::cout << v[i] << ' ';} // a better way to do this?
  std::cout << ") is " << sum << '\n';
}

void ui(){
  // present UI
  // Note: Program does not validate user input types
  std::vector<double> reals;
  int n;
  std::cout << "Please enter the number of values you want to sum:\n";
  std::cin>>n;
  std::cout << "Please enter some real numbers (press '|' to stop):\n";
  for(double real; std::cin>>real;){reals.push_back(real);}
  sum_first_n(n, reals);
}
