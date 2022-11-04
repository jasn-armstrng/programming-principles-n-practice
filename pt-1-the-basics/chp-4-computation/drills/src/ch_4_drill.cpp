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
8. - Reject illegal inputs
9. - Print summary:
   - Smallest input, largest input, number of inputs,
     total of inputs in metres.
10.- Store all values converted in metres in a vector
   - At the end output all values in vector
*/

#include <iostream>
#include <vector>

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
  std::vector<double> values; // track values entered by user converted to m
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
      values.push_back(number/100);
    }
    else if (unit=="in")
    { // 1in == 2.54cm
      cm+=number*2.54;
      smallest = min(smallest, number*2.54);
      largest = max(largest, number*2.54);
      values.push_back(number*2.54/100);
    }
    else if (unit=="m")
    { // 1m == 100cm
      cm+=number*100;
      smallest = min(smallest, number*100);
      largest = max(largest, number*100);
      values.push_back(number);
    }
    else if (unit=="ft")
    { // 1ft == 30.48cm
      cm+=number*30.48;
      smallest = min(smallest, number*30.48);
      largest = max(largest, number*30.48);
      values.push_back(number*30.48/100);
    }
    else
    {
      std::cout << "I cannot accept that input.\n";
    }

    std::cout << "\nInput:> "; // Prompt for another round of input
  }

  std::cout << "\nSummary:\n";
  std::cout << " - Smallest value: " << smallest << "cm\n";
  std::cout << " - Largest value: " << largest << "cm\n";
  std::cout << " - Number of values: " << values.size() << '\n';
  std::cout << " - Values in metres: \n";
  for (int i = 0; i < values.size(); ++i)
  {
    std::cout << "   " << i+1 << ". " << values[i] << "m\n";
  }
  std::cout << " - Total in metres: " << cm/100 << "m\n";
  return 0;
}
