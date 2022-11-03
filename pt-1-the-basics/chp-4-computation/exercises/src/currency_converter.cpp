/*
  This program converts currency values to USD.

  How it works:
  1. Input: Prompt user to enter a currency (symbol) immediately followed by an amount,
     Ex. 2€, 20£, 8¥
  2. Output: "2€ = $1.70"
*/

#include <iostream>
int main()
{
  double amount;
  int currency;
  std::cout << "\t      +--------------------+\n";
  std::cout << "\t      | Currency Converter |\n";
  std::cout << "\t      +--------------------+\n\n";
  // Prompt for user values. Read in user input.
  std::cout << "Please enter currency from the numbered options below:\n\n";
  std::cout << "\t1: €\t2: £\t3: ¥\t4: ₩\t5: dkk\n\n";
  std::cout << "Option: ";
  std::cin >> currency;
  std::cout << "Amount: ";
  std::cin >> amount;

  // Cases for conversion
  switch (currency)
  {
    case(1):
      std::cout << "\nResult: " << "€" << amount << " = $" << amount * 0.98 << '\n'; break;
    case(2):
      std::cout << "\nResult: " << "£" << amount << " = $" << amount * 1.12 << '\n'; break;
    case(3):
      std::cout << "\nResult: " << "¥" << amount << " = $" << amount * 0.067 << '\n'; break;
    case(4):
      std::cout << "\nResult: " << "₩" << amount << " = $" << amount * 0.00070 << '\n'; break;
    case(5):
      std::cout << "\nResult: " << "dkk" << amount << " = $" << amount * 0.13 << '\n'; break;
    default:
      std::cout << "\nSorry, I am unable to convert for that currency.\n"; break;
  }

  return 0;
}
