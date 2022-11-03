// This program analyzes words from user input stream. Words
// found in blacklist are written to output as BLEEP.

#include <iostream>
#include <vector>
int main()
{
  std::vector<std::string> blacklist = {"crap"};
  std::string current = "";
  std::cout << "+----------------+\n";
  std::cout << "| Bleep my words |\n";
  std::cout << "+----------------+\n\n";

  std::cout << "Note: To end this program press CTRL+D.\n";
  std::cout << "Start writing: ";

}
