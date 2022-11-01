// This program provides the user a list and value of their coins.

#include <iostream>
int main()
{
  // Variable declaration
  int pennies, nickels, dimes, quarters, half_dollars, silver_dollars, total_of_coins;
  // Heading
  std::cout << "+-----------------------------------------+\n";
  std::cout << "| Coin Receipt: List and total your coins |\n";
  std::cout << "+-----------------------------------------+\n\n";
  // Prompt
  std::cout << "How many pennies do you have?: "; std::cin >> pennies;
  std::cout << "How many nickels do you have?: "; std::cin >> nickels;
  std::cout << "How many dimes do you have?: "; std::cin >> dimes;
  std::cout << "How many quarters do you have?: "; std::cin >> quarters;
  std::cout << "How many half dollars do you have?: "; std::cin >> half_dollars;
  std::cout << "How many silver dollars do you have?: "; std::cin >> silver_dollars;
  total_of_coins = pennies + nickels + dimes + quarters + half_dollars + silver_dollars;
  // Output
  std::cout << "\nYour receipt:\n";
  std::cout << "You have " << pennies << " pennies.\n";
  std::cout << "You have " << nickels << " nickels.\n";
  std::cout << "You have " << dimes << " dimes.\n";
  std::cout << "You have " << quarters << " quarters.\n";
  std::cout << "You have " << half_dollars << " half dollars.\n";
  std::cout << "You have " << silver_dollars << " silver dollars.\n";
  std::cout << "The value of all your coins is " << total_of_coins << " cents.\n";
  return 0;
}
