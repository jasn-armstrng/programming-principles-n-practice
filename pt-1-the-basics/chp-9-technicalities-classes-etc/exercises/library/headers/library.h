/**
 * @file library.h
 * @author Jason Armstrong
 * @brief Contains the definitions for classes and helper functions
 * @version 0.1
 * @date 2023-02-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>

class Invalid {};
bool is_isbn(std::string& ISBN);

class Book
{
public:
  Book(std::string ISBN, std::string Title, std::string Author, std::string Copyright_Date)
    :isbn{ISBN}, title{Title}, author{Author}, copyright_date{Copyright_Date}
  {
    if(!is_isbn(ISBN)) { throw Invalid {}; }
  };

private:
  std::string isbn, title, author, copyright_date;
  bool checked_out;
};

bool is_isbn(std::string& ISBN)
{
  // a valid ISBN-13,
  // - starts with 978
  // - is 13 digits long
  if(ISBN.size() != 14) { return false; }
  if(ISBN.substr(0, 4) != "978-") { return false; }
  for(unsigned i = 4; i < ISBN.size(); ++i)
  {
    if(!std::isdigit(ISBN[i])) { return false; }
  }
  return true;
}
