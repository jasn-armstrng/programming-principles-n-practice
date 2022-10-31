// This program takes as input 2 floats from user and returns these evals:
// 1. min(val1, val2)
// 2. max(val1, val2)
// 3. sum(val1, val2)
// 4. diff(val1, val2)
// 5. mult(val1, val2)
// 6. div(val1, val2)

#include <iostream>

std::string min_max(double v1, double v2)
{
  if (v1 > v2)
    return "Smaller: " + std::to_string(v2) + '\n' + "Larger: " + std::to_string(v1) + '\n';
  else if (v1 < v2)
    return "Smaller: " + std::to_string(v1) + '\n' + "Larger: " + std::to_string(v2) + '\n';
  else
    return "Both equal.\n";
}

int main()
{
  double val1, val2;
  std::cout << "+----------------------+\n";
  std::cout << "| Operations on Floats |\n";
  std::cout << "+----------------------+\n\n";
  std::cout << "Please enter 2 floating-point values: ";
  std::cin >> val1 >> val2;
  std::cout << "\n";
  std::cout << min_max(val1, val2);
  std::cout << "Sum: " << val1+val2 << '\n';
  std::cout << "Difference: " << val1-val2 << '\n';
  std::cout << "Product: " << val1*val2 << '\n';
  std::cout << "Ratio: " << val1/val2 << '\n';
  return 0;
}
