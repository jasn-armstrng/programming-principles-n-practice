// This program takes an input n and finds the first n primes

#include <iostream>
int main()
{
  int n; // number of primes

  std::cout << "+----------------+\n";
  std::cout << "| First N Primes |\n";
  std::cout << "+----------------+\n\n";

  std::cout << "\nThis program takes an input N and finds the first N primes.";
  std::cout << "\nNote: Limited to first 1000 primes.";
  std::cout << "\n-----------------------------------";
  std::cout << "\n\nN: ";
  std::cin >> n;

  return 0;
}
