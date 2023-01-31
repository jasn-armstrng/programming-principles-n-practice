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

std::ostream& operator<<(std::ostream& os, Book& book) {
  // overload the << operator to print a Book object's state
  return os << "Name: " << book.name << '\n'
            << "Author: " << book.author << '\n'
            << "Genre: " << book.genre << '\n';
}

int main() {
  Book b1 { "Far from the madding crowd", "Thomas Hardy", "English classic" };
  std::cout << b1;
  return 0;
}
