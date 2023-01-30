// This program further practice with inheritance and virtual functions also
// introduces pure virtual functions

#include <iostream>

class Instrument {
  public:
    virtual void make_sound() = 0; // Pure virtual function. This makes Instrument
                                   // an abstract class.
};

class Accordion:public Instrument {
  // As a derived class of an abstract class it must have its own definition of make_sound()
  void make_sound() {
    std::cout << "Acordion playing ...\n";
  }
};

int main() {
  Instrument* i1 = new Accordion;
  i1->make_sound();

  return 0;
}
