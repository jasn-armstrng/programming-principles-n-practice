// This program takes a lisp like operation syntax string, performs the operation
// and return result. E.g. input: "+ 100 3" should output: 103

#include <iostream>
int main()
{
  char operation;
  double operand1, operand2, result;
  std::cout << "+------------------+\n";
  std::cout << "| Eval and Operate |\n";
  std::cout << "+------------------+\n\n";
  std::cout << "Please enter an operation e.g. + 100 33.3: ";
  std::cin >> operation >> operand1 >> operand2;

  if (operation == '+')
    result = operand1 + operand2;

  if (operation == '-')
    result = operand1 - operand2;

  if (operation == '*')
    result = operand1 * operand2;

  if (operation == '/')
    result = operand1 / operand2;

  std::cout << "\nResult: " << operand1 << operation << operand2 << " = " << result << '\n';
}
