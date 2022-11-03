// This program analyzes words from user input stream. Words
// found in blacklist are written to output as BLEEP.

#include <iostream>
#include <vector>
int main()
{
  std::vector<std::string> blacklist = {"fox", "lazy", "dog"};
  std::string censored = "";
  std::string current;
  std::cout << "+----------------+\n";
  std::cout << "| Bleep my words |\n";
  std::cout << "+----------------+\n\n";

  std::cout << "Enter your text to censor at > below.\n";
  std::cout << "When you are done press Enter then ctrl+D for results.\n";
  std::cout << "\n> ";

  while (std::cin >> current)
  {
    for(std::string w:blacklist)
    {
      if (current == w)
        current = "BLEEP";
    }
    censored += (current + ' ');
  }

  std::cout << "\n\nCensored text: "<< censored << '\n';
  return 0;
}
