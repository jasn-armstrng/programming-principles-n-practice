// Introducing a namespace: A language mechanism to organize classes, functions,
// data, and types into an identifiable and named part of a program without
// defining a type
#include <iostream>
#include <vector>

inline void error(const std::string& s) { throw std::runtime_error(s); }

void print(const std::vector<int> v) {
  // print the contents of a vector
  for(unsigned i = 0; i < v.size(); ++i) {
    if(i != 0) { std::cout << ", "; }
    std::cout << v[i];
  }
  std::cout << '\n';
}

namespace string_vector_stats {
  std::vector<int> string_sizes(const std::vector<std::string> v) {
    // compute and store size of strings in v
    // pre-conditions: vector v.size() > 0
    // post-conditions: returns a vector with string sizes
    if(v.size() == 0) { error("Input has no data!"); }
    // store sizes of strings in v
    std::vector<int> string_sizes;
    for(std::string s: v) {
      string_sizes.push_back(s.size());
    }
    return string_sizes;
  }

  // std::string smallest_string(const std::vector<std::string> v) {
  //   // find the smallest string in input vector v
  //   // pre-conditions: input vector v.size() > 0
  //   // post-conditions: return smallest string in input vector v
  //   std::vector<int> sizes = string_vector_stats::string_sizes(v);

  //   int smallest = sizes[0];
  //   for(int i: sizes) {
  //     if(i < smallest) { smallest = i; }
  //   }
  //   return v[smallest];
  // }
};
