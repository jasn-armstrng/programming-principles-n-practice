#include "../headers/regular_polygon.h"

namespace Shape {
  // definition for RegularPolygon class constructor
  RegularPolygon::RegularPolygon(const double w, const double h) { // w: width, h: height
    // Base class constructor
    // pre-conditions: Both width and height should be > 0

    if(w < 1 || h < 1) { throw Invalid {}; } // check width/height validity

    width = w;
    height = h;
  }
} // namespace Shape
