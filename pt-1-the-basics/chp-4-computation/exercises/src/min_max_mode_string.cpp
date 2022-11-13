/*
This programs finds the min, max, and mode of a sequence of strings.
Definitions:
 min: shortest length string
 max: longest length string
 mode: string that appears most frequently

 1. Find min string: Store the first string. Compare the length of each
    subsequent string with the length of stored string. If subsequent string is
    less store that string ...
 2. Find max string: Same as 1 but if length is greater then store.
 3. Find mode: Count the occurence of each string in the vector each count is
    compared against a max count and replaces it if greater.

  - Note for 1 and 2 if 2 strings are the same length then compare Ascii values
*/

#include <iostream>
#include <vector>

std::string min(const std::vector<std::string> v);
std::string max(const std::vector<std::string> v);
std::string mode(const std::vector<std::string> v);

int main()
{
  std::vector<std::string> strings;
  std::string str, min_string, max_string;

  std::cout << "+---------------------------+\n";
  std::cout << "| Min, Max, Mode of Strings |\n";
  std::cout << "+---------------------------+\n\n";

  std::cout << "Enter a sequence of strings: ";
  for(std::string str; std::cin>>str;) strings.push_back(str);

  std::cout << "\nResults:\n";
  std::cout << "--------\n";
  std::cout << "Min (string): " << min(strings) << '\n';
  std::cout << "Max (string): " << max(strings) << '\n';
  std::cout << "Mode(string): " << mode(strings) << '\n';

  return 0;
}

std::string min(const std::vector<std::string> v)
{
  std::string min_string = v[0];
  for(int i = 0; i < int(v.size()); ++i)
    if (int(v[i].size()) < int(min_string.size()))
      min_string = v[i];

  return min_string;
}

std::string max(const std::vector<std::string> v)
{
  std::string max_string = v[0];
  for(int i = 0; i < int(v.size()); ++i)
    if (int(v[i].size()) > int(max_string.size()))
      max_string = v[i];

  return max_string;
}

std::string mode(const std::vector<std::string> v)
{
  std::string max_value; // Mode
  int max_count = 0;

  for(std::string i: v)
  {
    int count = 0;
    for(std::string j: v)
    {
      if(i==j)
        ++count;
    }
    if (count>max_count)
    {
      max_value = i;
      max_count = count;
    }
  }
  if (max_count>1)
    return max_value;

  return "No mode"; // If no repeated strings
}
