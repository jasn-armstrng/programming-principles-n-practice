// This program calculates the mean and median of a sequence of temperatures

#include <iostream>
#include <vector>

double mean(std::vector<double> v)
{
  double sum = 0;
  for (double i:v) // Note the type of the iterator should match the type of the element.
  {
    sum+=i;
  }
  return sum/v.size();
}

int main()
{
  std::vector<double> temps;

  std::cout << "+----------------------+\n";
  std::cout << "| Calc Mean and Median |\n";
  std::cout << "+----------------------+\n\n";

  std::cout << "Please enter a sequence of temperature values. A | signals the end of the sequence.\n";
  std::cout << "Values: ";

  for(double temp; std::cin >> temp;) // Note the syntax for reading values in with for. The ;
  {
    temps.push_back(temp);
  }

  // Compute mean
  std::cout << "Mean: "<< mean(temps) << '\n';

  return 0;
}
