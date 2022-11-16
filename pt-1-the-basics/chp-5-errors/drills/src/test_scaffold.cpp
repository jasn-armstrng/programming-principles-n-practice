// This program catches and outputs errors in C++ statements.
#include <iostream>

inline void keep_window_open();

int main()
try{
  // statement here
  keep_window_open();
  return 0; // indicates succes
}
catch (std::exception& e){
  std::cerr << "error: " << e.what() << '\n';
  keep_window_open();
  return 1;
}
catch (...){
  std::cerr << "Oops: unknown exception!\n" << '\n';
  keep_window_open();
  return 2;
}

inline void keep_window_open(){
  char ch; std::cin>>ch;
}
