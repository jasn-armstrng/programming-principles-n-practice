/**
 * @file chrono.h
 * @author Jason Armstrong
 * @brief Date class definition and member declarations. See member definitions
 *        in chrono.cpp
 * @version 0.1
 * @date 2023-02-06
 */

#include <iostream> // for istream and ostream facilities

namespace Chrono {
  enum class Month
  {
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
  };

  class Date
  {
    public:
      class Invalid{}; // to be used as exception

      Date(int y, Month m, int d); // Check for valid date and initialize.
      Date(); // default constructor

      // Getters
      int day() const { return d; }
      Month month() const { return m; }
      int year() const { return y; }

      // Setters
      void add_day(int n);
      void add_month(int n);
      void add_year(int n);

    private:
      int y;
      Month m;
      int d;
  };

  // Helper function declarations ..............................................
  bool is_date(int y, Month m, int d);  // Month class, the ones below are Date


  bool leapyear(int y); // true if a leap year


  bool operator==(const Date& a, const Date& b);


  bool operator!=(const Date& a, const Date& b);


  std::ostream& operator<<(std::ostream& os, const Date& d);


  std::istream& operator>>(std::istream& os, const Date& d);
}
