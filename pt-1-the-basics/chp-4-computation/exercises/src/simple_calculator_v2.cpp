// This program performs basic arithmetic calculations on single digit integers.
// The user can input statements in the following forms,
//    6 5 +
//    six five +
// and the output expected,
//    The sum of 6 and 5 is 11

#include <iostream>
#include <vector>
int main()
{
  std::vector<std::string> ints_as_words
    = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  std::string int1, int2, operation;

  std::cout << "+----------------------+\n";
  std::cout << "| Simple Calculator v2 |\n";
  std::cout << "+----------------------+\n\n";

  std::cout << "Hello User\n";
  std::cout << "\nHow to use this program:\n";
  std::cout << "- Input examples,\n";
  std::cout << "  6 7 +, 7 8 *, five four -, nine three /\n";
  std::cout << "- To exit program enter ctrl-D\n";

  return 0;
}
