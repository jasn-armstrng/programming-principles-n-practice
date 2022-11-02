// This program does nothing except declare illegal variable names.
// This is to observe how the compiler reacts. See compiler errors
// below.

int main()
{
  int double = 6;
  char OMG! = '!';
  double 22_5 = 22.5;
  int $12_dollars = 12; // Not flagged as an error but this is bad practice.
}

/*
illegal_variable_names.cpp:6:7: error: cannot combine with previous 'int' declaration specifier
  int double = 6;
      ^
illegal_variable_names.cpp:6:14: error: expected unqualified-id
  int double = 6;
             ^
illegal_variable_names.cpp:7:11: error: expected ';' at end of declaration
  char OMG! = '!';
          ^
          ;
illegal_variable_names.cpp:8:10: error: expected unqualified-id
  double 22_5 = 22.5;
         ^
4 errors generated.
*/
