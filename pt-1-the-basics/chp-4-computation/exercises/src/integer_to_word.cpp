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
  std::cout << "\nHow to use this program:";
  std::cout << "\n------------------------";
  std::cout << "\n- At Input: below enter an integer e.g. 7";
  std::cout << "\n- To exit enter the | symbol.\n";

  std::cout << "\nInput: ";
  while(std::cin >> num)
  {
    if (num < 0 || num >= int(integer_spelling.size())) // Reason for type conversion below
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
  std::cout << "\nThanks for using Integer to Word :)\n";
  return 0;
}

// integer_to_word.cpp:22:24:
// warning: comparison of integers of different signs: 'int'
// and 'std::vector<std::string>::size_type' (aka 'unsigned long') [-Wsign-compare]

//     if (num < 0 || num >= integer_spelling.size())
