// This program sorts 3 strings from user and returns them sorted.
// Duplicated strings should appear in sequence.

#include <iostream>
int main()
{
  std::string s1, s2, s3;
  std::cout << "+-------------+\n";
  std::cout << "| String Sort |\n";
  std::cout << "+-------------+\n\n";
  std::cout << "Please enter 3 string values: ";
  std::cin >> s1 >> s2 >> s3;

  // The following ifs do comparisons and swap using bitwise xor.
  // if (s1 > s2)
  // {

  // }

  std::cout << "\nSorted: " << s1 << ' ' << s2 << ' ' << s3 << '\n';
  return 0;
}
