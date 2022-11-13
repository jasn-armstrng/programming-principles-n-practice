/*
This programs finds the min, max, and mode of a sequence of strings.
Definitions:
 min: shortest length string
 max: longest length string
 mode: string that appears most frequently

Note:
1. The min and max functions: does a lexicographical comparison on the strings.
   This compares strings in the same way that they would be listed in dictionary
   order, generalized to work for strings with non-letter characters.

2. The mode function: when elements have the same frequency - where
   frequency is greater > 1 - it outputs the first element found with that
   frequency.
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

  std::cout << "Enter a sequence of strings to get the min, max and mode (To finish, press Enter then Ctrl-D):\n";
  for(std::string str; std::cin>>str;) strings.push_back(str);

  if (!strings.empty())
  {
    std::cout << "\nResults:\n";
    std::cout << "--------\n";
    std::cout << "Min (string): " << min(strings) << '\n';
    std::cout << "Max (string): " << max(strings) << '\n';
    std::cout << "Mode(string): " << mode(strings) << '\n';
    std::cout << '\n';
  }
  else
  {
    std::cout << "\nNo results.\n";
  }
  return 0;
}

std::string min(const std::vector<std::string> v)
{
  std::string min_string = v[0];
  for(int i = 0; i < int(v.size()); ++i)
    if (v[i] < min_string) // lexicographical comparison
      min_string = v[i];

  return min_string;
}

std::string max(const std::vector<std::string> v)
{
  std::string max_string = v[0];
  for(int i = 0; i < int(v.size()); ++i)
    if (v[i] > max_string)
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
  return (max_count>1) ? max_value : "No mode";
}
