// This program stores a prints name/age pairs entered by a user.
#include <iostream>
#include <vector>

class Person {
  public:
    std::string name;
    double age;
};

int main() {
  std::vector<Person> persons;
  std::string person_name;
  double person_age;

  std::string instructions {
    "Please enter name/age pairs; each pair on a new line.\n"
    "(press ctrl+D when finished):\n"
  };

  std::cout << instructions;
  while(std::cin >> person_name >> person_age) {
    Person p;
    p.name = person_name;
    p.age = person_age;
    persons.push_back(p);
  }

  // sort custom type vector on the element's class member variable using lambda
  // function.
  std::sort(persons.begin(), persons.end(),
          [](const Person &a, const Person &b) {return (a.name < b.name);});

  std::cout << "\nName\tAge\n";
  for(Person p: persons) {
    std::cout << p.name << '\t' << p.age << '\n';
  }

  return 0;
}
