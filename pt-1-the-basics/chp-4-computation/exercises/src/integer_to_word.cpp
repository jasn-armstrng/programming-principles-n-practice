// This program,
// 1. Converts integer input to their spelled word equivalent e.g.
//  In: 7 Out: seven
// 2. Converts a spelled word integer to integer
//  In: seven Out: 7

#include <iostream>
#include <vector>
int main()
{
  std::vector<std::string> integer_spelling
    = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  std::string num;

  std::cout << "+------------------+\n";
  std::cout << "| Integer <-> Word |\n";
  std::cout << "+------------------+\n\n";

  std::cout << "Hello User!\n";
  std::cout << "\nHow to use this program:";
  std::cout << "\n------------------------";
  std::cout << "\n- At Input: below enter for e.g. 7 or seven";
  std::cout << "\n- To exit enter the | symbol.\n";

  std::cout << "\nInput: ";
  while(std::cin >> num)
  {

  }
  std::cout << "\nThanks for using Integer to Word :)\n";
  return 0;
}

// integer_to_word.cpp:22:24:
// warning: comparison of integers of different signs: 'int'
// and 'std::vector<std::string>::size_type' (aka 'unsigned long') [-Wsign-compare]

//     if (num < 0 || num >= integer_spelling.size())
