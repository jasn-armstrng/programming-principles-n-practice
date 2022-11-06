// This program stores a sequence of distances to locations along a route.
// Outputs the smallest, largest and average distance between the locations as
// well as the total distance travelled on the route.

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
  for (double i:v) sum+=i; // Note: type of the iterator matches element type.
  return sum/v.size();
}

int main()
{
  double sum, average;
  double smallest = std::numeric_limits<double>::infinity();
  double largest = 0;
  std::vector<double> dist_to_loc; // distance to location
  std::vector<double> dist_between_loc;

  std::cout << "Please enter a the sequence of distances along the route.\n";
  std::cout << "Use | to signal the end of the sequence.\n";
  std::cout << "\nValues: ";

  for(double val; std::cin >> val;) dist_to_loc.push_back(val);

  for (int i = 0; i<dist_to_loc.size(); ++i)
  {
    if(i>0)
    {
      double dist_between = dist_to_loc[i]-dist_to_loc[i-1];
      dist_between_loc.push_back(dist_between);
      smallest = min(smallest, dist_between);
      largest = max(largest, dist_between);
    } else
    {
      dist_between_loc.push_back(dist_to_loc[i]);
      smallest = min(smallest, dist_to_loc[i]);
      largest = max(largest, dist_to_loc[i]);
    }
  }
  std::cout << "\nDistances: ";
  for (double x: dist_to_loc) std::cout << x << ' ';
  std::cout << "\nDifferences: ";
  for (double x: dist_between_loc) std::cout << x << ' ';
  std::cout << "\nSmallest Diff: " << smallest;
  std::cout << "\nlargest Diff: " << largest;
  std::cout << "\nAverage Diff: " << mean(dist_between_loc) << '\n';

  return 0;
}
