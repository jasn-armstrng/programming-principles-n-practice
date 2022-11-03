// This program squares a number by repeated addition.

#include <iostream>

double square(double x)
{
  for (int i = 0; i < x; ++i)
  {
    x+=x;
  }
  return x;
}

int main()
{
  double number;
  std::cout << "+----------------------+\n";
  std::cout << "| Squaring by addition |\n";
  std::cout << "+----------------------+\n\n";

  // Prompt for user values. Read in user input.
  std::cout << "Please enter a number: ";
  std::cin >> number;
}
