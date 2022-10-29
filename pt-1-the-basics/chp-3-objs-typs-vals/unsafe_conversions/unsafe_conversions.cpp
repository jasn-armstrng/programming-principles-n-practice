// This programs is used to demonstrate unsafe type conversions

#include <iostream>
int main()
{
  double d = 0;
  while (std::cin >> d) // repeat statement below as long as we enter numbers
  {
    int i = d;  // try to squeeze a double into an int
    char c = i; // try to squeeze an int into a char
    int i2 = c; // get the integer value of the char
    std::cout << " d==" << d  // the original double
              << " i==" << i  // converted to int
              << "i2==" << i2 // int value of the char
              << "char(" << c << ")\n"; // the char
  }
}
