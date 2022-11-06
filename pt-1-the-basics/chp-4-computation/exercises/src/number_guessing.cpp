// This program uses binary search to determine the number the player has chosen

#include <iostream>
int main()
{
  int min = 1;
  int max = 100;
  int mid = (min+max)/2;
  int guesses = 0;
  bool number_found = false;
  char response, hint;

  std::cout << "+-------------------+\n";
  std::cout << "| Number 'Guessing' |\n";
  std::cout << "+-------------------+\n\n";

  std::cout << "Hello, player!\n";
  std::cout << "\nPlease choose a number between 1 and 100, and within\n";
  std::cout << "seven I will 'guess' your number.\n";

  std::cout << "\nReady? Here I go ...\n";

  while (!number_found)
  {
    std::cout << "\nIs " << mid << " your number (y/n): ";
    std::cin >> response;
    ++guesses;
    if (response == 'n')
    {
      std::cout << "Then is your number higher or lower (h/l): ";
      std::cin >> hint;
      switch(hint)
      {
        case('h'):
          min = mid+1;
          mid = (min+max)/2;
          break;
        case('l'):
          max = mid-1;
          mid = (min+max)/2;
          break;
        default:
          std::cout << "C'mon, that's not a hint.\n";
          break;
      }
    }
    else
    {
      number_found = true;
      std::cout << "\nGreat! Got it in " << guesses << ".\n";
    }
  }
  return 0;
}
