// This program returns the integer value for the string literal version of that
// number. E.g. input: "Two" output: 2,  input: "2" output: 2

#include <iostream>
int main()
{
  std::string val;
  std::cout << "+-------------------+\n";
  std::cout << "| String to Integer |\n";
  std::cout << "+-------------------+\n\n";
  std::cout << "Please enter a number as text or integer: ";
  std::cin >> val;
}
