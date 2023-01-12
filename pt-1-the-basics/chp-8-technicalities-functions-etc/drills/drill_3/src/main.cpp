#include <iostream>

namespace X {
  int var;
  void print() { std::cout << var << '\n'; }
}

namespace Y {
  int var;
  void print() { std::cout << var << '\n'; }
}

namespace Z {
  int var;
  void print() { std::cout << var << '\n'; }
}

int main() {
  X::var = 7;
  X::print();         // print X's var
  using namespace Y;
  var = 9;            // This is Y's var
  print();            // print Y's var
  {
    using Z::var;
    using Z::print;
    var = 11;
    print();          // print Z's var. We're in a Z exclusive block
  }
  print();            // print Y's var, because "using namespace Y" stated explicitly
  X::print();         // print X's var
  return 0;
}
