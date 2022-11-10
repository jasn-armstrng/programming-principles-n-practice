// There is an old story that the inventor of chess asked for his reward -
// a grain of rice on the first square of the chess board, 2 on the second,
// 4 on the third and so on ...
// This program computes the number of squares needed for 10^3, 10^6 and 10^9
// grains of rice.

#include <iostream>
int main()
{
  int squares;
  double rice_on_squares;
  double rice_reward;

  std::string intro =
    "There is an old story that the inventor of chess asked for his reward -"
    "\n1 grain of rice on the first square of the board, 2 on the second, 4 on"
    "\nthe third and so on ... .\n"
    "\n\nThis program computes and outputs the number of squares needed for at"
    "\nleast N grains of rice.\n";

  std::string outro =
    "\nP.S. If the reward could have been granted he would be"
    "\ngiven a stupendous 18,446,744,073,709,551,615 grains.\n\n";

  std::cout << "+----------------+\n";
  std::cout << "| Rice and Chess |\n";
  std::cout << "+----------------+\n\n";

  std::cout << intro << '\n';
  std::cout << "How to use this program:\n";
  std::cout << "------------------------\n";
  std::cout << "- Enter number at 'Rice reward:' prompt\n";
  std::cout << "- For numbers > 1,000,000,000 please use scientific notation\n";
  std::cout << "- Enter a dash '-' to exit program.\n";

  std::cout << "\nRice grains: ";

  while(std::cin >> rice_reward)
  {
    squares = 0; // Reset this and rice on squares after each iteration
    rice_on_squares = 0;
    std::cout << "+-----------------------------------------+\n";
    for (double i = 1; rice_on_squares <= rice_reward; i*=2)
    {
      ++squares;
      rice_on_squares += i;
      std::cout << "Squares: [" << squares << "]\tTotal grains: " << rice_on_squares <<'\n';
    }
    std::cout << "+-----------------------------------------+\n";
    std::cout << "At least " << squares << " squares are needed.\n";
    std::cout << "\nRice grains: ";
  }

  std::cout << outro;
  return 0;
}
/*
Note: The max reward cannot be stored in the double as integer literal, as
highlighted in the warning below,

 rice_and_chess.cpp:51:10: warning: integer literal is too large to be represented in a signed integer type, interpreting as unsigned [-Wimplicitly-unsigned-literal]
 test = 18446744073709551615;

Favour scientific notation instead,
 test = 1.8446744e+19
*/
