/*
This program completes Chapter 4's Drill on pg. 126
1. - Read in two integers and print them to console.
   - Exit program when a '|' is entered
2. - Write out "the smaller value is: " << number
   - Write out "the larger value is: " << number
3. - Write out "the numbers are equal" when this is true
4. - Change program to use doubles instead of ints
5. - Write out "the numbers are almost equal" after 2. if
     their difference is less than 0.01(one hundredth)
*/

#include <iostream>

double min(double x, double y)
{
  if (x>y)
    return y;
  return x;
}

double max(double x, double y)
{
  if (x>y)
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
    if (num1==num2)
    {
      std::cout << "The numbers are equal\n";
    }
    else
    {
      double smaller = min(num1, num2);
      double larger = max(num1, num2);
      std::cout << "The smaller value is " << smaller << '\n';
      std::cout << "The larger value is " << larger << '\n';
      // When numbers are within 0.01 of each other
      // std::cout << larger-smaller << '\n';
      if ((larger-smaller) < 0.01)
        std::cout << "- the numbers are almost equal\n";
    }
    // Prompt for another round of inputs
    std::cout << "\nInput:> ";
  }

  return 0;
}
