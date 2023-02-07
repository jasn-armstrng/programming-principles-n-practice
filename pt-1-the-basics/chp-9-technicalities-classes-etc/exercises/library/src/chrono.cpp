#include "../headers/chrono.h"

namespace Chrono {
  // member function definitions
  // - when we define a member outside its class we need to say which class it
  //   it belongs to and we do that with the class_name::member_name notation
  Date::Date(int yy, Month mm, int dd)
    // below is how we initialize members. It's called a member initializer list
    :y{yy}, m{mm}, d{dd} // these are the private members
    {
      if(!is_date(yy, mm, dd)) {
        throw Invalid{};
      }
    }

  const Date& default_date() {
    // we use static to get a variable dd that is created only once (rather than
    // each time default_date() is called) and initialized the first time
    // default date is called.
    static Date dd(2001, Month::jan, 1);
    return dd;
  }

  Date::Date() // default date constructor
    // note that the default constructor does not need to check its value; the
    // constructor for default_date() already did that.
    :y{default_date().year()},  // 2001
     m{default_date().month()}, // jan
     d{default_date().day()}    // 1
  {
    // does nothing except initializes members with the default date values
  }

  void Date::add_day(int n) {
    // increase date by n days
    // pre-conditions: n must be a +ve integer
    // ...
  }

  void Date::add_month(int n) {
    // increase date by n months
    // pre-conditions: n must be a +ve integer
    // ...
  }

  void Date::add_year(int n) {
    // if not a leap year go to Mar 1
    if(m == Month::feb && d == 29 && !leapyear(y+n)) {
      m = Month::mar; // use March 1 instead of February 29
      d = 1;
    }
    y += n; // then increment the year
  }

  // helper functions:
  bool is_date(int y, Month m, int d) {
    // assume y is valid
    if (d <= 0) { return false; } // (d)ays must be +ve
    if (m < Month::jan || Month::dec < m) { return false; } // month: 1 - 12

    int days_in_month = 31; // most months have 31 days

    switch(m) {
      case Month::feb: // Feb is 29 for leap years
        days_in_month = leapyear(y) ? 29 : 28; // assign using ternary exp
        break;
      case Month::apr: case Month::jun: case Month::sep: case Month::nov:
        days_in_month = 30; // the rest have 30
        break;
      default:
        days_in_month = 31;
        break;
    }

    if(days_in_month < d) { return false; }

    return true;
  }

  bool leapyear(int y) {
    // a leap year is divisible by 4 or 400 but not 100
    if(y % 400 == 0) { return true; }
    if(y % 100 == 0) { return false; }
    if(y % 4 == 0) { return true; }
    return false;
  }

  bool operator==(const Date& a, const Date& b) {
    return a.year() == b.year()
        && a.month() == b.month()
        && a.day() == b.day();
  }

  bool operator!=(const Date& a, const Date& b) {
    return !(a == b);
  }

  // << operator overloading. Allows the output of a data object to the console
  std::ostream& operator<<(std::ostream& os, const Date& d) {
    return os << '(' << d.year()
              << ',' << int(d.month()) // error: invalid operands to binary expression
              << ',' << d.day() << ')';
  }

  // >> operator overloading. Allows the input of a data object from the console
  std::istream& operator>>(std::istream& is, Date& dd) {
    int y, m, d;
    char ch1, ch2, ch3, ch4;

    is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
    if(!is) { return is; }
    if(ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')') { // oops: format error
      is.clear(std::ios_base::failbit);                        // set the failbit
      return is;
    }

    dd = Date(y, Month(m), d); // update dd
    return is;
  }

  enum class Day {
    sunday, monday, tuesday, wednesday, thursday, friday, saturday
  };

  Day day_of_week(const Date& d) {
    // ...
  }

  Date next_sunday(const Date& d) {
    // ...
  }

  Date next_weekday(const Date& d) {
    // ...
  }
} // End of Chrono namespace
