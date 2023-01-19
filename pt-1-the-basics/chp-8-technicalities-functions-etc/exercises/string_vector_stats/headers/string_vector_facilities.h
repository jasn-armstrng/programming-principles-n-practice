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
    // post-conditions: returns vector
    if(v.size() == 0) { error("Input has no data!"); }

    std::vector<int> string_sizes;
    for(std::string s: v) {
      string_sizes.push_back(s.size());
    }
    return string_sizes;
  }

  std::string smallest_string(const std::vector<std::string> v) {
    // find the smallest string in input vector v
    // pre-conditions: input vector v.size() > 0
    // post-conditions: return string
    if(v.size() == 0) { error("Input has no data!"); }

    const std::vector<int>& sizes = string_vector_stats::string_sizes(v);

    int smallest { sizes[0] };
    int smallest_index { 0 };
    for(unsigned i = 0; i < sizes.size(); ++i) {
      if(sizes[i] < smallest) {
        smallest = sizes[i];
        smallest_index = i;
      }
    }
    return v[smallest_index];
  }

  std::string largest_string(const std::vector<std::string> v) {
    // find the largest string in input vector v
    // pre-conditions: input vector v.size() > 0
    // post-conditions: return string
    if(v.size() == 0) { error("Input has no data!"); }

    const std::vector<int>& sizes = string_vector_stats::string_sizes(v);

    int largest { sizes[0] };
    int largest_index { 0 };
    for(unsigned i = 0; i < sizes.size(); ++i) {
      if(sizes[i] > largest) {
        largest = sizes[i];
        largest_index = i;
      }
    }
    return v[largest_index];
  }

  std::string lexico_smallest(const std::vector<std::string> v) {
    // find the lexicographically smallest string in input vector v
    // pre-conditions: input vector v.size() > 0
    // post-conditions: return string
    if(v.size() == 0) { error("Input has no data!"); }

    std::vector<std::string> v_sorted = v;
    auto lambda = [](std::string a, std::string b) { return a < b; };
    std::sort(v_sorted.begin(), v_sorted.end(), lambda);
    return v_sorted[0];
  }

  std::string lexico_largest(const std::vector<std::string> v) {
    // find the lexicographically largest string in input vector v
    // pre-conditions: input vector v.size() > 0
    // post-conditions: return string
    if(v.size() == 0) { error("Input has no data!"); }

    std::vector<std::string> v_sorted = v;
    auto lambda = [](std::string a, std::string b) { return a > b; };
    std::sort(v_sorted.begin(), v_sorted.end(), lambda);
    return v_sorted[0];
  }
};
