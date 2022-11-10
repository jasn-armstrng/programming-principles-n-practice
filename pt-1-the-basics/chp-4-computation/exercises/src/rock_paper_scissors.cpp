// This program plays the game "Rock, Paper, Scissors"

#include <iostream>
#include <random>
#include <vector>

// Global. Updated by function update_score_board
std::vector<int> score_board = {0, 0};

std::string outcome(std::string p_move, std::string c_move)
{
  if (p_move == c_move)
    return "Draw!";

  if (p_move == "rock" && c_move == "scissors"){
    return "Player wins!";
  }else if (c_move == "rock" && p_move == "scissors")
  {
    return "Computer wins!";
  }

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
    return "Love always wins!";

  return "No result!";
}

void update_score_board(std::string o_come)
{
  if (o_come == "Player wins!" || o_come == "Love always wins!")
    ++score_board[0];
  else if (o_come == "Computer wins!")
    ++score_board[1];
}

int main()
{
  // List of moves computer randomly chooses from
  std::vector<std::string> moves = {"scissors", "rock", "paper", "paper", "rock", "scissors", "paper", "scissors", "rock"};

  // Next 2 lines make up our psuedo-random number generator
  std::random_device ran_dev;
  std::uniform_int_distribution<int> dist(0,8);

  std::string player_move;
  std::string computer_move;
  int rounds = 1;
  char play_again;

  std::cout << "+-----------------------+\n";
  std::cout << "| Rock, Paper, Scissors |\n";
  std::cout << "+-----------------------+\n\n";

  std::cout << "To play: Enter either 'rock', 'paper', or 'scissors' at the prompt below.\n\n";

  std::cout << "Round: " << rounds << '\n';
  std::cout << "------------\n";
  std::cout << "Your move: ";
  while (std::cin >> player_move)
  {
    computer_move = moves[dist(ran_dev)];
    std::cout << "Computer: " << computer_move << '\n';
    std::cout << "Result: " << outcome(player_move, computer_move) << '\n';

    // Update score-board
    update_score_board(outcome(player_move, computer_move));

    // Show score
    std::cout << "-----------------------------\n";
    std::cout << "Score: Player[" << score_board[0] << "] Computer [" << score_board[1] << "]\n";

    // Play again?
    std::cout << "\nPlay again [y/n]: ";
    std::cin >> play_again;
    if (play_again == 'n')
      break;
    else
      ++rounds;
      std::cout << "Round: " << rounds << '\n';
      std::cout << "------------\n";
      std::cout << "\nYour move: ";
  }
  std::cout << "\nThanks for playing!\n";
  return 0;
}
