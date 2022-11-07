// This program performs as a very simple calculator. It takes two real numbers
// and an operator as input e.g. 35.6 24.1 + and returns the result of the
// operation.

#include <iostream>

void calculate(double x, double y, char oper)
{
  switch(oper)
  {
    case('+'):
      std::cout << "The sum of " << x << " and " << y << " is " << x+y << '\n';
      break;
    case('-'):
      std::cout << "The difference between " << x << " and " << y << " is " << x-y << '\n';;
      break;
    case('/'):
      std::cout << "The division of " << x << " by " << y << " is " << x/y << '\n';;
      break;
    case('*'):
      std::cout << "The product of " << x << " and " << y << " is " << x*y << '\n';
      break;
    default:
      std::cout << "I'm sorry, I can perform the operation " << oper << '\n';
  }
}

int main()
{
  double num1, num2;
  char operation;

  std::cout << "+-------------------+\n";
  std::cout << "| Simple Calculator |\n";
  std::cout << "+-------------------+\n\n";

  std::cout << "Hello User!\n";
  std::cout << "\nUsage:\n- Calculate: 35.6 24.1 + \n- To exit enter |\n";
  std::cout << "\nCalculate: ";

  while (std::cin >> num1 >> num2 >> operation)
  {
    calculate(num1, num2, operation);
    std::cout << "\nCalculate: ";
  }
  std::cout << "\nThanks for using Simple Calculator :)\n";
  return 0;
}
