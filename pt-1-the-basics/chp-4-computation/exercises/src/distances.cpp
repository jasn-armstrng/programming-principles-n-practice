// This program stores a sequence of distances to locations along a route.
// Outputs the smallest, largest and average distance between the locations as
// well as the total distance travelled on the route.

#include <iostream>
#include <vector>
int main()
{
  double sum, average;
  double smallest = std::numeric_limits<double>::infinity();
  double largest = 0;
  std::vector<double> distances;

  std::cout << "Please enter a the sequence of distances along the route.\n";
  std::cout << "Use | to signal the end of the sequence.\n";
  std::cout << "Values:_ ";

  for(double val; std::cin >> val;) distances.push_back(val);
}
