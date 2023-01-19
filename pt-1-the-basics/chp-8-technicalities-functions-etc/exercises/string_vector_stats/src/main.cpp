/*
Given a vector of strings, this program conputes and returns,
1. The number of cheracters in each string
2. The longest and shortest strings
3. The lexicographical shortest and longest string
*/
#include <iostream>
#include <vector>

inline void error(const std::string& s);
void compute_stats(std::vector<std::string> v);

int main() try {
  std::vector<std::string> excerpt = { "in", "the", "beginning", "God", "created", "the", "heavens", "and", "the", "Earth" };
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

inline void error(const std::string& s) { throw std::runtime_error(s); }

void compute_stats(std::vector<std::string>& v) {
  //
  // pre-conditions: vector v.size() > 0
  // post-conditions:

  // check pre-condition
  if(v.size() == 0) { error("Input has no data!"); }
}
