// This program performs basic arithmetic calculations on single digit integers.
// The user can input statements in the following forms,
//    6 5 +
//    six five +
// and the output expected,
//    The sum of 6 and 5 is 11

#include <iostream>
#include <vector>

int word_to_int(std::string word)
{
  std::vector<std::string> ints_as_words
    = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

  for(int i = 0; i < int(ints_as_words.size()); ++i)
    {
      if(word == ints_as_words[i])
      {
        return i;
      }
      else if (word == std::to_string(i))
      {
        return i;
      }
    }
  return 0;
}

void calculate(int x, int y, char oper)
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
      std::cout << "I'm sorry, I can't perform the operation " << oper << '\n';
  }
}

int main()
{

  std::string int1, int2;
  char operation;

  std::cout << "+----------------------+\n";
  std::cout << "| Simple Calculator v2 |\n";
  std::cout << "+----------------------+\n\n";

  std::cout << "Hello User\n";
  std::cout << "\nHow to use this program:\n";
  std::cout << "- Input examples,\n";
  std::cout << "  6 7 +\n  7 8 *\n  five 4 -\n  nine three /\n";
  std::cout << "- Use +ve single digits only\n";
  std::cout << "- To exit program enter ctrl-D\n";

  std::cout << "\nInput: ";
  while (std::cin >> int1 >> int2 >> operation)
  {
    calculate(word_to_int(int1), word_to_int(int2), operation);
    std::cout << "\nInput: ";
  }
  return 0;
}
