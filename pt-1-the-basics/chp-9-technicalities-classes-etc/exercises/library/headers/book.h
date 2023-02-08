/**
 * @file book.h
 * @author Jason Armstrong
 * @brief Book class, its and its members' definitions and helper functions
 * @version 0.1
 * @date 2023-02-07
 */

#include <iostream>
#include "./std_lib_facilities.h" // For error()

enum class Genre // Book genres
{
  fiction, nonfiction, periodical, biography, children
};


class Book
{
  public:
    // Constructor
    Book(std::string isbn, std::string title, std::string author,
         std::string copyright_date, Genre genre);

    // Getters
    std::string isbn() const { return ISBN; }
    std::string title() const { return Title; }
    std::string author() const { return Author; }
    std::string copyright_date() const { return Copyright_Date; }
    Genre genre() const { return GENRE; }
    bool checked_out() const { return Checked_Out; }

    // Setters
    void checkout(Book& b) { b.Checked_Out = true; }

  private:
    std::string ISBN, Title, Author, Copyright_Date; // Using ISBN-13
    bool Checked_Out { false };
    Genre GENRE;
};


bool is_isbn(std::string& isbn);


// Member function definitions .................................................
Book::Book(std::string isbn, std::string title, std::string author,
           std::string copyright_date, Genre genre):ISBN{isbn}, Title{title},
           Author{author}, Copyright_Date{copyright_date}, GENRE{genre}
{
  if(!is_isbn(isbn))
  {
    error("ISBN(-13) should be in the form 978-n, where n is a 10-digit number.\n");
  }
};


// Helper functions ............................................................
bool is_isbn(std::string& isbn)
{
  // Checks if ISBN-13 is valid
  if(isbn.size() != 14) { return false; } // is 14 digits long
  if(isbn.substr(0, 4) != "978-") { return false; } // starts with 978
  for(unsigned i = 4; i < isbn.size(); ++i) // has the form 978-n, where n is a 10-digit number
  {
    if(!std::isdigit(isbn[i])) { return false; }
  }
  return true;
}


std::ostream& operator<<(std::ostream& os, const Genre& genre)
{ // Enables descriptive form of book's genre
  switch(genre)
  {
    case Genre::fiction:
      return os << "Fiction";
      break;
    case Genre::nonfiction:
      return os << "Nonfiction";
      break;
    case Genre::biography:
      return os << "Biography";
      break;
    case Genre::children:
      return os << "Children";
      break;
    case Genre::periodical:
      return os << "Periodical";
      break;
    default:
      return os;
  }
}


std::ostream& operator<<(std::ostream& os, const Book& book) // Enables output of a Book object's state
{
  return os << "Title: " << book.title() << '\n'
            << "Author: " << book.author() << '\n'
            << "ISBN-13: " << book.isbn() << '\n'
            << "Copyright Date: " << book.copyright_date() << '\n'
            << "Genre: " << book.genre() << '\n'
            << "Available: " << (book.checked_out() ? "No" : "Yes");
}


bool operator==(const Book& a, const Book& b)
{
  return (a.title() == b.title());
}


bool operator!=(const Book& a, const Book& b)
{
  return !(a.title() == b.title());
}
