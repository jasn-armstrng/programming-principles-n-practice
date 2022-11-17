// This program does conversions between Celsius and Fahrenheit

#include <iostream>

inline void error(const std::string& s);
double ctof(double c);
double ftoc(double f);
int main(){

  std::cout << ctof(10) << '\n';
  std::cout << ctof(-10) << '\n';
  std::cout << ctof(100) << '\n';
  std::cout << ctof(-100) << '\n';
  //std::cout << ctof(-300) << '\n';
  return 0;
}

// inline void error(const std::string& s){throw std::runtime_error(s);}

double ctof(double c){
  // converts celsius to fahrenheit
  // pre-conditions: c >= -273.15 (absolute zero)
  // post-conditions: returns value >= −459.67 F (absolute zero)
  //if (c < -273.15){ error("Value entered is below absolute zero");}
  return (c*9)/5+32;
}
