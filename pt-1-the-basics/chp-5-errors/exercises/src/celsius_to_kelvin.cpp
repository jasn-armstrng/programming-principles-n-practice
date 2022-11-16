// This program converts Celsius to Kelvin
#include <iostream>

inline void keep_window_open();
inline void error(const std::string& s);
double ctok(double c);

int main(){
  double c = 0;
  std::cout << "Celsius: ";
  std::cin >> c;
  std::cout << "Kelvin: " << ctok(c) << '\n';
  keep_window_open();
  return 0;
}

inline void keep_window_open(){ char ch; std::cin>>ch; }

inline void error(const std::string& s){ throw std::runtime_error(s); }

double ctok(double c){
  // converts Celsius to Kelvin
  // pre-conditions: cel >= -273.15
  // post-conditions: returns a positive value. 0 Kelvin = absolute zero (-273.15c)
  if (c < -273.15) { error("Value entered is below absolute zero"); }
  return c+273.15;
}
