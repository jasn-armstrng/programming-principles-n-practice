// This program computes the sum of the first n of a series of integers
#include <iostream>
#include <vector>
int main(){
  std::vector<int> integers;
  int n;

  std::cout << "Please enter the number of integers you want to sum: ";
  std::cin>>n;
  std::cout << "Please enter some integers (press '|' to stop): ";
  for(int integer; std::cin>>integer;){integers.push_back(integer);}
  std::cout << n << '\n';
  for(int i: integers){std::cout << i << '\n';}
  return 0;
}
