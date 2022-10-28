// This program prompts user to enter their first name and age. Both values will
// then be logged to the screen.

#include <iostream>
int main(){
  std::cout << "Please enter your first name and age\n";
  std::string first_name = "???"; // String variable with default value
  int age = -1; // integer variable (default -1 means "don't know the age")
  std::cin >> first_name >> age;
  std::cout << "Hello, " << first_name << " (age " << age << ")\n";
}
