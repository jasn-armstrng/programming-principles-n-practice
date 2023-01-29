namespace Shape {
  // Contains the definitions for the RegularPolygon class and its derived classes
  class RegularPolygon {
    // Polygon base class
    public:
      RegularPolygon(const double w, const double h) { // w: width, h: height
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

      double area() { return (width * height) * 0.5; } // Compute triangle area
  };

  class Square:public RegularPolygon {
    public:
      Square(const double w, const double h):RegularPolygon(w, h) { }

      double area() { return (width * height); } // Compute square area
  };
};
