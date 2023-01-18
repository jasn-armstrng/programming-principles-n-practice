// This program is the solution for Ex. 8 Ques. 7
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

  std::cout << "\nPlease enter name/age pairs. Each on a new line.\n(press ctrl+D to stop):\n";
  while(std::cin >> person_name >> person_age) {
    Person p;
    p.name = person_name;
    p.age = person_age;
    persons.push_back(p);
  }

  return 0;
}
