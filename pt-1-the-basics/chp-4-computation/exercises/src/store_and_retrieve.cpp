// This program stores and retrieves name/value pairs

#include <iostream>
#include <vector>

int mode(const std::vector<std::string> v);

int main()
{
  std::vector<std::string> names;
  std::vector<std::string> scores;
  std::string name, score;


  std::cout << "Please enter name and score. To end enter NoName 0.\n";
  std::cout << "Name Score: ";

  for (std::string name, score; std::cin >> name >> score;)
  {
    if(name == "NoName" && score == "0")
    {
      break;
    }
  }

  for (int i = 0; i < int(names.size()); ++i)
  {
    std::cout << "Name: " << names[i] << " Score: " << scores[i] << '\n';
  }

  return 0;
}

int mode(const std::vector<std::string> v)
{
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
      max_count = count;
    }
  }
  return max_count;
}
