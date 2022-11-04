/*
This program completes Chapter 4's Drill on pg. 126
1. - Read in two integers and print them to console.
   - Exit program when a '|' is entered
2. - Write out the "the smaller value is: " << number
   - Write out the "the larger value is: " << number
*/

#include <iostream>

int min(int x, int y)
{
  if (x > y)
    return y;
  return x;
}

int max(int x, int y)
{
  if (x > y)
    return x;
  return y;
}

int main()
{
  int num1, num2;

  // Prompt user for input
  std::cout << "Please enter two integers. Enter a '|' to terminate the program.\n";
  std::cout << "\nInput:> ";

  while (std::cin >> num1 >> num2)
  {
    //std::cout << "You entered: " << num1 << ' ' << num2 << "\n\nIntegers:";
    std::cout << "The smaller value is " << min(num1, num2) << '\n';
    std::cout << "The larger value is " << max(num1, num2) << '\n';
    std::cout << "\nInput:> ";
  }
  return 0;
}
