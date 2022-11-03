/*
  This program converts currency values to USD.

  How it works:
  1. Input: Prompt user to enter a currency (symbol) immediately followed by an amount,
     Ex. 2€, 20£, 8¥
  2. Output: "2€ = $1.70"
*/

#include <iostream>
#include <cwchar>
int main()
{
  double amount;
  int currency;
  std::cout << "+--------------------+\n";
  std::cout << "| Currency Converter |\n";
  std::cout << "+--------------------+\n\n";
  // Prompt for user values. Read in user input.
  std::cout << "Please enter currency from the numbered options below\n\n";
  std::cout << "\t1: €\t2: £\t3: ¥\t4: ₩\t5: kr\n\n";
  std::cout << "Currency: ";
  std::cin >> currency;
  std::cout << "  Amount: ";
  std::cin >> amount;

  // Cases for conversion
  return 0;

}
