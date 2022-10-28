// This program has 4 errors. Errors caught shown after program.

#include <iostream>
int Main() // this Main that should be main error is caught at link-time
{
  std::STRING s = "Goodbye, cruel world! ";
  std::cOut << S << '\n';
  return 0;
}

/*
3 compile time errors generated
===============================
compile_time_errors.cpp:6:8: error: no type named 'STRING' in namespace 'std'
  std::STRING s = "Goodbye, cruel world! ";
  ~~~~~^
compile_time_errors.cpp:7:8: error: no member named 'cOut' in namespace 'std'
  std::cOut << S << '\n';
  ~~~~~^
compile_time_errors.cpp:7:16: error: use of undeclared identifier 'S'
  std::cOut << S << '\n';
               ^

1 link-time error generated (Once the compile time errors have been resolved)
===========================
Undefined symbols for architecture arm64:
  "_main", referenced from:
     implicit entry/start for main executable
ld: symbol(s) not found for architecture arm64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
*/
