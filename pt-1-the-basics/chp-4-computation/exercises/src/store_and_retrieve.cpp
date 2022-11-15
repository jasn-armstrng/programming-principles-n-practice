// This program stores and retrieves name/value pairs
#include <iostream>
#include <vector>

// Function declarations
int mode(const std::vector<std::string> v);
void options(const std::vector<std::string> p, const std::vector<std::string> s);
void show_all(const std::vector<std::string> p, const std::vector<std::string> s);
void find_player_score(const std::vector<std::string> p, const std::vector<std::string> s);
void find_score(const std::vector<std::string> p, const std::vector<std::string> s);

int main()
{
  std::vector<std::string> players;
  std::vector<std::string> scores;
  std::string player, score;

  std::cout << "+--------------------+\n";
  std::cout << "| Store and Retrieve |\n";
  std::cout << "+--------------------+\n\n";

  std::cout << "Please enter player name and score on a new line below. To end enter: NoName 0\n";
  std::cout << "\nPlayer Score:\n";
  std::cout << "-------------\n";

  for (std::string player, score; std::cin>>player>>score;)
  {
    if(player=="NoName" && score=="0") // Input terminator
    {
      break;
    }
    else
    {
      players.push_back(player);
      scores.push_back(score);
    }
    // Notify of and remove duplicate name entry
    if(mode(players)>1)
    {
      std::cout << "\nERROR: Duplicate name entry.\n";
      players.pop_back(), scores.pop_back();
      break;
    }
  }
  // List, search, and exit options
  options(players, scores);
  return 0;
}

// Function definitions
void options(const std::vector<std::string> p, const std::vector<std::string> s)
{
  std::string queries = "\n[1] Show all scores\n[2] Find player's score\n[3] Find score\n[4] Exit\nOption: ";
  char option;

  std::cout << queries;
  while(std::cin>>option)
  {
    if(option=='1')
      show_all(p, s);

    if(option=='2')
      find_player_score(p, s);

    if(option=='3')
      find_score(p, s);

    if(option=='4')
    {
      std::cout << '\n';
      break;
    }
    std::cout << queries; // Repeat options
  }
}

void find_score(const std::vector<std::string> p, const std::vector<std::string> s)
{
  std::string score;
  int count = 0;
  std::cout << "\nScore: "; std::cin >> score;

  std::cout << "Players:\n";
  std::cout << "--------\n";
  for(int i = 0; i<int(s.size()); ++i)
  {
    if(s[i]==score)
    {
      ++count;
      std::cout << p[i] << ", " << s[i] << '\n';
    }
  }
  if(count==0)
    std::cout << "-, -\n";
}

void find_player_score(const std::vector<std::string> p, const std::vector<std::string> s)
{
  std::string player, score = "-1";
  std::cout << "\nPlayer: "; std::cin>>player;
  for(int i = 0; i<int(p.size()); ++i)
  {
    if(p[i]==player)
    {
      score = s[i];
      break;
    }
  }
  if(score!="-1")
    std::cout << "Score: " << score << '\n';
  else
    std::cout << "Error: Player not found.\n";
}

void show_all(const std::vector<std::string> p, const std::vector<std::string> s)
{
  std::cout << "\nScores:\n";
  std::cout << "-------\n";
  for(int i = 0; i<int(p.size()); ++i)
  {
    std::cout << p[i] << ", " << s[i] << '\n';
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
    if(count>max_count)
    {
      max_count = count;
    }
  }
  return max_count;
}
