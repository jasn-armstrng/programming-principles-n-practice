// This program performs as a very simple calculator. It takes two real numbers
// and an operator as input e.g. 35.6 24.1 + and returns the result of the
// operation.

#include <iostream>
int main()
{
  double num1, num2;
  char operation;

  std::cout << "+-------------------+\n";
  std::cout << "| Simple Calculator |\n";
  std::cout << "+-------------------+\n\n";

  std::cout << "Hello User!\n";
  std::cout << "\nPlease enter your calculation to be performed e.g. 35.6 24.1 + =\n";
  std::cout << "Calculate: ";

  while (std::cin >> num1 >> num2 >> operation)
  {
    std::cout << num1 << ' ' << num2 << ' ' << operation << '\n';
  }
  return 0;
}
