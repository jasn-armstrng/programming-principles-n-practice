// This program analyzes words from user input stream. Words
// found in blacklist are written to output as BLEEP.

#include <iostream>
#include <vector>

std::string check_blacklist(std::string x)
{
  std::vector<std::string> blacklist = {"fox", "lazy", "dog"};
  for(std::string w:blacklist)
    {
      if (x == w)
        return "BLEEP";
    }
  return x;
}

int main()
{
  std::string censored = "";
  std::string current;
  std::cout << "+-------------+\n";
  std::cout << "| Bleep words |\n";
  std::cout << "+-------------+\n\n";

  // Prompt for use input
  std::cout << "Enter your text to censor at > below.\n";
  std::cout << "When you are done press Enter then ctrl+D for results.\n";
  std::cout << "\n> ";

  // Read in input and check against blacklist
  while (std::cin >> current)
  {
    current = check_blacklist(current);
    censored += (current + ' ');
  }

  std::cout << "\n\nCensored text: "<< censored << '\n';
  return 0;
}
