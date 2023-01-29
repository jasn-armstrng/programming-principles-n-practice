namespace Shape {
  // Contains the definitions for the RegularPolygon class and its derived classes
  class RegularPolygon {
    // Polygon base class
    public:
      RegularPolygon(const double w, const double h) { // w: width, h: height
        width = w;
        height = h;
      }

    private:
      double width;
      double height;
  };
};
