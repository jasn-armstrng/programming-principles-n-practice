// This program solves quadratic equations. A quadratic equation is of the form,
// ax^2 + bx + c = 0

#include <cmath>
#include <iostream>
#include <tuple>

std::tuple<double, double> solve_quadratic(double a, double b, double c);

int main()
{
  double a, b, c, result1, result2;

  std::cout << "+---------------------------+\n";
  std::cout << "| Quadratic Equation Solver |\n";
  std::cout << "+---------------------------+\n";

  std::cout << "\nEquation form: ax^2 + bx + c = 0\n\n";
  std::cout << "a = "; std::cin >> a;
  std::cout << "b = "; std::cin >> b;
  std::cout << "c = "; std::cin >> c;

  // std::tie(result1, result2) = solve_quadratic(1, -5, 6);
  // std::cout << "\nEquation: x^2 + -5x + 6 = 0";
  // std::cout << "\nSolution: x=" << result1 << " or x=" << result2 << '\n';
  // Tests
  // std::tie(result1, result2) = solve_quadratic(1, -5, 6);
  // std::cout << "\nEquation: x^2 + -5x + 6 = 0";
  // std::cout << "\nSolution: x=" << result1 << " or x=" << result2 << '\n'; // expect 3, 2

  // std::tie(result1, result2) = solve_quadratic(5, 6, 1);
  // std::cout << "\nEquation: 5x^2 + 6x + 1 = 0";
  // std::cout << "\nSolution: x=" << result1 << " or x=" << result2 << '\n'; // expect -0.2, -1

  return 0;
}

std::tuple<double, double> solve_quadratic(double a, double b, double c)
{
  double x1, x2;
  // Compute solutions
  x1 = (-b + std::sqrt((b*b)-4*(a*c)))/(2*a);
  x2 = (-b - std::sqrt((b*b)-4*(a*c)))/(2*a);

  return std::make_tuple(x1, x2);
}
