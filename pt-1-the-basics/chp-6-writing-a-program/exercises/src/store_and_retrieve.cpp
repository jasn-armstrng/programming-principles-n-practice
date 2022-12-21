// This program stores and retrieves name/value pairs
#include <iostream>
#include <vector>

// Class definition
class Name_value {
  public:
    std::string name;
    std::string value;
};

// Function declarations
int mode(const std::vector<std::string> v);
void options(const std::vector<Name_value> nvv);
void show_all(const std::vector<Name_value> nvv);
void find_player_score(const std::vector<Name_value> nvv);
void find_score(const std::vector<Name_value> nvv);

int main()
{
  std::vector<Name_value> players_score;
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
      Name_value ps;
      ps.name = player, ps.value = score;
      players_score.push_back(ps);

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
  options(players_score);
  return 0;
}

// Function definitions
void options(const std::vector<Name_value> nvv)
{
  std::string queries = "\n[1] Show all scores\n[2] Find player's score\n[3] Find score\n[4] Exit\nOption: ";
  char option;

  std::cout << queries;
  while(std::cin>>option)
  {
    if(option=='1')
      show_all(nvv);

    if(option=='2')
      find_player_score(nvv);

    if(option=='3')
      find_score(nvv);

    if(option=='4')
    {
      std::cout << '\n';
      break;
    }
    std::cout << queries; // Repeat options
  }
}

void find_score(const std::vector<Name_value> nvv) {
  std::string score;
  int count = 0;
  std::cout << "\nScore: "; std::cin >> score;
  for (Name_value nv: nvv) {
    if (nv.value == score) {
      ++count;
      std::cout << nv.name << ", " << nv.value << '\n';
    }
  }
  if (count == 0) { std::cout << "Sorry, score not found.\n"; }
}

void find_player_score(const std::vector<Name_value> nvv) {
  std::string player, score = "-1";
  std::cout << "\nPlayer: "; std::cin>>player;
  for (Name_value nv: nvv) {
    if (nv.name == player) {
      score = nv.value;
      break;
    }
  }
  if(score!="-1")
    std::cout << "Score: " << score << '\n';
  else
    std::cout << "Sorry, player not found.\n";
}

void show_all(const std::vector<Name_value> nvv) {
  std::cout << "\nScores:\n";
  std::cout << "-------\n";
  for (Name_value nv: nvv) {
    std::cout << nv.name << ", " << nv.value << '\n';
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
