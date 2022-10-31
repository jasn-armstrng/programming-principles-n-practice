// This program is a test of the type safety conversion of bool to char.

#include <iostream>
int main()
{
  bool b = true; // bool can be 1, 0, true, false
  char c = b;
  bool d = c == b;
  std::cout << c; // returns nothing
  std::cout << d; // returns 1
}
