// This is the first attempt of the calculator program. Pg. 180. I'm writing to
// see how cin works with a character stream and a for loop.

#include <iostream>

inline void error(const std::string& s);

int main(){
  std::cout << "Please enter expression (we can handle +, -, * and /)\n";
  std::cout << "Add an x to end expression (e.g., 1+2*3x): ";

  int lval = 0;
  int rval;

  std::cin >> lval; // read leftmost character input - operand
  if (!std::cin) { error("No first operand"); };
  for (char op; std::cin >> op;) { // read operator,
    if (op != 'x') { std::cin >> rval; } // and right-hand operand repeatedly
    std::cout << "lval: " << lval << ", op: " << op << ", rval: " << rval << '\n'; // what rval, lval, op is on each iteration thru stream

    if (!std::cin) { error("No second operand"); }

    switch(op) {
      case '+':
        lval += rval;
        break;
      case '-':
        lval -= rval;
        break;
      case '*':
        lval *= rval;
        break;
      case '/':
        lval /= rval;
        break;
      default:
        std::cout << "Result: " << lval << '\n';
        return 0;
    }
  }
  error("Bad expression"); // when is this executed?

  return 0;
}

inline void error(const std::string& s) { throw std::runtime_error(s); }
