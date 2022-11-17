// This program computes the roots of a quadratic equation
#include <cmath>
#include <iostream>
// function declaration(s)
void solve_quadratic(double a, double b, double c);
int main(){
  // a = 1, b = -5, c = 6, Roots: x = 2, 3
  // a = 5, b = 6, c = 1, Roots: x = − 0.2, −1

  solve_quadratic(1, -5, 6);
  solve_quadratic(5, 6, 1);
  return 0;
}

// function definition(s)
void solve_quadratic(double a, double b, double c){
  // compute the roots of a quadratic equation ax^2+bx+c=0
  // pre-conditions: b^2-4ac > 0
  // post-conditions: return the real roots of the quadratic equation
  double r1 = (-b + std::sqrt((b*b)-4*(a*c)))/(2*a);
  double r2 = (-b - std::sqrt((b*b)-4*(a*c)))/(2*a);
  std::cout << "Root: " << r1 << " or " << r2 << '\n';
}
