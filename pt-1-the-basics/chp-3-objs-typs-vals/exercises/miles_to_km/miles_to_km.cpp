// This program converts user entered miles to km

#include <iostream>
int main()
{
  double miles;
  std::cout << "Please enter a number of miles to convert to km: ";
  std::cin >> miles;
  std::cout << miles * 1.609;
}
