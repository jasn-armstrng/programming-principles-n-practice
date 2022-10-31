// This program sorts 3 integers from user and returns them sorted

#include <iostream>
int main()
{
  int val1, val2, val3;
  double first, second, third;
  std::cout << "+--------------+\n";
  std::cout << "| Integer Sort |\n";
  std::cout << "+--------------+\n\n";
  std::cout << "Please enter 3 integer values: ";
  std::cin >> val1 >> val2 >> val3;

  if (val1 > val2)
    first = val2;
    second = val1;

  // if (first >= val3)
  //   third = first;
  //   first = val3;

  // if (second >= third)
  //   second ^= third;
  //   third ^= second;
  //   second ^= third;

  std::cout << val1 << ' ' << val2 << ' ' << val3 << '\n';
  std::cout << first << ' ' << second << '\n';
  return 0;
}
