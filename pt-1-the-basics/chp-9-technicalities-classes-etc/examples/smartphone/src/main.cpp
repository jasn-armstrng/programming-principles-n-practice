// This program is used to understand abstraction. See notes in header file.
#include "../headers/Smartphone.h"

int main() {
  // An application developer need not know how either function is implemented on
  // the backend.
  Smartphone* s1 = new Iphone();
  s1->take_selfie();
  s1->make_call();

  return 0;
}
