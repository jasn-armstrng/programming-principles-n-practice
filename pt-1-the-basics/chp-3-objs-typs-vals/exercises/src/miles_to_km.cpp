// This program converts user entered miles to km

#include <iostream>
int main()
{
  double miles;
  std::cout << "+------------------------------------------+\n";
  std::cout << "|Welcome to the Miles->Kilometres converter|\n";
  std::cout << "+------------------------------------------+\n\n";
  std::cout << "Please enter a number of miles: ";
  std::cin >> miles;
  std::cout << "Answer: " << miles * 1.609 << "km\n";
  return 0;
}
