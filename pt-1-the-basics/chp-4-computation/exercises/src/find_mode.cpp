// This program finds the mode of a set of integers.


#include <algorithm>
#include <iostream>
#include <vector>

int mode(std::vector<int> v)
{
  int max_value = 0, // Mode
      max_count = 0; // Tracks the max frequency of a value in the vector

  std::sort(v.begin(), v.end());  // Sort vector ascending

  for(int i = 0; i < int(v.size()); ++i)
  { // This nested iteration works because the mode does not beat
    // the count it got on first iteration thru the inner for.
    int count = 0; // Tracks the consecutive count of a value
                   // reset to 0 for each iteration/value
    for(int j = i; j < int(v.size()); ++j)
    {
      if(v[j] == v[i])
      {
        ++count;
      }
    }
    if (count > max_count)
    {
      // update the mode and frequency
      max_value = v[i];
      max_count = count;
    }
  }
  if (max_count > 1)
    return max_value;

  return -1; // If no repeated numbers in a set of elements > 0, then no mode
}

int main()
{
  std::vector<int> integers;

  std::cout << "+-----------+\n";
  std::cout << "| Find Mode |\n";
  std::cout << "+-----------+\n\n";

  std::cout << "\nHow this program works:";
  std::cout << "\n--------------------------------------------";
  std::cout << "\n- Enter sequence of space separated integers";
  std::cout << "\n- End set of integers with a |";
  std::cout << "\n- If no mode program will output -1";
  std::cout << "\n- To exit the program enter |";
  std::cout << "\n--------------------------------------------";
  // User in
  std::cout << "\n\nIntegers: ";
  for(double val; std::cin >> val;) integers.push_back(val);
  // Program out
  std::cout << "\nMode: " << mode(integers) << '\n';
  return 0;
}
