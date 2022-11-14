// This program stores and retrieves name/value pairs

#include <iostream>
#include <vector>
int main()
{
  std::vector<std::string> names;
  std::vector<int> scores;
  std::string name;
  int score;

  std::cout << "Please enter name and score. To end enter NoName 0.\n";
  std::cout << "Name Score: ";
  while(std::cin >> name >> score)
  {
    for(std::string n: names)
    {
      if (name == n)
        std::cout << "Name already entered.\n";
        break;
    }

    if(name == "NoName" && score == 0)
    {
      break;
    }
    else
    {
      names.push_back(name);
      scores.push_back(score);
    }
  }
  for (int i = 0; i < int(names.size()); ++i)
  {
    std::cout << "Name: " << names[i] << " Score: " << scores[i] << '\n';
  }

  return 0;
}
