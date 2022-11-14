// This program stores and retrieves name/value pairs

#include <iostream>
#include <vector>

int mode(const std::vector<std::string> v);
void show_all(const std::vector<std::string> n, const std::vector<std::string> s);
void find_player_score(const std::vector<std::string> n, const std::vector<std::string> s);

int main()
{
  std::vector<std::string> players;
  std::vector<std::string> scores;
  std::string player, score;
  char option;

  std::cout << "Please enter player name and score on a new line below. To end enter: NoName 0\n";
  std::cout << "\nPlayer Score:\n";
  std::cout << "-------------\n";
  for (std::string player, score; std::cin >> player >> score;)
  {
    if(player == "NoName" && score == "0")
    {
      break;
    }
    else
    {
      players.push_back(player);
      scores.push_back(score);
    }

    if(mode(players) > 1){
      std::cout << "\nERROR: Duplicate name entry.\n";
      players.pop_back(), scores.pop_back();
      break;
    }
  }

  std::cout << "\n[1] Show all scores\n[2] Find player score\n";
  std::cout << "\nOption: "; std::cin >> option;
  if (option == '1')
  {
    show_all(players, scores);
  }
  if (option == '2')
  {
    find_player_score(players, scores);
  }
  return 0;
}

void find_player_score(const std::vector<std::string> n, const std::vector<std::string> s)
{
  std::string player, score = "-1";
  std::cout << "Player: "; std::cin >> player;
  for (int i = 0; i < int(n.size()); ++i)
  {
    if (n[i] == player)
    {
      score = s[i];
      break;
    }
  }
  if (score != "-1")
    std::cout << "Score: " << score << '\n';
  else
    std::cout << "Error: Player not found.\n";
}

void show_all(const std::vector<std::string> n, const std::vector<std::string> s)
{
  std::cout << "\nScores:\n";
  std::cout << "-------\n";
  for (int i = 0; i < int(n.size()); ++i)
  {
    std::cout << n[i] << ", " << s[i] << '\n';
  }
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
