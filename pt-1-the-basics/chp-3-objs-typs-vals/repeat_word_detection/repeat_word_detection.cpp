// This program detects adjacent repeated words in a stream entered by user.

#include <iostream>
int main()
{
  std::cout << "Note: To end this program press CTRL+D.\n";
  std::cout << "Please enter a sentence >= 2 words: ";
  std::string previous = " ";
  std::string current;
  while (std::cin >> current)
  {
    if (previous == current)
      std::cout << "repeated word: " << current << "\n";
    previous = current;
  }
}
