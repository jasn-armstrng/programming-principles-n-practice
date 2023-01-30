#include <iostream>

namespace Shape {
  // Contains the definitions for the RegularPolygon class and its derived classes
  class RegularPolygon { // Polygon base class
    public:
      class Invalid {}; // Used to throw exception
      RegularPolygon(const double w, const double h); // Constructor defined in
                                                      // ../src/regular_polygon.cpp
      virtual double area() { return 0; } // 'placeholder' to access area() defined
                                          // in the derived classes when implementing
                                          // polymorphism
      virtual std::string type() { return ""; } // Same as with area()

    protected:
      double width;
      double height;
  };

  class Triangle:public RegularPolygon { // RegularPolygon derived class
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
} // namespace Shape
