// This program returns the integer value for the string literal version of that
// number. E.g. input: "Two" output: 2,  input: "2" output: 2

#include <iostream>
int main()
{
  std::string in;
  int out = -1;
  std::cout << "+-------------------+\n";
  std::cout << "| String to Integer |\n";
  std::cout << "+-------------------+\n\n";
  std::cout << "Please enter a number as text or integer: ";
  std::cin >> in;

  if (in == "zero" || in == "0")
    out = 0;
  else if (in == "one" || in == "1")
    out = 1;
  else if (in == "two" || in == "2")
    out = 2;
  else if (in == "three" || in == "3")
    out = 3;
  else if (in == "four" || in == "4")
    out = 4;

  if (out != -1)
    std::cout << "\nResult: The input " << in << " corresponds to the number " << out << ".\n\n";
  else
    std::cout << "\nResult: Not a number I know.\n\n";
}
