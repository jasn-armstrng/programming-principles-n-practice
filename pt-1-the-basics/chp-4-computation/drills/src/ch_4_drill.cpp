/*
1. - Read in two integers and print them to console.
   - Exit program when a '|' is entered
*/

#include <iostream>
int main()
{
  int num1, num2;

  // Prompt user for input
  std::cout << "Please enter two integers: ";
  while (std::cin >> num1 >> num2)
  {
    std::cout << num1 << ' ' << num2 << '\n';
  }
  return 0;
}
