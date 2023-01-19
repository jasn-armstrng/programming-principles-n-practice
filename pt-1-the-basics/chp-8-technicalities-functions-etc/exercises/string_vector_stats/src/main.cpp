/*
Given a vector of strings, this program conputes and returns,
1. The number of cheracters in each string
2. The longest and shortest strings
3. The lexicographical shortest and longest string
*/
#include <iostream>
#include <vector>
#include "../headers/string_vector_facilities.h"

int main() try {
  std::vector<std::string> excerpt = { "in", "the", "beginning", "god", "created", "heaven", "and", "earth" };
  std::cout << "--- Input ---\n";
  print_string_vec("Strings: ", excerpt);
  std::cout <<  "\n--- Stats ---\n";
  print_int_vec("String sizes: ", string_vector_stats::string_sizes(excerpt));
  std::cout << "Smallest string: " << string_vector_stats::smallest_string(excerpt) << '\n';
  std::cout << "Largest string: " << string_vector_stats::largest_string(excerpt) << '\n';
  std::cout << "Lexicographically smallest: " << string_vector_stats::lexico_smallest(excerpt) << '\n';
  std::cout << "Lexicographically largest: " << string_vector_stats::lexico_largest(excerpt) << '\n';
  return 0;
}
catch(std::exception& e) {
  std::cerr << "Error: " << e.what() << '\n';
  return 1;
}
catch(...) {
  std::cerr << "Error: Unknown exception\n";
  return 2;
}
