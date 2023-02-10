/**
 * @file chrono.h
 * @author Jason Armstrong
 * @brief A re-implementation of the Date class from chapter 9
 * @version 0.1
 * @date 2023-02-10
 */

namespace Chrono
{
  enum class Month // Used to construct a new date in the form dd/mm/yyyy
  {
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
  };

  class Date
  {
    Date(int& day, Month& month, int& year):dd{day}, mm{month}, yyyy{year} { }

    private:
      int dd;
      Month mm;
      int yyyy;
  };
};
