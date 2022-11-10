// This program plays the game "Rock, Paper, Scissors"

#include <iostream>
#include <random>
#include <vector>

int main()
{
  // List of moves computer randomly chooses from
  std::vector<std::string> moves = {"rock", "paper", "scissors", "rock", "paper", "scissors", "rock", "paper", "scissors"};



  std::string player_move;
  std::string computer_move;
  char play_again;

  std::cout << "+-----------------------+\n";
  std::cout << "| Rock, Paper, Scissors |\n";
  std::cout << "+-----------------------+\n\n";

  std::cout << "Your move: ";
  while (std::cin >> player_move)
  {

  }
  std::cout << "\nThanks for playing!\n";
  return 0;
}
