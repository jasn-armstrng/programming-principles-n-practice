/**
 * @file chrono.h
 * @author Jason Armstrong
 * @brief A re-implementation of the Date class from chapter 9
 * @version 0.1
 * @date 2023-02-10
 */

#include <iostream>
#include "./std_lib_facilities.h"

namespace Chrono
{
  enum class Month
  {
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
  };


  enum class Day
  {
    mon=1, tues, wed, thurs, fri, sat, sun
  };


  bool is_date(const int d, const Month m, const int y);
  bool is_leap_year(int y);


  class Date
  {
    public:
      Date(int date, Month month, int year); // Date constructor

      Date(); // Default date constructor

      // Non-modifying member functions
      int dd() const { return d; } // 1-31
      int mm() const { return int(m); } // 1-12
      Month mon() const { return m; } // Jan-Dec
      int yr() const { return y; } // 1-9999 AD

      // Modifying member functions
      void add_day(int n); // to implement
      void add_month(int n); // to implement
      void add_year(int n);

    private:
      int d; // date
      Month m; // month
      int y; // year
  };

  // Member functions ..........................................................
  Date::Date(int date, Month month, int year):d{date}, m{month}, y{year}
  {
    // Check if day and year are valid. If not throw error
    if(!is_date(date, month, year)) { error("Invalid date value(s)!"); }
  }


  const Date& default_date() // Define default date 1/1/1970
  {
    static Date def_dt { 1, Month::jan, 1970 };
    return def_dt;
  }


  Date::Date():d{default_date().dd()},
               m{default_date().mon()},
               y{default_date().yr()} { }


  void Date::add_year(int n)
  {
    if(m == Month::feb && d == 29 && !is_leap_year(y + n))  // beware of leap years
    {
      d = 1;
      m = Month::mar;
    }
    y += n;
  }

  // Helper functions ..........................................................
  std::ostream& operator<<(std::ostream& os, const Month& month)
  {
    switch (month)
    {
      case Month::jan: return os << "Jan"; break;
      case Month::feb: return os << "Feb"; break;
      case Month::mar: return os << "Mar"; break;
      case Month::apr: return os << "Apr"; break;
      case Month::may: return os << "May"; break;
      case Month::jun: return os << "Jun"; break;
      case Month::jul: return os << "Jul"; break;
      case Month::aug: return os << "Aug"; break;
      case Month::sep: return os << "Sep"; break;
      case Month::oct: return os << "Oct"; break;
      case Month::nov: return os << "Nov"; break;
      case Month::dec: return os << "Dec"; break;
      default: return os; break;
    };
  }


  std::ostream& operator<<(std::ostream& os, const Date& date)
  {
    return os << date.dd() << '/' << date.mm() << '/' << date.yr(); // dd/mm/yyyy
  }


  bool operator==(Date& a, Date& b)
  {
    return a.dd() == b.dd() &&
           a.mm() == b.mm() &&
           a.yr() == b.yr();
  }


  bool is_leap_year(int y)
  {
    // a leap year is divisible by 4 or 400 but not 100
    if(y % 400 == 0) { return true; }

    if(y % 100 == 0) { return false; }

    if(y % 4 == 0) { return true; }

    return false;
  }


  bool is_date(const int d, const Month m, const int y)
  {
    // Valid date checks
    if(d < 1) { return false; } // date >= 1

    if(m < Month::jan || m > Month::dec) { return false; } // 1 <= month <= 12

    int days_in_month;
    switch(m) // month day values in "30 days has September ..." mnemonic applies
    {
      case Month::feb:
        days_in_month = is_leap_year(y) ? 29 : 28; // if leap year Feb 29 is allowed
        break;
      case Month::apr: case Month::jun: case Month::sep: case Month::nov:
        days_in_month = 30;
        break;
      default:
        days_in_month = 31;
        break;
    }

    if(d > days_in_month) { return false; } // date <= (at most) 31

    if(y < 1 || y > 9999) { return false; } // 1 <= year <= 9999

    return true;
  }


  Date next_workday(Date& d)
  {
    // Workdays are Mon-Fri
  }
};
