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
7. - Allow the user to enter a number and unit of measure
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
  double number;
  std::string unit;
  int values; // track values entered by user
  double cm; // track total of values in cm
  double smallest = std::numeric_limits<double>::infinity();
  double largest = 0;

  std::cout << "Please enter a number followed by a unit (cm, in, m, ft)\n";
  std::cout << "\nInput:> ";

  while (std::cin >> number >> unit) // Read in input and compare
  {
    if (unit=="cm")
    {
      cm+=number;
      smallest = min(smallest, number);
      largest = max(largest, number);
    }
    else if (unit=="in")
    { // 1in == 2.54cm
      cm+=number*2.54;
      smallest = min(smallest, number*2.54);
      largest = max(largest, number*2.54);
    }
    else if (unit=="m")
    { // 1m == 100cm
      cm+=number*100;
      smallest = min(smallest, number*100);
      largest = max(largest, number*100);
    }
    else if (unit=="ft")
    { // 1ft == 30.48cm
      cm+=number*30.48;
      smallest = min(smallest, number*30.48);
      largest = max(largest, number*30.48);
    }
    else
    {
      --values; // decrement for bad input
      std::cout << "I cannot accept that input.\n";
    }

    ++values; // keeps valid input count though consecutive invalids entered
    std::cout << "\nInput:> "; // Prompt for another round of input
  }

  std::cout << "\nSummary:\n";
  std::cout << " - Smallest value: " << smallest << "cm\n";
  std::cout << " - Largest value: " << largest << "cm\n";
  std::cout << " - Number of values: " << values-1 << '\n'; // -1 because |
  std::cout << " - Total in metres: " << cm/100 << "m\n";
  return 0;
}
