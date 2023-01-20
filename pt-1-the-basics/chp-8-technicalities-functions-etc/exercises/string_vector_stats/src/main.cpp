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
  std::vector<std::string> l1 { "in", "the", "beginning", "god", "created", "heaven", "and", "earth" };
  std::vector<std::string> l2 { "Quentin", "Jason", "Zebedee", "woke", "urgently", "one", "day", "keenly",
                                "thinking", "he", "could", "go", "by", "Lindsay's", "Forester's", "Yard",
                                "Inn", "near", "Vasey", "Street", "and", "play", "refined", "elegant",
                                "xylophone", "music" };
                                // ' = 2 characters, strings starting with caps are lexicographically first
  std::vector<std::string> l3 {}; // Error: Input has no data!
  // ---- Get stats ----
  string_vector_stats::stats(l1);
  string_vector_stats::stats(l2);
  string_vector_stats::stats(l3);
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
