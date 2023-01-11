#include "swap.h"

void swap_v(int a, int b) { // pass by val
  int temp;
  temp = a;
  a = b;
  b = temp;
}

void swap_r(int& a, int& b) { // pass by ref
  int temp;
  temp = a;
  a = b;
  b = temp;
}

void swap_cr(const int& a, const int& b) { // pass by const ref
  int temp;
  temp = a;
  a = b; // compilation error: can't mod const a, same for b in line below
  b = temp;
}
