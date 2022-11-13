/*
This programs finds the min, max, and mode of a sequence of strings.
Definitions:
 min: shortest length string
 max: longest length string
 mode: string that appears most frequently

 1. Find min string: Store the first string index and its length in an vector
    of size 2. Compare the length of each subsequent string with the length in
    the vector. If less then that string index and length are the new values in
    vector.
 2. Find max string: Same as 1 but if length is greater then we update the
    vector with the new values.
 3. Find mode: Use the mode function previously created
*/

#include <iostream>
#include <vector>

int main()
{
  std::vector<std::string> strings;
  std::string str, min_string, max_string;

  std::cout << "+---------------------------+\n";
  std::cout << "| Min, Max, Mode of Strings |\n";
  std::cout << "+---------------------------+\n\n";

  std::cout << "Enter a sequence of strings: ";
  for(std::string str; std::cin>>str;) strings.push_back(str);
  min_string = strings[0], max_string = strings[1];

  for(std::string s: strings)
  {
    if (int(s.size()) < int(min_string.size()) && s < min_string)
      min_string = s;

    if (int(s.size()) > int(max_string.size()) && s > max_string)
      max_string = s;
  }

  // std::cout << "Min: " << min_string << " Max: " << max_string <<'\n';
  // std::string s1 = "is",
  //             s2 = "be";
  // bool comp = s1 < s2;
  // std::cout << comp << '\n';
  return 0;
}
