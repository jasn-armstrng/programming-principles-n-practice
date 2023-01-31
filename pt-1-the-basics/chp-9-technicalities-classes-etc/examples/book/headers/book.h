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

std::ostream& operator<<(std::ostream& os, Book& book) {
  // overload the << operator to print a Book object's state
  return os << "Name: " << book.name << '\n'
            << "Author: " << book.author << '\n'
            << "Genre: " << book.genre << '\n';
}
