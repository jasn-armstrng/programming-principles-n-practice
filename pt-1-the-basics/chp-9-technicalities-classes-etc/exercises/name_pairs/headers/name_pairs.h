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
  std::vector<Person> person;
  void read_name_age();
};

void Name_pairs::read_name_age() {
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

void operator<<(std::ostream& os, Name_pairs& np) {
  for(Person p: np.person) {
    os << p.name << ", " << p.age << '\n';
  }
}
