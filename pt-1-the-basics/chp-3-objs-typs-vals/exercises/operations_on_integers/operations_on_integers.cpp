// This program takes as input 2 integers from user and returns these evals:
// 1. min(val1, val2)
// 2. max(val1, val2)
// 3. sum(val1, val2)
// 4. diff(val1, val2)
// 5. mult(val1, val2)
// 6. div(val1, val2)

#include <iostream>

std::string min_max(int v1, int v2)
{
  if (v1 > v2)
    return std::to_string(v1) + " is larger than " + std::to_string(v2);
  else if (v1 < v2)
    return std::to_string(v2) + " is larger than " + std::to_string(v1);
  else
    return "Both are equal.";
}

int main()
{
  int val1, val2;
  std::cout << "Please enter 2 integer values: ";
  std::cin >> val1 >> val2;
  std::cout << val1 << val2;
  return 0;
}
