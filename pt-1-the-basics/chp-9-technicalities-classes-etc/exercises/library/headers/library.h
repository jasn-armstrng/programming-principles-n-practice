/**
 * @file library.h
 * @author Jason Armstrong
 * @brief Contains the definitions for classes and helper functions
 * @version 0.1
 * @date 2023-02-01
 */

#include <iostream>
#include <vector>
#include "./chrono.h"
#include "./book.h"
#include "./patron.h"

using namespace Chrono; // for Date type in Transaction


class Invalid {}; // Used as an exception








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
        if(book == b) { return true; }
      }
      return false;
    }

    bool patron_exists(const Patron& patron) const
    {
      for(Patron p: Patrons)
      {
        if(patron == p) { return true; }
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
