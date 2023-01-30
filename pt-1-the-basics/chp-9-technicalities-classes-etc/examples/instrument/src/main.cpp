// This program further practice with inheritance and virtual functions also
// introduces pure virtual functions

#include <iostream>
#include <vector>

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

class Piano:public Instrument {
  void make_sound() {
    std::cout << "Piano playing ...\n";
  }
};

int main() {
  Instrument* i1 = new Accordion();
  Instrument* i2 = new Piano();

  // Making use of polymorphism
  std::vector<Instrument*> instruments = { i1, i2 };
  for(Instrument* i: instruments) { i->make_sound(); }

  return 0;
}
