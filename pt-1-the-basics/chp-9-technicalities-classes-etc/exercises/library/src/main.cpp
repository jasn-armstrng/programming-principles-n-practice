/**
 * @file main.cpp
 * @author Jason Armstrong
 * @brief
 * @version 0.1
 * @date 2023-02-01
 *
 */

#include <iostream>
#include "../headers/library.h"

int main() try
{
  // Test creation of new book objects, view book state
  Book b1 { "978-0618968636", "The Hobbit", "J. R. R. Tolkien", "January 1, 1973", Genre::fiction };
  std::cout << b1 << '\n';

  std::cout << '\n';

  Book b2 { "978-0006552314", "Daughter of Fortune", "Isabel Allende", "April 1, 2008", Genre::biography };
  std::cout << b2 << '\n';

  std::cout << '\n';

  Book b3 { "978-0142437230", "Don Quixote", "Miguel Cervantes", "February 25, 2003", Genre::fiction };
  std::cout << b3 << '\n';

  std::cout << '\n';

  // Test book comparison
  std::cout << (b1 == b2) << '\n';
  std::cout << (b1 != b2) << '\n';

  // Test library object creation and adding books
  Library l1;
  l1.add_book(b1);
  l1.add_book(b2);

  std::cout << '\n';
  l1.books();

  // Test creation of patron
  Patron p1 { "jasonarmstrong" };
  Patron p2 { "olgakalinksya" };
  Patron p3 { "sevenofnine" };
  Patron p4 { "cuahtemocblanco" };

  // Check created patron attributes
  std::cout << '\n';
  std::cout << p1.user_name() << " " << p1.id() << '\n';
  std::cout << p2.user_name() << " " << p2.id() << '\n';
  std::cout << p3.user_name() << " " << p3.id() << '\n';

  // Test adding patrons to library
  l1.add_patron(p1);
  l1.add_patron(p2);
  l1.add_patron(p3);

  // List all patrons
  std::cout << '\n';
  l1.patrons();


  // Test checkout with valid user
  l1.checkout_book(p1, b1); // jason..., the hobbit
  std::cout << '\n';
  std::cout << b1 << '\n';

  // Test checkout with non-existent book
  // std::cout << '\n';
  // l1.checkout_book(p2, b3); // jason..., the hobbit
  // std::cout << '\n';
  // std::cout << b3;

  // Test checkout with non-existent patron
  // std::cout << '\n';
  // l1.checkout_book(p4, b2); // jason..., the hobbit
  // std::cout << '\n';
  // std::cout << b2;

  // Test set library fees
  p1.add_fee(0.50);
  std::cout << '\n';
  std::cout << p1.fees() << '\n';
  std::cout << p1.has_fees() << '\n';

  // Test checkout with outstanding fees
  // l1.checkout_book(p1, b2); // jason..., Daughter of Fortune

  // Test list all Patrons owing fees
  std::cout << '\n';
  l1.outstanding_fees();

  return 0;
}
catch(std::exception& e)
{
  std::cerr << "Error: " << e.what() << '\n';
  return 1;
}
catch(...) {
  std::cerr << "Error: Unknown exception!\n";
  return 2;
}
