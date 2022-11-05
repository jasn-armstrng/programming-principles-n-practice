// This program calculates the mean and median of a sequence of temperatures

#include <algorithm>
#include <iostream>
#include <vector>

double mean(std::vector<double> v)
{
  double sum = 0;
  for (double i:v) sum+=i; // Note the type of the iterator should match the type of the element.
  return sum/v.size();
}

double median(std::vector<double> v)
{
  std::sort(v.begin(), v.end());
  if (v.size()%2 != 0)
  {
    return v[(v.size()/2)];
  }
}

int main()
{
  std::vector<double> temps;

  std::cout << "+----------------------+\n";
  std::cout << "| Calc Mean and Median |\n";
  std::cout << "+----------------------+\n\n";

  std::cout << "Please enter a sequence of temperature values. A | signals the end of the sequence.\n";
  std::cout << "Values: ";

  // Note the syntax below for reading values in with for. The ; after each statement
  for(double temp; std::cin >> temp;) temps.push_back(temp);

  // Compute mean
  std::cout << "Mean: "<< mean << '\n';

  // Compute median
  std::sort(temps.begin(), temps.end());
  for(double i:temps)
  {
    std::cout << i << '\n';
  }

  std::cout << "Median: "<< median(temps) << '\n';

  return 0;
}
