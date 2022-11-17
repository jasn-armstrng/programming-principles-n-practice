// This program does conversions between Celsius and Fahrenheit
#include <iostream>

// function declaration(s)
inline void error(const std::string& s);
inline void keep_window_open();
double ctof(double c);
double ftoc(double f);
void ui();

int main()
try{
  std::cout << "+------------------------+\n";
  std::cout << "| Celsius <-> Fahrenheit |\n";
  std::cout << "+------------------------+\n\n";
  ui();
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

// function definition(s)
inline void error(const std::string& s){throw std::runtime_error(s);}

inline void keep_window_open(){char ch; std::cin>>ch;};

double ctof(double c){
  // converts celsius to fahrenheit
  // pre-conditions: c >= -273.15 (absolute zero)
  // post-conditions: returns value >= −459.67 F (absolute zero)
  if(c < -273.15){error("Value entered is below absolute zero (-273.15 C)");}
  return (c*9)/5+32;
}

double ftoc(double f){
  // converts fahrenheit to celsius
  // pre-conditions: f >= −459.67 F (absolute zero)
  // post-conditions: returns a celsius value > absolute 0 (-273.15)
  if(f < -459.67){error("Value entered is below absolute zero (-459.67 F)");}
  return (f-32)*5/9;
}

void ui(){
  // presents gui
  // pre-conditions: v is numberic(double), u is a character {c, f}
  // post-conditions: Returns the appropriate conversion or an error
  double v, f, c;
  char u;

  std::cout << "Enter temperature value and unit e.g. 32 c, 100 f\nTemp: ";
  std::cin >>v>>u;

  switch(u){
    case('c'):
      f = ctof(v);
      std::cout << "Conv: " << f << " F\n";
      break;
    case('f'):
      c = ftoc(v);
      std::cout << "Conv: " << c << " ˚C\n";
      break;
    default:
      error("Bad input");
      break;
  }
}
