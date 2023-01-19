// Introducing a namespace: A language mechanism to organize classes, functions,
// data, and types into an identifiable and named part of a program without
// defining a type
#include <iostream>
#include <vector>

inline void error(const std::string& s) { throw std::runtime_error(s); }

void print_int_vec(const std::string label, const std::vector<int> v) {
  // print the contents of vector
  // pre-conditions: vector is type int
  std::cout << label;
  for(unsigned i {0}; i < v.size(); ++i) {
    if(i != 0) { std::cout << ", "; }
    std::cout << v[i];
  }
  std::cout << '\n';
}

void print_string_vec(const std::string label, const std::vector<std::string> v) {
  // print the contents of a string vector
  // pre-conditions: vector is type string
  std::cout << label;
  for(unsigned i {0}; i < v.size(); ++i) {
    if(i != 0) { std::cout << ", "; }
    std::cout << v[i];
  }
  std::cout << '\n';
}

namespace string_vector_stats {
  std::vector<int> string_sizes(const std::vector<std::string> v) {
    // compute and store size of strings in v
    // pre-conditions: vector v.size() > 0
    // post-conditions: returns vector
    std::vector<int> string_sizes;
    for(auto s: v) {
      string_sizes.push_back(s.size());
    }
    return string_sizes;
  }

  std::string smallest_string(std::vector<std::string> v) {
    // find the smallest string in input vector v
    // pre-conditions: input vector v.size() > 0
    // post-conditions: return string
    unsigned min {100};
    std::string smallest;
    for(auto s: v) {
      if (s.size() < min) {
        min = s.size();
        smallest = s;
      }
    }
    return smallest;
  }

  std::string largest_string(const std::vector<std::string> v) {
    // find the largest string in input vector v
    // pre-conditions: input vector v.size() > 0
    // post-conditions: return string
    unsigned max {0};
    std::string largest;
    for(auto s: v) {
      if (s.size() > max) {
        max = s.size();
        largest = s;
      }
    }
    return largest;
  }

  std::string lexico_smallest(const std::vector<std::string> v) {
    // find the lexicographically smallest string in input vector v
    // pre-conditions: input vector v.size() > 0
    // post-conditions: return string
    std::vector<std::string> v_sorted {v};
    auto lambda {[](std::string a, std::string b) { return a < b; }};
    std::sort(v_sorted.begin(), v_sorted.end(), lambda);
    return v_sorted[0];
  }

  std::string lexico_largest(const std::vector<std::string> v) {
    // find the lexicographically largest string in input vector v
    // pre-conditions: input vector v.size() > 0
    // post-conditions: return string
    std::vector<std::string> v_sorted {v};
    auto lambda {[](std::string a, std::string b) { return a > b; }};
    std::sort(v_sorted.begin(), v_sorted.end(), lambda);
    return v_sorted[0];
  }
};

void stats(const std::vector<std::string> v) {
  // print string vector stats
  // pre-conditions: input vector v.size() > 0
  if(v.size() == 0) { error("Input has no data!"); }

  std::cout << "--- Input ---\n";
  print_string_vec("Strings: ", v);
  std::cout <<  "\n--- Stats ---\n";
  print_int_vec("String sizes: ", string_vector_stats::string_sizes(v));
  std::cout << "Smallest string: " << string_vector_stats::smallest_string(v) << '\n';
  std::cout << "Largest string: " << string_vector_stats::largest_string(v) << '\n';
  std::cout << "Lexicographically smallest: " << string_vector_stats::lexico_smallest(v) << '\n';
  std::cout << "Lexicographically largest: " << string_vector_stats::lexico_largest(v) << '\n';
  std::cout << '\n';
}
