// A simple program to exercise operators

#include <iostream>
#include <math.h> // to access sqrt() function
int main()
{
  std::cout << "Please enter a integer value: ";
  int n;
  std::cin >> n;
  std::cout << "  n == " << n
            << "\nn+1 == " << n+1
            << "\n3*n == " << n*3
            << "\n2*n == " << n*2
            << "\nn^2 == " << n*n
            << "\nn/2 == " << n/2
            << "\nn%2 == " << n%2 // No modulo operation for double (floating-point) values
            << "\n √n == " << sqrt(n)
            << '\n';
}
