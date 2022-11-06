// This program takes a sequence of distances between locations along a route.
// - Outputs the smallest, largest and average distance traveled between the
//   locations as well as the total distance travelled.

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

double mean(std::vector<double> v)
{
  double sum = 0;
  for (double i:v) sum+=i;
  return sum/v.size();
}

int main()
{
  double sum, average;
  double smallest = std::numeric_limits<double>::infinity();
  double largest = 0;
  std::vector<double> dist_to_loc; // distance to location

  std::cout << "+----------------+\n";
  std::cout << "| Travel Summary |\n";
  std::cout << "+----------------+\n\n";
  std::cout << "Please enter the sequence of distances traveled between cities below.\n";
  std::cout << "* Use | to signal end of the sequence.\n";
  std::cout << "\nDistances: ";

  for(double val; std::cin >> val;) dist_to_loc.push_back(val);

  for (int i = 0; i<dist_to_loc.size(); ++i)
  {
    sum+=dist_to_loc[i]; // compute total distance traveled
    smallest = min(smallest, dist_to_loc[i]);
    largest = max(largest, dist_to_loc[i]);
  }
  average = mean(dist_to_loc);

  std::cout << "\nTravel summary: ";
  std::cout << "\n===============";
  std::cout << "\nMin distance: " << smallest << "km";
  std::cout << "\nMax distance: " << largest << "km";
  std::cout << "\nAvg distance: " << average << "km";
  std::cout << "\nSum distance: " << sum << "km\n";

  return 0;
}
