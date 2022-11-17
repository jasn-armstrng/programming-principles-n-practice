// This program computes the roots of a quadratic equation
#include <cmath>
#include <iostream>
// function declaration(s)
inline void error(const std::string& s);
inline void keep_window_open();
void solve_quadratic(double a, double b, double c);

int main()
try{
  solve_quadratic(1, 2, 3);
  return 0;
}
catch(std::exception& e){
  std::cerr << "\nError: " << e.what() << '\n';
  keep_window_open();
  return 1;
}
catch(...){
  std::cerr << "\nError: Unknown exception\n";
  keep_window_open();
  return 2;
}

// function definition(s)
inline void error(const std::string& s){throw std::runtime_error(s);}

inline void keep_window_open(){char ch; std::cin>>ch;}

void solve_quadratic(double a, double b, double c){
  // compute the roots of a quadratic equation ax^2+bx+c=0
  // pre-conditions: b^2-4ac > 0
  // post-conditions: return the real roots of the quadratic equation
  if(b*b-(4*a*c)<0){error("no real roots found");}
  double r1 = (-b + std::sqrt((b*b)-4*a*c))/(2*a);
  double r2 = (-b - std::sqrt((b*b)-4*a*c))/(2*a);
  std::cout << "Root: " << r1 << " or " << r2 << '\n';
}


// a = 1, b = -5, c = 6, Roots: x = 2, 3
// a = 5, b = 6, c = 1, Roots: x = − 0.2, −1
// a = 1, b = 2, c = 3, Roots: No real roots

// solve_quadratic(1, -5, 6);
// solve_quadratic(5, 6, 1);
