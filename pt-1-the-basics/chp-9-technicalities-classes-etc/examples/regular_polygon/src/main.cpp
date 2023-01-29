// This program written to implement and understand polymorphism

#include <iostream>
#include "../headers/regular_polygon.h"
using namespace Shape;

int main() try {
  Triangle tri(7, 4);
  Square sqr(14, 14);

  std::cout << tri.type() << " area: " << tri.area() << '\n';
  std::cout << sqr.type() << " area: " << sqr.area() << '\n';
  return 0;
}
catch(RegularPolygon::Invalid) {
  std::cerr << "Error: Both width and height must be greater than zero.\n";
  return 1;
}
catch(...) {
  std::cerr << "Error: Unknown exception.\n";
  return 2;
}
