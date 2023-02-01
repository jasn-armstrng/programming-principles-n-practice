#include <iostream>
#include <vector>

class Person {
public:
  std::string name;
  double age;

  Person(std::string& n, double& a):name{n}, age{a} { }
};

class Name_pairs {
public:
  void read_names() {
    // reads a series of names from console input and stores them in name
    std::string n;
    std::string msg { "Enter person names below. End by entering a semi-colon (;):\n" };

    std::cout << msg;

    while(std::cin >> n) {
      if(n == ";") { break; }
      name.push_back(n);
    }
  }

  void read_ages() {
    // reads the ages of the names entered using read_names()
    double a;
    std::string msg { "Enter age of persons entered:\n" };

    std::cout << msg;

    for(unsigned i = 0; i < name.size(); ++i) {
      std::cout << name[i] << ": ";
      std::cin >> a;
      age.push_back(a);
    }
  }

  void print() {
    // prints each name/age pair stored (one per line)
    std::cout << "\nName, Age"
              << "\n=========\n";
    for(unsigned i = 0; i < name.size(); ++i) {
      std::cout << name[i] << ", " << age[i] << '\n';
    }
  }

private:
  std::vector<std::string> name;
  std::vector<double> age;
};
