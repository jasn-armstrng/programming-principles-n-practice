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
  Book b1 { "978-0618968636", "The Hobbit", "J. R. R. Tolkien", "January 1, 1973", Genre::fiction };
  std::cout << b1;

  std::cout << '\n';

  Book b2 { "978-0006552314", "Daughter of Fortune", "Isabel Allende", "April 1, 2008", Genre::biography };
  std::cout << b2;

  std::cout << '\n';

  Book b3 { "978-0142437230", "Don Quixote", "Miguel Cervantes", "February 25, 2003", Genre::fiction };
  std::cout << b3;

  std::cout << '\n';

  std::cout << (b1 == b2) << '\n';
  std::cout << (b1 != b2) << '\n';


  Library l1;
  l1.add_book(b1);
  l1.add_book(b2);

  std::cout << '\n';
  l1.list_books();

  Patron p1 { "jasonarmstrong" };
  Patron p2 { "olgakalinksya" };
  Patron p3 { "sevenofnine" };
  Patron p4 { "cuahtemocblanco" };

  std::cout << '\n';
  std::cout << p1.user_name() << " " << p1.library_card_number() << '\n';
  std::cout << p2.user_name() << " " << p2.library_card_number() << '\n';
  std::cout << p3.user_name() << " " << p3.library_card_number() << '\n';

  l1.add_patron(p1);
  l1.add_patron(p2);
  l1.add_patron(p3);

  std::cout << '\n';
  for(Patron p: l1.patrons()) { std::cout << p.library_card_number() << '\n'; }

  l1.checkout_book(p1, b1); // jason..., the hobbit
  std::cout << '\n';
  std::cout << b1;

  // Test checkout with non-existent book
  // std::cout << '\n';
  // l1.checkout_book(p2, b3); // jason..., the hobbit
  // std::cout << '\n';
  // std::cout << b3;

  // Test checkout with non-existent patron
  std::cout << '\n';
  l1.checkout_book(p4, b2); // jason..., the hobbit
  std::cout << '\n';
  std::cout << b2;

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
