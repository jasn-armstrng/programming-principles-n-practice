// This program does conversions between Celsius and Kelvin
#include <iostream>

// Function declarations
inline void keep_window_open();
inline void error(const std::string& s);
double ctok(double c);
double ktoc(double c);
void ui();

int main()
try{
  ui();
  keep_window_open();
  return 0;
}
catch(std::exception& e){
  std::cerr << "\nError: " << e.what() << '\n';
  keep_window_open();
  return 1; // indicates failure
}
catch(...){
  std::cerr << "\nError: Unknown exception" << '\n';
  keep_window_open();
  return 2; // indicates failure
}

// Function definitions
inline void keep_window_open(){char ch; std::cin>>ch;}

inline void error(const std::string& s){throw std::runtime_error(s);}

double ctok(double c){
  // converts Celsius to Kelvin
  // pre-conditions: cel >= -273.15
  // post-conditions: returns a +ve value. 0 Kelvin = absolute zero (-273.15c)
  if (c < -273.15) { error("Value entered is below absolute zero"); }
  return c+273.15;
}

double ktoc(double k){
  // converts Kelvin to Celsius
  // pre-conditions: k >= 0
  // post-conditions: returns a value above absolute zero (-273.15c)
  if (k < 0) { error("Value entered is below absolute zero"); }
  return k-273.15;
}

void ui(){
  // presents gui
  double v; // value
  char u; // unit

  std::cout << "+--------------------+\n";
  std::cout << "| Celsius <-> Kelvin |\n";
  std::cout << "+--------------------+\n\n";
  std::cout << "Enter temperature value and unit e.g. 32 c, 100 k\nTemp: ";
  std::cin >>v>>u;
  if (u=='c'){
    double k = ctok(v);
    std::cout << "Conv: " << k << " K\n";
  }
  else if(u=='k'){
    double c = ktoc(v);
    std::cout << "Conv: " << c << " ˚C\n";
  }
  else{
    error("Bad input");
  }
}
