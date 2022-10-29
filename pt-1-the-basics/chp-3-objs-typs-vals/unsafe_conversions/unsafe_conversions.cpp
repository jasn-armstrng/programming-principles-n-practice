// This programs is used to demonstrate results of unsafe type conversions

#include <iostream>
int main()
{
  double d = 0;
  while (std::cin >> d) // repeat statements below as long as we key in numbers
  {
    int i = d;  // try to squeeze a double into an int
    char c = i; // try to squeeze an int into a char
    int i2 = c; // get the integer value of the char
    std::cout << "d==" << d  // the original double
              << " i==" << i  // converted to int
              << " i2==" << i2 // int value of the char
              << " char(" << c << ")\n"; // the char
  }
}

// test values (1):
// 2 3 127 1001 56 89 128 56.9 56.2

// test results:
// d==2 i==2 i2==2 char()
// d==3 i==3 i2==3 char()
// d==127 i==127 i2==127 char()
// d==1001 i==1001 i2==-23 char(�)
// d==56 i==56 i2==56 char(8)
// d==89 i==89 i2==89 char(Y)
// d==128 i==128 i2==-128 char(�)
// d==56.9 i==56 i2==56 char(8)
// d==56.2 i==56 i2==56 char(8)

// test values (2):
// 94 44 32 9 43 126

// test results: See Ascii table to reference the char output.
// d==94 i==94 i2==94 char(^)
// d==44 i==44 i2==44 char(,)
// d==32 i==32 i2==32 char( )
// d==9 i==9 i2==9 char(   )
// d==43 i==43 i2==43 char(+)
// d==126 i==126 i2==126 char(~)
