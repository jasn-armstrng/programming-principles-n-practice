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
  int mid = v.size()/2;

  if (v.size()%2 != 0)
    return v[mid];
  else
    return (v[mid]+v[mid-1])/2;
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
  std::cout << "Mean: "<< mean(temps) << '\n';
  std::cout << "Median: "<< median(temps) << '\n';

  return 0;
}
