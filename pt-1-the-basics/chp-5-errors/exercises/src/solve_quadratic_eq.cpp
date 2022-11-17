// This program computes the roots of a quadratic equation
#include <cmath>
#include <iostream>
// function declaration(s)
inline void error(const std::string& s);
inline void keep_window_open();
void solve_quadratic(double a, double b, double c);
void ui();

int main()
try{
  std::cout << "+--------------------------+\n";
  std::cout << "| Solve Quadratic Equation |\n";
  std::cout << "+--------------------------+\n\n";
  ui();
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
  std::cout << "\nRoots: " << r1 << " and " << r2 << "\n";
}

void ui(){
  // presents gui
  // Note: Does not validate input.
  double a, b, c;
  std::cout << "For ax^2 + bx + c = 0, enter a b c: ";
  std::cin>>a>>b>>c;
  solve_quadratic(a, b, c);
}

/*
Test cases:
a = 1, b = -5, c = 6, Roots: 2, 3
a = 5, b = 6, c = 1, Roots: -0.2, -1
a = 1, b = 2, c = 3, Roots: No real roots
*/
