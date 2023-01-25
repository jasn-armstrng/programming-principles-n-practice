// Chrono namespace contains Month and Date classes, and the declarations of
// their helper member-functions
#include <iostream> // for istream and ostream facilities

namespace Chrono { // Namespaces organizes classes, functions, data, and types
                   // into an identifiable and named part of a program without
                   // defining an overarching type. Keep code neat. Well docu-
                   // ment your namespaces for the next programmer.
  enum class Month {
    // An enum (enumeration) is a very simple user-defined type, specifying its
    // set of values (its enumerators) as synbolic constants.
    // The values below are only is the scope of the enum class. To access them
    // outside the class we have to say Month::jan ...

    // Here the jan initialized as 1 begins a sequence that continues with feb=2,
    // mar=3 ...
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
  }; // end of class

  class Date {
    public: // interface details
      class Invalid{};            // to throw as exception

      // Date, is a member function definition
      Date(int y, Month m, int d); // Check for valid date and initialize.
                                   // Note m is custom enum type Month
      Date();                      // default constructor
      // the default copy operations are fine

      // non-modifying operations: const members cannot modify objects.
      // We use const right after the function's arg list to indicate that the
      // member function call be called on a const object. The compiler holds
      // this function to its non-modifiying "promise".
      int day() const { return d; }
      Month month() const { return m; }
      int year() const { return y; }

      // modifying operations:
      void add_day(int n);
      void add_month(int n);
      void add_year(int n);

      // Note: we could have defined the above Date and modifying functions in
      //       the class definition however those function can be many lines long
      //       making out class larger and messier. It's fine to define smaller
      //       functions like the non-modifiyings in class. See rule of thumb
      //       after namespace.

    private: // implementation details
      int y;
      Month m;
      int d;
  };

  // helper function declarations
  // they are all class member functions
  bool is_date(int y, Month m, int d);  // Month class, the ones below are Date
  bool leapyear(int y);        // true if a leap year
    // operator overloads
  bool operator==(const Date& a, const Date& b);
  bool operator!=(const Date& a, const Date& b);

    // output stream
  std::ostream& operator<<(std::ostream& os, const Date& d);
    // input stream
  std::istream& operator<<(std::istream& os, const Date& d);

} // end of namespace Chrono


// Further notes:
// 1. Rule of thumb - Don't put member functions bodies in the class declaration
//    unless you know that you need the performance boost from inlining tiny
//    functions.
// 2. We rarely inline a function that that consist of more than one or two
//    expressions
