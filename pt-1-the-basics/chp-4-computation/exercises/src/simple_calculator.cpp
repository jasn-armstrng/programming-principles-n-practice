// This program performs as a very simple calculator. It takes two real numbers
// and an operator as input e.g. 35.6 24.1 + and returns the result of the
// operation.

#include <iostream>

double calculate(double x, double y, char oper)
{
  switch(oper)
  {
    case('+'):
      return x+y;
      break;
    case('-'):
      return x-y;
      break;
    case('/'):
      return x/y;
      break;
    case('*'):
      return x*y;
      break;
    default:
      return 0;
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
    std::cout << "Result: " << calculate(num1, num2, operation) << '\n';
    std::cout << "\nCalculate: ";
  }
  return 0;
}
