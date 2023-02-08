/**
 * @file std_lib_facilities.h
 * @author Jason Armstrong
 * @brief Provides commonly used functions
 * @version 0.1
 * @date 2023-02-07
 */

#include <iostream>

inline void error(const std::string& s) { throw std::runtime_error(s); }
