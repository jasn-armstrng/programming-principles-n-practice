// This program further practice with inheritance and virtual functions also
// introduces pure virtual functions

#include <iostream>

class Instrument {
  public:
    virtual void make_sound() {
      std::cout << "Instrument playing ...\n";
    }
};

class Accordion:public Instrument {
  void make_sound() {
    std::cout << "Acordion playing ...\n";
  }
};

int main() {
  Instrument* i1 = new Accordion;
  i1->make_sound();

  return 0;
}
