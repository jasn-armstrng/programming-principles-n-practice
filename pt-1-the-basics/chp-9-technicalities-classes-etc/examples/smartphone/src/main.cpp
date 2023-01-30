// This program is used to understand abstraction
#include <iostream>

class Smartphone {
  public:
    virtual void take_selfie() = 0;
    virtual void make_call() = 0;
};

class Android {
  public:
    void take_selfie() { std::cout << "Android takes selfie\n"; }
    void make_call() { std::cout << "Android makes call\n"; }
};

int main() {

  return 0;
}
