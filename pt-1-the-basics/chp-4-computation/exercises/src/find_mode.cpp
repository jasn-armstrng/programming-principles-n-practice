// This program finds the mode of a set of integers

#include <algorithm>
#include <iostream>
#include <vector>

double max(double x, double y)
{
  if (x>y)
    return x;
  return y;
}

int mode(std::vector<int> vec)
{
  int mode;
  int max_frequency = 1;
  int counter = 0;
  // mode is the value in a sequence that occurs most
  std::sort(vec.begin(), vec.end());

  for (int i = 1; i < int(vec.size()); ++i)
  {
    if (vec[i] == vec[i-1])
    {
      ++counter;
    }
    else
    {

    }

  }


}

int main()
{
  int integer;
  std::vector<int> integers;
  std::cout << "+-----------+\n";
  std::cout << "| Find Mode |\n";
  std::cout << "+-----------+\n\n";

  std::cout << "\nHow this program works:";
  std::cout << "\n---------------------------------------------";
  std::cout << "\n- Enter sequence of space separated integers.";
  std::cout << "\n- End set of integers with a | ";
  std::cout << "\n- To exit the program enter - .";
  std::cout << "\n---------------------------------------------";

  std::cout << "\n\nIntegers: ";
  while (std::cin >> integer)
  {
    integers.push_back(integer);
  }
  // for (int x: integers)
  // {
  //   std::cout << x << '\n';
  // }
  return 0;
}
