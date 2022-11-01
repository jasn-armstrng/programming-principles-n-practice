// This program provides the user a list and value of their coins.

#include <iostream>
int main()
{
  // Variable declaration
  double pennies, nickels, dimes, quarters, half_dollars, silver_dollars;
  double total_in_cents, total_in_dollars;
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
  // Totals
  total_in_cents =  pennies
                  + (nickels * 5)
                  + (dimes * 10)
                  + (quarters * 25)
                  + (half_dollars * 50)
                  + (silver_dollars * 100);
  total_in_dollars = total_in_cents/100;
  // Output
  std::cout << "\nYour receipt:\n";
  std::cout << "You have " << pennies;
    (pennies > 1) ? std::cout << " pennies.\n" : std::cout << " penny.\n";
  std::cout << "You have " << nickels ;
    (nickels > 1) ? std::cout << " nickels.\n" : std::cout << " nickel.\n";
  std::cout << "You have " << dimes ;
    (dimes > 1) ? std::cout << " dimes.\n" : std::cout << " dime.\n";
  std::cout << "You have " << quarters ;
    (quarters > 1) ? std::cout << " quarters.\n" : std::cout << " quarter.\n";
  std::cout << "You have " << half_dollars ;
    (half_dollars > 1) ? std::cout << " half dollars.\n" : std::cout << " half dollar.\n";
  std::cout << "You have " << silver_dollars ;
    (silver_dollars > 1) ? std::cout << " silver dollars.\n" : std::cout << " silver dollar.\n";

  std::cout << "The value of all your coins is $" << total_in_dollars << " dollars.\n";
  return 0;
}
