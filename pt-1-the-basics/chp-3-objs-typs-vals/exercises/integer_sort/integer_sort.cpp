// This program sorts 3 integers from user and returns them sorted.
// Duplicated integers should appear in sequence.

#include <iostream>
int main()
{
  int val1, val2, val3;
  int first = 0; int second = 0; int third = 0;
  std::cout << "+--------------+\n";
  std::cout << "| Integer Sort |\n";
  std::cout << "+--------------+\n\n";
  std::cout << "Please enter 3 integer values: ";
  std::cin >> val1 >> val2 >> val3;

  // The following ifs do comparisons and swap using bitwise xor.
  if (val1 > val2)
  {
    val1 ^= val2;
    val2 ^= val1;
    val1 ^= val2;
  }

  if (val1 > val3)
  {
    val1 ^= val3;
    val3 ^= val1;
    val1 ^= val3;
  }

  if (val2 > val3)
  {
    val2 ^= val3;
    val3 ^= val2;
    val2 ^= val3;
  }

  std::cout << "\nSorted: " << val1 << ' ' << val2 << ' ' << val3 << '\n';
  return 0;
}
