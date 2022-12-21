#include <iostream>
#include <vector>

class Name_value {
  public:
    std::string name;
    int value;
};

int main() {
  std::vector<Name_value> players_score;

  Name_value p1;
  p1.name = "Hrothgar", p1.value = 23;
  players_score.push_back(p1);

  Name_value p2;
  p2.name = "Aulfric", p2.value = 25;
  players_score.push_back(p2);

  Name_value p3;
  p3.name = "Gothmar", p3.value = 22;
  players_score.push_back(p3);

  for (Name_value nv: players_score) {
    std::cout << "Player: " << nv.name << ", Score: " << nv.value << '\n';
  }

  return 0;
}
