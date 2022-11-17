// This program does conversions between Celsius and Fahrenheit

#include <iostream>

inline void error(const std::string& s);
inline void keep_window_open();
double ctof(double c);
double ftoc(double f);
int main()
try{

  std::cout << ftoc(10) << '\n';
  std::cout << ftoc(-10) << '\n';
  std::cout << ftoc(100) << '\n';
  std::cout << ftoc(-100) << '\n';
  //std::cout << ctof(-300) << '\n';
  keep_window_open();
  return 0;
}
catch(std::exception& e){
  std::cerr << "\nError: " << e.what() << '\n';
  keep_window_open();
  return 1;
}
catch(...){ // all other unthrown errors
  std::cerr << "\nError: unknown exception" << '\n';
  keep_window_open();
  return 2;
}

inline void error(const std::string& s){throw std::runtime_error(s);}

inline void keep_window_open(){char ch; std::cin>>ch;};

double ctof(double c){
  // converts celsius to fahrenheit
  // pre-conditions: c >= -273.15 (absolute zero)
  // post-conditions: returns value >= -459.67 F (absolute zero)
  if(c < -273.15){error("Value entered is below absolute zero");}
  return (c*9)/5+32;
}

double ftoc(double f){
  // converts fahrenheit to celsius
  // pre-conditions: f >= −459.67 F (absolute zero)
  // post-conditions: returns a celsius value > absolute 0 (-273.15)
  if(f < -459.67){error("Value entered is below absolute zero");}
  return (f-32)*5/9;
}
