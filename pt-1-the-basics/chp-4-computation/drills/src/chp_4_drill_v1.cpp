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
6. - Read one variable from user
   - track the largest and smallest number input from user
   - After each iteration of while if the current entry is
     the smallest/largest of inputs notify user.
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
  double current;
  double smallest = std::numeric_limits<double>::infinity();
  double largest = 0;

  // Prompt user for input
  std::cout << "Please enter a real number. Enter | to terminate program.\n";
  std::cout << "\nInput:> ";

  // Read in input and compare
  while (std::cin >> current)
  {
    smallest = min(smallest, current);
    largest = max(largest, current);

    if (smallest==current)
    {
      std::cout << current << " is the smallest so far\n";
    }
    else if (largest==current)
    {
      std::cout << current << " is the largest so far\n";
    }
    else
    {
      std::cout << current << " meh, nothing special\n";
    }

    // Prompt for another round of input
    std::cout << "\nInput:> ";
  }

  return 0;
}
