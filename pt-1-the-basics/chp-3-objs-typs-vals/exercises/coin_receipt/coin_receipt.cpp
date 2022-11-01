// This program provides the user a list and value of their coins.

#include <iostream>
int main()
{
  std::string pennies, nickels, dimes, quarters, half_dollars, silver_dollars;
  std::cout << "+-----------------------------------------+\n";
  std::cout << "| Coin Receipt: List and total your coins |\n";
  std::cout << "+-----------------------------------------+\n\n";
  std::cout << "How many pennies do you have?: "; std::cin >> pennies;
  std::cout << "                     nickels?: "; std::cin >> nickels;
  std::cout << "                       dimes?: "; std::cin >> dimes;
  std::cout << "                    quarters?: "; std::cin >> quarters;
  std::cout << "                half-dollars?: "; std::cin >> half_dollars;
  std::cout << "              silver-dollars?: "; std::cin >> silver_dollars;

  return 0;
}
