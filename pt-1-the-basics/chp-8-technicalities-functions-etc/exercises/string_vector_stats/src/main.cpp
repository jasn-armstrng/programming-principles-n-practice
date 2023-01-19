/*
Given a vector of strings, this program conputes and returns,
1. The number of cheracters in each string
2. The longest and shortest strings
3. The lexicographical shortest and longest string
*/
#include <iostream>
#include <vector>

inline void error(const std::string& s);
std::vector<int> get_string_sizes(std::vector<std::string> v);
void print(const std::vector<int> v);

int main() try {
  std::vector<std::string> excerpt = { "in", "the", "beginning", "god", "created", "heaven", "and", "earth" };
  print(get_string_sizes(excerpt));
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

std::vector<int> get_string_sizes(std::vector<std::string> v) {
  // compute and store size of strings in v
  // pre-conditions: vector v.size() > 0
  // post-conditions: return vector of v's string sizes

  // check pre-condition
  if(v.size() == 0) { error("Input has no data!"); }

  // store sizes of strings in v
  std::vector<int> string_sizes;
  for(std::string s: v) {
    string_sizes.push_back(s.size());
  }

  return string_sizes;
}

void print(const std::vector<int> v) {
  // print the contents of a vector
  for(unsigned i = 0; i < v.size(); ++i) {
    if(i != 0) {
      std::cout << ", ";
    }
    std::cout << v[i];
  }
  std::cout << '\n';
}
