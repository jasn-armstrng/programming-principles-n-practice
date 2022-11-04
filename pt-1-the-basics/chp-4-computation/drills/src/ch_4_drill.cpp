/*
This program completes Chapter 4's Drill on pg. 126
1. - Read in two integers and print them to console.
   - Exit program when a '|' is entered
2. - Write out "the smaller value is: " << number
   - Write out "the larger value is: " << number
3. - Write out "the numbers are equal" when this is true
4. - Change program to use doubles instead of ints
*/

#include <iostream>

double min(double x, double y)
{
  if (x > y)
    return y;
  return x;
}

double max(double x, double y)
{
  if (x > y)
    return x;
  return y;
}

int main()
{
  double num1, num2;

  // Prompt user for input
  std::cout << "Please enter two integers. Enter | to terminate program.\n";
  std::cout << "\nInput:> ";

  // Read in input and compare
  while (std::cin >> num1 >> num2)
  {
    // std::cout << "You entered: " << num1 << ' ' << num2 << "\n\nIntegers:";
    if (num1 == num2)
    {
      std::cout << "The numbers are equal\n";
    }
    else
    {
      std::cout << "The smaller value is " << min(num1, num2) << '\n';
      std::cout << "The larger value is " << max(num1, num2) << '\n';
    }
    // Prompt for another round of inputs
    std::cout << "\nInput:> ";
  }

  return 0;
}
