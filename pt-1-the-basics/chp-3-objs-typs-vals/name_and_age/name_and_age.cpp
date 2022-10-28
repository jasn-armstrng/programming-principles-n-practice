// This program prompts user for their first name and age. Both values are
// then logged to the screen.

#include <iostream>
int main(){
  std::cout << "Please enter your first name and age\n"; // prompt for user info.
  std::string first_name = "???"; // string variable with default value "???" meaning "don't know the name"
  double age = -1.0; // double variable (default -1 means "don't know the age")
  std::cin >> first_name >> age; // read a string followed by an int/double
  std::cout << "Hello, " << first_name << " (age " << age << ")\n";
}
