/*
This program outputs a subset of ascii characters - the
alphabet - and their decimal values.

Sample output below,

Chr     Dec     Chr     Dec
----------------------------
A       65      a       97
B       66      b       98
...
----------------------------
*/

#include <iostream>
int main()
{
  std::cout << "+---------------------------+\n";
  std::cout << "| Ascii Table - Chr and Dec |\n";
  std::cout << "+---------------------------+\n\n";
  // Table output
  std::cout << "Chr\tDec\tChr\tDec\n";
  std::cout << "----------------------------\n";
  for (int i = 65; i<91; ++i)
  {
    std::cout << char(i) << '\t' << i << '\t' << char(i+32) << '\t' << i+32 << '\n';
  }
  return 0;
}
