// This program used to practice operator overloading
#include <iostream>

struct Book {
  std::string name;
  std::string author;
  std::string genre;

  // Constructor
  Book(std::string n, std::string a, std::string g) {
    name = n;
    author = a;
    genre = g;
  }
}; // namespace Book

int main() {
  Book b1 { "Far from the madding crowd", "Thomas Hardy", "English classic" };
  return 0;
}
