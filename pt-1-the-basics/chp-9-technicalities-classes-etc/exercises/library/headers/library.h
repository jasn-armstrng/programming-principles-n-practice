/**
 * @file library.h
 * @author Jason Armstrong
 * @brief Library class, its and its members' definitions and helper functions.
 *        The class that makes use of the Chrono, Book, and Patron classes
 * @version 0.1
 * @date 2023-02-01
 * @todo Complete outstanding_fees(): To do this objects in Patron must be updated
 *       when the object referenced is updated. I considered a vector of references
 *       but I'm unsure of the right implementation. Further into book should provide
 *       an example or a better design pattern.
 */

#include <iostream>
#include <vector>
#include "./chrono.h"
#include "./book.h" // Access to error() also thru here
#include "./patron.h"

using namespace Chrono; // for Date type in Transaction


struct Transaction {
  Book book;
  Patron patron;
  Date date;
};


class Library {
  public:
    // Getters
    void books() const;
    std::vector<Patron> patrons() const { return Patrons; }
    void outstanding_fees() const;

    // Setters
    void add_book(const Book& book) { Books.push_back(book); }
    void add_patron(const Patron& patron) { Patrons.push_back(patron); }
    void checkout_book(const Patron& patron, Book& book);

  private:
    std::vector<Book> Books;
    std::vector<Patron> Patrons;
    std::vector<Transaction> transactions;

    // Verification methods for books and patrons
    bool book_exists(const Book& book) const;
    bool patron_exists(const Patron& patron) const;
};

// Member function definitions .................................................
void Library::books() const
{
  for(Book b: Books) { std::cout << b.title() << '\n'; }
}


bool Library::book_exists(const Book& book) const
{
  for(Book b: Books) { if(book == b) { return true; } }
  return false;
}


bool Library::patron_exists(const Patron& patron) const
{
  for(Patron p: Patrons) { if(patron == p) { return true; } }
  return false;
}


void Library::checkout_book(const Patron& patron, Book& book)
{
  // Verify if transa
  if(!patron_exists(patron)) { error("Patron does not exists!"); }
  if(!book_exists(book)) { error("Book does not exists!"); }
  if(patron.has_fees()) { error("Patron has outstanding fees!"); }

  Transaction transaction { book, patron, Date{2023, Month::feb, 8} };
  transactions.push_back(transaction);
  book.checkout(book);
}


void Library::outstanding_fees() const
{
  std::cout << "Patrons who owe fees" << '\n';
  for(Patron p: Patrons)
  {
    std::cout << p.fees() << '\n';
    // if(p.has_fees())
    // {
    //   std::cout << "Name: " << p.user_name() << "\tFees: " << p.fees() << '\n';
    // }
  }
}
