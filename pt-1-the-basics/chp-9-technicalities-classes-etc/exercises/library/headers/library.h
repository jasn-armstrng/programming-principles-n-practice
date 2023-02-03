/**
 * @file library.h
 * @author Jason Armstrong
 * @brief Contains the definitions for classes and helper functions
 * @version 0.1
 * @date 2023-02-01
 *
 */

#include <iostream>

class Invalid {}; // To be used as exception
bool is_isbn(std::string& isbn);

class Book
{
public:
  Book(std::string isbn, std::string title, std::string author, std::string copyright_date)
    :ISBN{isbn}, Title{title}, Author{author}, Copyright_Date{copyright_date}
  {
    if(!is_isbn(isbn)) { throw Invalid {}; }
    Checked_Out = false;
  };

  std::string isbn() const { return ISBN; }
  std::string title() const { return Title; }
  std::string author() const { return Author; }
  std::string copyright_date() const { return Copyright_Date; }
  bool checked_out() const { return Checked_Out; }

private:
  std::string ISBN, Title, Author, Copyright_Date; // Using ISBN-13
  bool Checked_Out;
};

bool is_isbn(std::string& isbn)
{
  // A valid ISBN-13,
  // - starts with 978
  // - is 14 digits long
  // - has the form 978-n, where n is a 10-digit number
  if(isbn.size() != 14) { return false; }
  if(isbn.substr(0, 4) != "978-") { return false; }
  for(unsigned i = 4; i < isbn.size(); ++i)
  {
    if(!std::isdigit(isbn[i])) { return false; }
  }
  return true;
}

std::ostream& operator<<(std::ostream& os, Book& book)
{
  // Enables output of a Book object's state
  return os << "Title: " << book.title() << '\n'
            << "Author: " << book.author() << '\n'
            << "ISBN-13: " << book.isbn() << '\n'
            << "Copyright Date: " << book.copyright_date() << '\n'
            << "Available: " << (book.checked_out() ? "No" : "Yes") << '\n';
}

bool operator==(Book& a, Book& b)
{
  return (a.isbn() == b.isbn());
}
