// This program is used to understand abstraction
#include <iostream>

class Smartphone {
  // Our high-level ABSTRACT base class of Smartphone
  public:
    // Each sub-class of Smartphone will have an implementation of the following
    // virtual member functions.
    virtual void take_selfie() = 0;
    virtual void make_call() = 0;
};

class Android:public Smartphone {
  // Android and any other sub-class of Smartphone inherits core functionality
  // from Smartphone but is allowed to implement that core functionality in its
  // own way
  public:
    void take_selfie() { std::cout << "Android takes selfie\n"; }
    void make_call() { std::cout << "Android makes call\n"; }
};

class Iphone:public Smartphone {
  // Underlying mechanisms for take_selfie() amd make_call() can be completely
  // different from Android.
  public:
    void take_selfie() { std::cout << "Iphone takes selfie\n"; }
    void make_call() { std::cout << "Iphone makes call\n"; }
};

// Abstraction allows reuse the base class template, allows different
// implementations of core functions in sub-classes, and separates complex
// implementation details of base functionality from other parts of our
// application e.g. the UI
// For more on this see,
// https://www.youtube.com/watch?v=Ui7Dca5Kbvw&list=PL43pGnjiVwgTJg7uz8KUGdXRdGKE0W_jN&index=7

int main() {

  return 0;
}
