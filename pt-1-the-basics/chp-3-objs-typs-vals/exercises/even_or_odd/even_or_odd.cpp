// This program checks if user integer input is even or odd.

#include <iostream>
int main()
{
  int num;
  std::cout << "+-------------+\n";
  std::cout << "| Even or Odd |\n";
  std::cout << "+-------------+\n\n";
  std::cout << "Please enter an integer: ";
  std::cin >> num;

  if (num % 2 == 0)
    std::cout << "\nThe value " << num << " is an even number.\n";
  else
    std::cout << "\nThe value " << num << " is an odd number.\n";

  return 0;
}
