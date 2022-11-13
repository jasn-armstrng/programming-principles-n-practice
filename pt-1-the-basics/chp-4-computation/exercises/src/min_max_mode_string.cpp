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
  min_string = strings[0], max_string = strings[1];

  for(std::string s: strings)
  {
    if (int(s.size()) < int(min_string.size()) && s < min_string)
      min_string = s;

    if (int(s.size()) > int(max_string.size()) && s > max_string)
      max_string = s;
  }

  std::cout << "\nResults:\n";
  std::cout << "--------\n";
  std::cout << "Min (string): " << min_string << '\n';
  std::cout << "Max (string): " << max_string << '\n';
  std::cout << "Mode(string): " << mode(strings) << '\n';

  return 0;
}

std::string mode(const std::vector<std::string> v)
{
  std::string max_value; // Mode
  int max_count = 0; // Tracks the max frequency of a value in the vector

  // This nested iteration and count works because if there is a mode it does
  // not beat the count it got on first iteration thru the inner for.
  for(std::string i: v)
  {
    int count = 0; // Tracks consecutive value counts. Reset for each iteration.
    for(std::string j: v)
    {
      if(i==j)
        ++count;
    }
    if (count>max_count) // Then update the mode and frequency
    {
      max_value = i;
      max_count = count;
    }
  }
  if (max_count>1)
    return max_value;

  return "No mode"; // If no repeated numbers in a set of elements > 0, then no mode
}
