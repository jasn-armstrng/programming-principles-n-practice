// This program calculates the mean and median of a sequence of values e.g
// temperatures.

#include <algorithm>
#include <iostream>
#include <vector>

double mean(std::vector<double> v)
{
  double sum = 0;
  for (double i:v) sum+=i; // Note: type of the iterator matches element type.
  return sum/v.size();
}

double median(std::vector<double> v)
{
  std::sort(v.begin(), v.end());
  int mid = v.size()/2;

  if (v.size()%2 != 0)
    return v[mid];
  else
    return (v[mid]+v[mid-1])/2;
}

int main()
{
  std::vector<double> vec;

  std::cout << "+----------------------+\n";
  std::cout << "| Calc Mean and Median |\n";
  std::cout << "+----------------------+\n\n";

  std::cout << "Please enter a sequence of values. Use | to signal the end of the sequence.\n";
  std::cout << "Values: ";

  // Note the syntax below for reading values in with for. The ; after each statement
  for(double val; std::cin >> val;) vec.push_back(val);

  std::cout << "\nResults:\n";
  std::cout << "- No. of Values: " << vec.size() << '\n';
  std::cout << "- Mean: "<< mean(vec) << '\n';
  std::cout << "- Median: "<< median(vec) << '\n';

  return 0;
}
