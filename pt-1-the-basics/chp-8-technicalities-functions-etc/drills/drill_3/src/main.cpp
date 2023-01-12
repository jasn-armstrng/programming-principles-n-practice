#include <iostream>

int main() {
  X::var = 7;
  X::print();         // print X's var
  using namespace Y;
  var = 9;
  print();            // print Y's var
  {
    using Z::var;
    using Z::print;   // print Z's var
    var = 11;
    print();
  }
  print();            // print Y's var
  X::print();         // print X's var
  return 0;
}
