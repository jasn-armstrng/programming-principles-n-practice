// This project is completed for drill 2 of chp. 8 of Prog: Princ & Prac, pg 298
#include <iostream>
#include "../headers/swap.h"

int main() {
  int x = 7;
  int y = 9;
  swap_v(x, y);
  std::cout << x << ", " << y << '\n'; // -> 7, 9, arguments not modified
  swap_r(x, y);
  std::cout << x << ", " << y << '\n'; // -> 9, 7, arguments modified by ref
  // swap_cr(x, y); // -> error

  const int cx = 7;
  const int cy = 9;
  // swap_r(cx, cy); // error: function tries to modify const cx, cy
  // std::cout << cx << ", " << cy << '\n';
  swap_v(cx, cy);
  std::cout << cx << ", " << cy << '\n'; // -> 7, 9, arguments not modified

  double dx = 7;
  double dy = 9;
  swap_v(dx, dy);
  std::cout << dx << ", " << dy << '\n'; // -> 7, 9, arguments not modified
  // swap_r(dx, dy); // error: can't pass a double to an int reference
  // std::cout << dx << ", " << dy << '\n';

  return 0;
}
