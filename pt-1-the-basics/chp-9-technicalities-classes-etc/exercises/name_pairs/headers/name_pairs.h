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
  // void print() {
  //   // prints each name/age pair stored (one per line)
  //   std::cout << "\nName, Age"
  //             << "\n=========\n";
  //   for(unsigned i = 0; i < name.size(); ++i) {
  //     std::cout << name[i] << ", " << age[i] << '\n';
  //   }
  // }

  void read_name_age() {
    std::string msg { "Enter <Name Age> of persons. Enter <None 0> to end:\n" };
    std::string name;
    double age;

    // Prompt for name/age pairs and store
    std::cout << msg;
    while(std::cin >> name >> age) {
      if (name == "None" && age == 0) { break; }
      Person p { name, age };
      person.push_back(p);
    }

    // Sort entries on name
    auto lambda = [](const Person &a, const Person &b) { return a.name < b.name; };
    std::sort(person.begin(), person.end(), lambda);
  }

private:
  std::vector<Person> person;
  // std::vector<std::string> name;
  // std::vector<double> age;
};
