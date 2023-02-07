/**
 * @file library.h
 * @author Jason Armstrong
 * @brief Contains the definitions for classes and helper functions
 * @version 0.1
 * @date 2023-02-01
 *
 */

#include <iostream>
#include <vector>
#include "./chrono.h"

using namespace Chrono; // for Date type in Transaction


bool is_isbn(std::string& isbn);


class Invalid {}; // Used as an exception


inline void error(const std::string& s) { throw std::runtime_error(s); }


enum class Genre
{
  // Book genres
  fiction,
  nonfiction,
  periodical,
  biography,
  children
};


class Book
{
  public:
    // Constructor
    Book(std::string isbn, std::string title, std::string author, std::string copyright_date, Genre genre)
      :ISBN{isbn}, Title{title}, Author{author}, Copyright_Date{copyright_date}, GENRE{genre}
    {
      if(!is_isbn(isbn)) { error("ISBN(-13) should be in the form 978-n, where n is a 10-digit number.\n"); }
      Checked_Out = false;
    };

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
    bool Checked_Out;
    Genre GENRE;
};


int sequence {0};


class Patron
{
  public:
    Patron(std::string user_name):User_Name{user_name}
    {
      ++sequence;
      Library_Card_Number = std::to_string(sequence);
    }

    // Getters
    std::string user_name() const { return User_Name; }
    std::string library_card_number() const { return Library_Card_Number; }
    double library_fees() const { return Library_Fees; }

    // Setters
    void set_library_fees(Patron& patron, double fee) {
      patron.Library_Fees += fee;
      owes_fee = true;
    }

  private:
    std::string User_Name;
    std::string Library_Card_Number;
    double Library_Fees { 0 };
    bool owes_fee { false };
};


class Library {
  public:
    // Getters
    void list_books() const { for(Book b: Books) { std::cout << b.title() << '\n'; } }
    std::vector<Patron> patrons() const { return Patrons; }

    // Setters
    void add_book(const Book& book) { Books.push_back(book); }
    void add_patron(const Patron& patron) { Patrons.push_back(patron); }

    void checkout_book(const Patron& patron, Book& book)
    {
      if(!patron_exists(patron)) { error("Patron does not exists!"); }
      if(!book_exists(book)) { error("Book does not exists!"); }
      book.checkout(book);
    }

  private:
    std::vector<Book> Books;
    std::vector<Patron> Patrons;

    bool book_exists(const Book& book) const
    {
      for(Book b: Books)
      {
        if(book.title() == b.title()) { return true; }
      }
      return false;
    }

    bool patron_exists(const Patron& patron) const
    {
      for(Patron p: Patrons)
      {
        if(patron.library_card_number() == p.library_card_number())
        {
          return true;
        }
      }
      return false;
    }
};


struct Transaction {
  Book book;
  Patron patron;
  Date date;
  std::vector<Transaction> transactions;
};


bool is_isbn(std::string& isbn) {
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
{
  // Enables descriptive form of book's genre
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


std::ostream& operator<<(std::ostream& os, const Book& book)
{
  // Enables output of a Book object's state
  return os << "Title: " << book.title() << '\n'
            << "Author: " << book.author() << '\n'
            << "ISBN-13: " << book.isbn() << '\n'
            << "Copyright Date: " << book.copyright_date() << '\n'
            << "Genre: " << book.genre() << '\n'
            << "Available: " << (book.checked_out() ? "No" : "Yes") << '\n';
}


bool operator==(const Book& a, const Book& b)
{
  return (a.title() == b.title());
}


bool operator!=(const Book& a, const Book& b)
{
  return !(a.title() == b.title());
}


bool operator==(const Patron& a, const Patron& b)
{
  return (a.library_card_number() == b.library_card_number());
}
