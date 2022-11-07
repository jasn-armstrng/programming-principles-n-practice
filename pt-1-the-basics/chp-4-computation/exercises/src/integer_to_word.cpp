// This program converts integer input to their spelled word equivalent e.g.
// In: 7 Out: seven

#include <iostream>
#include <vector>
int main()
{
  std::vector<std::string> integer_spelling
    = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  int num;

  std::cout << "+-----------------+\n";
  std::cout << "| Integer to Word |\n";
  std::cout << "+-----------------+\n\n";

  std::cout << "Hello User!\n";
  std::cout << "\nProgram usage:\n- Input: 7 \n  Output: seven\n- To exit enter |\n";

  std::cout << "\nInput: ";
  while(std::cin >> num)
  {
    if (num < 0 || num >= int(integer_spelling.size()))
    {
      std::cout << "I'm sorry I don't know that one.\n";
      std::cout << "\nInput: ";
    }
    else
    {
      std::cout << "Output: " << integer_spelling[num] << '\n';
      std::cout << "\nInput: ";
    }
  }
  return 0;
}
