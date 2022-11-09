// There is an old story that the inventor of chess asked for his reward -
// a grain of rice on the first square of the chess board, 2 on the second,
// 4 on the third and so on ...
// This program computes the number of squares needed for 10^3, 10^6 and 10^9
// grains of rice.

#include <iostream>
#include <cmath>
int main()
{
  double rice_grains;
  std::string intro =
    "There is an old story that the inventor of chess asked for his reward -"
    "\n1 grain of rice on the first square of the board, 2 on the second, 4 on"
    "\nthe third and so on ... .\n"
    "\n\nThis program computes and outputs the number of squares needed for at"
    "\nleast N grains of rice.\n";

  std::string outro =
    "\nIf the reward could have been granted he would have been given"
    "\n18,446,744,073,709,551,615 grains.\n";

  std::cout << "+----------------+\n";
  std::cout << "| Rice and Chess |\n";
  std::cout << "+----------------+\n\n";

  std::cout << intro << '\n';
  std::cout << "How to use this program:\n";
  std::cout << "------------------------\n";
  std::cout << "- Enter number at 'Rice grains:' prompt\n";
  std::cout << "- Enter | to exit program.\n";

  std::cout << "\nRice grains: ";
  while(std::cin >> rice_grains)
  {

  }
  std::cout << outro;
  return 0;
}


// 184467440737095516150
