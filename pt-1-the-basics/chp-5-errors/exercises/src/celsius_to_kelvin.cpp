// This program converts Celsius to Kelvin
#include <iostream>
double cel_to_kel(double cel);
inline void error(const std::string& s);
int main(){

  return 0;
}

double cel_to_kel(double cel){
  // converts Celsius to Kelvin
  // pre-conditions: cel >= -273.15
  // post-conditions: returns a positive value. 0 Kelvin = absolute zero (-273.15c)
  if (cel < -273.15) { error("Value entered is below absolute zero"); }
  double kel = cel+273.15;
  return kel;
}

inline void error(const std::string& s){
	throw std::runtime_error(s);
}
