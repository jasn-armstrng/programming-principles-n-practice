#include <iostream>
#include <vector>

class Name_pairs {
public:
  void read_names() {
    // reads a series of names from console input
    std::string n,
                msg { "Enter names below. To end enter a semi-colon (;):\n" };

    std::cout << msg;

    while(std::cin >> n) {
      if(n == ";") { break; }
      name.push_back(n);
    }
  }

private:
  std::vector<std::string> name;
  std::vector<double> age;
};
