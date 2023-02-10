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
  enum class Month // Used to construct a new date in the form dd/mm/yyyy
  {
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
  };

  bool is_date(const int d, const Month m, const int y);

  class Date
  {
    public:
      Date(int date, Month month, int year):d{date}, m{month}, y{year}
      {
        // Check if day and year are valid. If not throw error
        if(!is_date(date, month, year)) { error("Invalid date value(s)!"); }
      }

      // Non-modifying member functions
      int dd() const { return d; } // 1-31
      int mm() const { return int(m); } // 1-12
      Month mon() const { return m; } // Jan-Dec
      int yr() const { return y; } // 1-9999 AD

    private:
      int d; // date
      Month m; // month
      int y; // year
  };

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

    return true;
  }
};
