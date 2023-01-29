#include <iostream>

namespace Shape {
  // Contains the definitions for the RegularPolygon class and its derived classes
  class RegularPolygon {
    // Polygon base class
    public:
      class Invalid {}; // Used to throw exception

      RegularPolygon(const double w, const double h) { // w: width, h: height
        // Base class constructor
        // pre-conditions: Both width and height should be > 0

        if(w < 1 || h < 1) { throw Invalid {}; } // check width/height validity

        width = w;
        height = h;
      }

    protected:
      double width;
      double height;
  };

  class Triangle:public RegularPolygon {
    public:
      Triangle(const double w, const double h):RegularPolygon(w, h) { }
      std::string type() { return "Triangle"; }
      double area() { return (width * height) * 0.5; } // Compute triangle area
  };

  class Square:public RegularPolygon {
    public:
      Square(const double w, const double h):RegularPolygon(w, h) { }
      std::string type() { return "Square"; }
      double area() { return (width * height); } // Compute square area
  };
};
