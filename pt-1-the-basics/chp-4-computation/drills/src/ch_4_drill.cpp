/*
This program completes Chapter 4's Drill on pg. 126
1. - Read in two integers and print them to console.
   - Exit program when a '|' is entered
*/

#include <iostream>
int main()
{
  int num1, num2;

  // Prompt user for input
  std::cout << "Please enter two integers. Enter a '|' to terminate the program.\n\nIntegers: ";
  while (std::cin >> num1 >> num2)
  {
    std::cout << "You entered: " << num1 << ' ' << num2 << "\n\nIntegers:";
  }
  return 0;
}
