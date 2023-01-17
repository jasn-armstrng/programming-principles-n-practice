#include <iostream>
#include <vector>
#include "../headers/reverse_vector.h"

std::vector<int> data = {1, 3, 5, 7, 9};

std::vector<int> reverse_by_value(const std::vector<int> v) {
  // reverse contents of a vector
  // pre-conditions: vector v is not empty
  // post-conditions: returns copy of vector v reversed
  std::vector<int> v_reversed;
  for (unsigned i = v.size(); i > 0; --i) {
    v_reversed.push_back(v[i-1]);
  }
  return v_reversed;
}

std::vector<int> reverse_by_reference(std::vector<int>& v) {
  // reverse contents of a vector
  // pre-conditions: vector v is not empty
  // post-conditions: returns v reversed
  for (unsigned i = v.size(), j = 0; i > v.size()/2; --i, ++j) {
    // swap(last, first), swap(2nd-to-last, 2nd), ... till the middle
    std::swap(v[i-1], v[j]);
  }
  return v;
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
