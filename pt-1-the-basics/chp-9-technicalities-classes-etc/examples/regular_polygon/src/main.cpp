// This program written to implement and understand polymorphism
// More on polymorphism here,
//  - https://cplusplus.com/doc/tutorial/polymorphism/, and
//  - https://www.youtube.com/watch?v=wK93q-JQUvw&t=52s

#include <iostream>
#include <vector>
#include "../headers/regular_polygon.h"
using namespace Shape;

int main() try {
  // Use polymorphism to link Base class to instances of derived classes
  RegularPolygon* tri = new Triangle(7, 4);
  RegularPolygon* sqr = new Square(13, 13);

  // Store and retrieve derived classes of polygon under their base class.
  std::vector<RegularPolygon*> polygons;
  polygons.push_back(tri);
  polygons.push_back(sqr);
  for(RegularPolygon* p: polygons) {
    // Sample output: Triangle area: 14
    std::cout << p->type() << " area: " << p->area() << '\n';
  }

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
