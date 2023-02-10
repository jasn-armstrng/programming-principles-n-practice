/**
 * @file chrono.h
 * @author Jason Armstrong
 * @brief A re-implementation of the Date class from chapter 9
 * @version 0.1
 * @date 2023-02-10
 */

#include <iostream>

namespace Chrono
{
  enum class Month // Used to construct a new date in the form dd/mm/yyyy
  {
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
  };


  class Date
  {
    public:
      Date(int date, Month month, int year):d{date}, m{month}, y{year}
      {
        // Check if day and year are valid. If not throw error
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
};
