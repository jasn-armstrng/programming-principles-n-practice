#include <iostream> // needed to access std::string
#include <vector>

extern std::vector<std::string> data;
std::vector<std::string> reverse_by_value(const std::vector<std::string> v);
std::vector<std::string> reverse_by_reference(std::vector<std::string>& v);
void print(const std::vector<std::string> v);
