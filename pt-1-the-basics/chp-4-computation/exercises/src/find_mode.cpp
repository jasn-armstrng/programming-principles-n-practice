// This program finds the mode of a set of integers

#include <iostream>
#include <vector>

int main()
{
  int integer;
  std::vector<int> integers;
  std::cout << "+-----------+\n";
  std::cout << "| Find Mode |\n";
  std::cout << "+-----------+\n\n";

  std::cout << "\nHow this program works:";
  std::cout << "\n----------------------------------------";
  std::cout << "\n- Enter set of space separated integers.";
  std::cout << "\n- End set of integers with a | ";
  std::cout << "\n- To exit the program enter - .";
  std::cout << "\n----------------------------------------";

  std::cout << "\n\nIntegers: ";
  while (std::cin >> integer)
  {
    integers.push_back(integer);
  }
}
