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

int main() try {
  Book b1 { "978-0618968636", "The Hobbit", "J. R. R. Tolkien", "January 1, 1973", Genre::fiction };
  std::cout << b1;

  std::cout << '\n';

  Book b2 { "978-0006552314", "Daughter of Fortune", "Isabel Allende", "April 1, 2008", Genre::biography };
  std::cout << b2;

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

  std::cout << '\n';
  std::cout << p1.user_name() << " " << p1.library_card_number() << '\n';
  std::cout << p2.user_name() << " " << p2.library_card_number() << '\n';

  return 0;
}
catch(Invalid) {
  std::cerr << "Error: ISBN should be in the form 978-n, where n is a 10-digit number.\n";
  return 1;
}
catch(...) {
  std::cerr << "Error: Unknown exception!\n";
  return 2;
}
