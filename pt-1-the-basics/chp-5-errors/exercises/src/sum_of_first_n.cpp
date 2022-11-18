// This program computes the sum of the first n of a series of integers
/*
Program execution:
1. Ask for n - the number of integers in series to sum. Read into n.
2. Ask for series of integers to sum. Read into vector.
3. Before computing sum check if n <= vector.size().
4. If 3 is false,
    - Show error
    - Repeat the prompt for n and integers
5. If 3 is true compute the sum of the first n integers in vector.
6. Output n, sum and integers that make up sum.
7. End program.
*/
#include <iostream>
#include <vector>

// function declarations
inline void error(const std::string& s);
void sum_first_n(const int n, const std::vector<int> i);
void ui();

int main()
try{
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

void sum_first_n(const int n, const std::vector<int> v){
  // sums the first n elements in a vector
  // pre-conditions: n<=vector.size()
  // post-condtions: print "The sum of the first n numbers ( numbers ) is sum"
  int sum = 0;
  // pre-condition check
  if(!(n<=int(v.size()))){error("Not enough integers provided");}
  // compute sum
  for(int i = 0; i<n; ++i){sum+=v[i];}
  // output
  std::cout << "The sum of the first " << n << " numbers ( ";
  for(int i = 0; i<n; ++i){std::cout << v[i] << ' ';} // a better way to do this?
  std::cout << ") is " << sum << '\n';
}

void ui(){
  // present UI
  std::vector<int> integers;
  int n;

  std::cout << "Please enter the number of integers you want to sum:\n";
  std::cin>>n;
  std::cout << "Please enter some integers (press '|' to stop):\n";
  for(int integer; std::cin>>integer;){integers.push_back(integer);}
  sum_first_n(n, integers);
}
