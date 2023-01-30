// This program further practice with inheritance and virtual functions also
// introduces pure virtual functions

#include <iostream>

class Instrument {
  public:
    void make_sound() {
      std::cout << "Instrument playing ...\n";
    }
};

class Accordion:public Instrument {
  void make_sound() {
    std::cout << "Acordion playing ...\n";
  }
};

int main() {

  return 0;
}
