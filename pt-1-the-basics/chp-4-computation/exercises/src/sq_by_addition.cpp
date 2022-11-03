// This program squares a +ve integer by repeated addition.

#include <iostream>

int square(int x)
{
  int sq = 0;
  for (int i = 0; i < x; ++i)
  {
    sq+=x;
  }
  return sq;
}

int main()
{
  int number;
  std::cout << "+----------------------+\n";
  std::cout << "| Squaring by addition |\n";
  std::cout << "+----------------------+\n\n";

  // Prompt for user values. Read in user input.
  std::cout << "Please enter a +ve integer: ";
  std::cin >> number;

  // Output square
  std::cout << "\nSquare: " << square(number) << '\n';
  return 0;
}
