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

int main()
try{
  std::vector<int> integers;
  int n, sum = 0;

  std::cout << "Please enter the number of integers you want to sum:\n";
  std::cin>>n;
  std::cout << "Please enter some integers (press '|' to stop):\n";
  for(int integer; std::cin>>integer;){integers.push_back(integer);}
  // n, vector.size() comparison
  if(!(n<=int(integers.size()))){error("Not enough integers provided");}
  for(int i = 0; i<n; ++i){sum+=integers[i];}
  std::cout << "The sum of the first " << n << " numbers is " << sum << '\n';

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

// Test code:
// std::cout << n << '\n';
// for(int i: integers){std::cout << i << '\n';}
