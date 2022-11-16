// This program converts Celsius to Kelvin
#include <iostream>
double ctok(double c);
inline void error(const std::string& s);
int main(){
  double c = 0;
  std::cin >> c;
  double k = ctok(c);
  std::cout << k << " Kelvin" << '\n';
  return 0;
}

double ctok(double c){
  // converts Celsius to Kelvin
  // pre-conditions: cel >= -273.15
  // post-conditions: returns a positive value. 0 Kelvin = absolute zero (-273.15c)
  if (c < -273.15) { error("Value entered is below absolute zero"); }
  double kel = c+273.15;
  return kel;
}

inline void error(const std::string& s){
	throw std::runtime_error(s);
}
