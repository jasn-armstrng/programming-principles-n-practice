/**
 * @file main.cpp
 * @author Jason Armstrong
 * @brief
 * @version 0.1
 * @date 2023-02-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include "../headers/library.h"

int main() try
{
  Book the_hobbit { "978-0618968636&", "The Hobbit", "J. R. R. Tolkien", "January 1, 1973" };
  // std::string isbn { "978-0618968636" };
  // std::cout << is_isbn(isbn) << '\n';
  return 0;
}
catch(Invalid)
{
  std::cerr << "Error: ISBN should be in the form 978-XXXXXXXXXX, where X is an integer.\n";
  return 1;
}
catch(...)
{
  std::cerr << "Error: Unknown exception!\n";
  return 2;
}
