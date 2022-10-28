// This program detects adjacent repeated words in a stream entered by user.

#include <iostream>
int main()
{
  std::cout << "Note: To end this program press CTRL+D.\n";
  std::cout << "Please enter a sentence >= 2 words: ";
  std::string previous = " "; // previous word initialized to not a word. Recall cin skips spaces
  std::string current;
  while (std::cin >> current) // read a stream of words
  {
    if (previous == current) // check if current being read is same as last
      std::cout << "repeated word: " << current << "\n";
    previous = current; // current becomes previous before next in stream is read
  }
}
