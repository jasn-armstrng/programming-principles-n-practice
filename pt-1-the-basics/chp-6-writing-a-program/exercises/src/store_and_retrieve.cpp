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
void ui();
bool duplicate_name_check(const std::string n, const std::vector<Name_value> nvv);
void options(const std::vector<Name_value> nvv); // nnv - name value vector
void show_all(const std::vector<Name_value> nvv);
void find_player_score(const std::vector<Name_value> nvv);
void find_score(const std::vector<Name_value> nvv);

int main()
{
  ui();
  return 0;
}

// Function definitions
void ui() {
  // present main interaction elements to user
  std::vector<Name_value> players_score;
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
      if (duplicate_name_check(player, players_score)) {
        std::cout << "Sorry, can't input duplicate player name.\n";
      } else {
        Name_value ps;
        ps.name = player, ps.value = score;
        players_score.push_back(ps);
      }
    }
  }
  // List, search, and exit options
  options(players_score);
}

void options(const std::vector<Name_value> nvv) {
  // presents user with a list of options to view stored data or exit
  std::string queries = "\n[1] Show all scores\n[2] Find player's score\n[3] Find score\n[4] Exit\nOption: ";
  char option;

  std::cout << queries;
  while(std::cin>>option) {
    if(option=='1') { show_all(nvv); }

    if(option=='2') { find_player_score(nvv); }

    if(option=='3') { find_score(nvv); }

    if(option=='4') {
      std::cout << '\n';
      break;
    }
    std::cout << queries; // Repeat options
  }
}

void find_score(const std::vector<Name_value> nvv) {
  // finds the player(s) with score from user input
  // pre-conditions: input vector should not be empty
  // post-conditions: return results in a table format or a not found message
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
  // finds the score of player from user input
  // pre-conditions: input vector should not be empty
  // post-conditions: return player score or a not found message
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
  // print all players and their scores
  // pre-conditions: input vector should not be empty
  std::cout << "\nScores:\n";
  std::cout << "-------\n";
  for (Name_value nv: nvv) {
    std::cout << nv.name << ", " << nv.value << '\n';
  }
}

bool duplicate_name_check(const std::string n, const std::vector<Name_value> nvv) {
  // check if name already exist in vector before insertion
  // pre-condtions: input vector should not be empty
  // post-conditions: return true/false
  for (Name_value nv: nvv) {
    if (nv.name == n) { return true; }
  }
  return false;
}
