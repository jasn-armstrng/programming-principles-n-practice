/*
This programs finds the min, max, and mode of a sequence of strings.
Definitions:
 min: shortest length string
 max: longest length string
 mode: string that appears most frequently

 1. Find min string: Store the first string and its length in an vector
    of size 2. Compare the length of each subsequent string with the length in
    the vector. If less then that string and length are the new values in
    vector.
 2. Find max string: Same as 1 but if length is greater then we update the
    vector with the new values.
 3. Find mode: Use the mode function previously created
*/

#include <iostream>
#include <vector>

int min(int x, int y){ return (x>y) ? y : x; }
int max(int x, int y){ return (x>y) ? x : y; }

int main()
{
  std::vector<std::string> strings;
  std::string str;

  std::cout << "+---------------------------+\n";
  std::cout << "| Min, Max, Mode of Strings |\n";
  std::cout << "+---------------------------+\n\n";

  std::cout << "Enter a sequence of strings: ";
  for(std::string str; std::cin>>str;) strings.push_back(str);

  return 0;
}
