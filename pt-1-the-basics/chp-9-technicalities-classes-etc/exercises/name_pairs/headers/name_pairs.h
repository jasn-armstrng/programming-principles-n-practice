/*******************************************************************************
Name_pairs.h

Provides the class and function definitions to read and store <Name Age> pairs
from user input. Prints pairs to console.
*******************************************************************************/
#include <iostream>
#include <vector>

/*                        Class/member definitions                            */
class Person
{
  public:
    std::string name;
    double age;
    Person(std::string& n, double& a):name{n}, age{a} {} // constructor
};

class Name_pairs
{
  public:
    std::vector<Person> person;
    void read_name_age(); // read, store and sort <name age> entries by user
};

void Name_pairs::read_name_age()
{
  std::string msg { "Enter <Name Age> of persons. Enter <None 0> to end:\n" };
  std::string name;
  double age;

  std::cout << msg; // Prompt for name/age pairs and store
  while(std::cin >> name >> age)
  {
    if (name == "None" && age == 0) { break; }
    Person p { name, age };
    person.push_back(p);
  }

  auto lambda = [](const Person &a, const Person &b) { return a.name < b.name; };
  std::sort(person.begin(), person.end(), lambda); // Sort entries on name
}

/*                            Helper functions                                */
void operator<<(std::ostream& os, Name_pairs& np)
{
  for(Person p: np.person)
  {
    os << p.name << ", " << p.age << '\n';
  }
}
