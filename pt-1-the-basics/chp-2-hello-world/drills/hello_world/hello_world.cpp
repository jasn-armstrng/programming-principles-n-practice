// This program prints "Hello, World!" to the console
#include <iostream>
inline void keep_window_open(){ char ch; std::cin>>ch; }
int main(){ // C++ programs start by executing the function main
  std::cout << "Hello, World!\n"; // Output "Hello, World!"
  keep_window_open();             // Wait for character to be entered
  return 0;
}
