#include <iostream>

inline void error(const std::string& s) { throw std::runtime_error(s); }
