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

class Book
{
public:
  Book(std::string ISBN, std::string Title, std::string Author, std::string Copyright_Date)
    :isbn{ISBN}, title{Title}, author{Author}, copyright_date{Copyright_Date} {};

private:
  std::string isbn, title, author, copyright_date;
  bool checked_out;
};
