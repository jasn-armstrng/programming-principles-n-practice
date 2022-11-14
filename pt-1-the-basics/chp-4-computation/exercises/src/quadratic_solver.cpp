// This program solves quadratic equations. A quadratic equation is of the form,
// ax^2 + bx + c = 0

#include <cmath>
#include <iostream>
#include <tuple>

std::tuple<double, double> solve_quadratic(double a, double b, double c);

int main()
{
  double result1, result2;

  std::tie(result1, result2) = solve_quadratic(1, -5, 6);
  std::cout << "\nEquation: x^2 + -5x + 6 = 0";
  std::cout << "\nSolution: x=" << result1 << " or x=" << result2 << '\n';

  std::tie(result1, result2) = solve_quadratic(5, 6, 1);
  std::cout << "\nEquation: 5x^2 + 6x + 1 = 0";
  std::cout << "\nSolution: x=" << result1 << " or x=" << result2 << '\n';

  return 0;
}

std::tuple<double, double> solve_quadratic(double a, double b, double c)
{
  double x1, x2;

  x1 = (-b + std::sqrt((b*b)-4*(a*c)))/(2*a);
  x2 = (-b - std::sqrt((b*b)-4*(a*c)))/(2*a);

  return std::make_tuple(x1, x2);
}
