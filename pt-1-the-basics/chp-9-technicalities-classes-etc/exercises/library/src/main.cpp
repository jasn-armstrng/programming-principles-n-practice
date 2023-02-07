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
  Book the_hobbit { "978-0618968636", "The Hobbit", "J. R. R. Tolkien", "January 1, 1973", Genre::fiction };
  std::cout << the_hobbit;

  std::cout << '\n';

  Book daughter_of_fortune { "978-0006552314", "Daughter of Fortune", "Isabel Allende", "April 1, 2008", Genre::biography };
  std::cout << daughter_of_fortune;

  std::cout << '\n';

  std::cout << (the_hobbit == daughter_of_fortune) << '\n';
  std::cout << (the_hobbit != daughter_of_fortune) << '\n';
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
