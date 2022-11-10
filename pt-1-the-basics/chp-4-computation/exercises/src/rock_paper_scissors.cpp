// This program plays the game "Rock, Paper, Scissors"

#include <iostream>
#include <random>
#include <vector>

// Global. Updated by function update_score_board. Read by final_score.
std::vector<int> score_board = {0, 0};

std::string round_result(std::string p_move, std::string c_move)
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

void update_score_board(std::string r_result)
{
  if (r_result == "Player wins!" || r_result == "Love always wins!")
    ++score_board[0];
  else if (r_result == "Computer wins!")
    ++score_board[1];
}

void final_score(std::vector<int> s_board)
{
  if (s_board[0] > s_board[1])
    std::cout << "\nWinner!" << '\n';
  else if (s_board[1] > s_board[0])
    std::cout << "\nLoser :P" << '\n';
  else
    std::cout << "\nThanks for playing!" << '\n';
}

int main()
{
  // List of moves computer randomly chooses from
  std::vector<std::string> moves = {"scissors", "rock", "paper", "paper", "rock", "scissors", "paper", "scissors", "rock"};

  // Next 2 lines make up our psuedo-random number generator
  std::random_device ran_dev;
  std::uniform_int_distribution<int> dist(0,8);

  std::string player_move, computer_move;
  int rounds = 1;
  char play_again;

  std::cout << "+-----------------------+\n";
  std::cout << "| Rock, Paper, Scissors |\n";
  std::cout << "+-----------------------+\n\n";

  std::cout << "To play: Enter either 'rock', 'paper', or 'scissors' at the prompt below.\n\n";

  std::cout << "Round: " << rounds;
  std::cout << "\n-----------------------------";
  std::cout << "\nYour move: ";
  while (std::cin >> player_move)
  {
    // Random draw from moves
    computer_move = moves[dist(ran_dev)];

    // Show user computer move and round outcome
    std::cout << "Computer: " << computer_move << '\n';
    std::cout << "Result: " << round_result(player_move, computer_move) << '\n';

    // Update score-board
    update_score_board(round_result(player_move, computer_move));

    // Show score
    std::cout << "-----------------------------\n";
    std::cout << "Score: Player[" << score_board[0] << "] Computer [" << score_board[1] << "]\n";

    // Ask user to play again
    std::cout << "\nPlay again [y/n]: ";
    std::cin >> play_again;
    if (play_again == 'n')
      break;
    else
      ++rounds;
      std::cout << "\nRound: " << rounds;
      std::cout << "\n-----------------------------";
      std::cout << "\nYour move: ";
  }
  // outro
  final_score(score_board);
  return 0;
}
