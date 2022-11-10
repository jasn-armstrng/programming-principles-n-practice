// This program plays the game "Rock, Paper, Scissors"

#include <iostream>
#include <random>
#include <vector>

std::string outcome(std::string p_move, std::string c_move)
{
  if (p_move == c_move)
    return "Draw!";

  if (p_move == "rock" && c_move == "scissors")
    return "Player wins!";
  else if (c_move == "rock" && p_move == "scissors")
    return "Computer wins!";

  if (p_move == "paper" && c_move == "rock")
    return "Player wins!";
  else if (c_move == "paper" && p_move == "rock")
    return "Computer wins!";

  if (p_move == "scissors" && c_move == "paper")
    return "Player wins!";
  else if (c_move == "scissors" && p_move == "paper")
    return "Computer wins!";

  // Easter egg
  if (p_move == "love")
    return "Love conquers all!";

  return "No result!";
}

int main()
{
  // List of moves computer randomly chooses from
  std::vector<std::string> moves = {"rock", "paper", "scissors", "rock", "paper", "scissors", "rock", "paper", "scissors"};

  // Next 2 lines make up our psuedo-random number generator
  std::random_device ran_dev;
  std::uniform_int_distribution<int> dist(0,8);

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
