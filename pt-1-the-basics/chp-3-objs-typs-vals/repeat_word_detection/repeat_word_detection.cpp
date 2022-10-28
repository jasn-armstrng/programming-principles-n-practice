// This program detects adjacent repeated words in a stream entered by user.

#include <iostream>
int main()
{
  int word_counter = 0;
  std::string previous = " "; // previous word initialized to not a word. Recall cin skips spaces
  std::string current;

  std::cout << "Note: To end this program press CTRL+D.\n";
  std::cout << "Please enter a sentence >= 2 words: ";
  while (std::cin >> current) // read a stream of words
  {
    ++word_counter;
    if (previous == current) // check if current being read is same as last
      std::cout << current << " - repeated at position " << word_counter << ".\n";
    previous = current; // current becomes previous before next in stream is read
  }
}
