#include <vector>

extern std::vector<int> data;
std::vector<int> reverse_by_value(const std::vector<int> v);
std::vector<int> reverse_by_reference(std::vector<int>& v);
void print(const std::vector<int> v);
