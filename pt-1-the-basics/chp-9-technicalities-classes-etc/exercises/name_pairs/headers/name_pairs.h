#include <iostream>
#include <vector>

class Name_pairs {
public:
  void read_names() {
    // reads a series of names from console input and stores them in name.
    std::string n;
    std::string msg { "Enter person names below. End by entering a semi-colon (;):\n" };

    std::cout << msg;

    while(std::cin >> n) {
      if(n == ";") { break; }
      name.push_back(n);
    }

    read_ages();
  }

  void read_ages() {
    // reads the ages of the names entered using read_names(). Call inside of
    // read_names
    double a;
    std::string msg { "Enter age of persons entered:\n" };

    std::cout << msg;
    for(unsigned i = 0; i < name.size(); ++i) {
      std::cout << name[i] << ": ";
      std::cin >> a;
      age.push_back(a);
    }
  }

private:
  std::vector<std::string> name;
  std::vector<double> age;
};
